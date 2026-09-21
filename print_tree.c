#include "rbt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLOT_WIDTH 2
#define MAX_PRINT_HEIGHT 10

static int tree_height(tree_t *root)
{
    int left_height;
    int right_height;

    if (root == NULL)
        return 0;

    left_height = tree_height(root->left);
    right_height = tree_height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}


static int power_of_two(int exponent)
{
    int value = 1;

    while (exponent-- > 0)
        value *= 2;

    return value;
}

static int node_position(int level, int index, int height)
{
    int first_position = power_of_two(height - level) * SLOT_WIDTH;
    int position_gap = power_of_two(height - level + 1) * SLOT_WIDTH;

    return first_position + index * position_gap;
}

static void print_label(tree_t *node, int position, int *last_position)
{
    char label[32];
    int label_length;
    int spaces;

    if (node == NULL)
        return;

    snprintf(label, sizeof(label), "%d%c", node->data, node->color == RED ? 'R' : 'B');
    label_length = (int)strlen(label);
    spaces = position - label_length / 2 - *last_position;

    if (spaces < 1)
        spaces = 1;

    printf("%*s", spaces, "");
    if (node->color == RED)
        printf("\033[31m%s\033[0m", label);
    else
        printf("\033[1;37m%s\033[0m", label);

    *last_position += spaces + label_length;
}

static void print_node_level(tree_t **nodes, int count, int level, int height)
{
    int index;
    int last_position = 0;

    for (index = 0; index < count; index++)
        print_label(nodes[index], node_position(level, index, height),
                    &last_position);

    printf("\n");
}

static void print_connector_level(tree_t **nodes, int count, int level, int height)
{
    int index;
    int left_position;
    int right_position;
    int parent_position;
    int line_width = power_of_two(height + 1) * SLOT_WIDTH + 4;
    char *line = malloc((size_t)line_width + 1);

    if (line == NULL)
        return;

    memset(line, ' ', (size_t)line_width);
    line[line_width] = '\0';

    for (index = 0; index < count; index++)
    {
        if (nodes[index] == NULL)
            continue;

        parent_position = node_position(level, index, height);
        left_position = node_position(level + 1, index * 2, height);
        right_position = node_position(level + 1, index * 2 + 1, height);

        if (nodes[index]->left != NULL)
            line[(parent_position + left_position) / 2] = '/';
        if (nodes[index]->right != NULL)
            line[(parent_position + right_position) / 2] = '\\';
    }

    while (line_width > 0 && line[line_width - 1] == ' ')
        line[--line_width] = '\0';

    printf("%s\n", line);
    free(line);
}

void print_tree(tree_t *root)
{
    tree_t **current;
    tree_t **next;
    int height;
    int count = 1;
    int level;
    int index;

    if (root == NULL)
        return;

    height = tree_height(root);
    if (height > MAX_PRINT_HEIGHT)
    {
        printf("Tree is too deep to display\n");
        return;
    }

    current = calloc(1, sizeof(*current));
    if (current == NULL)
        return;
    current[0] = root;

    printf("Red-Black Tree:\n\n");

    for (level = 0; level < height; level++)
    {
        print_node_level(current, count, level, height);

        if (level == height - 1)
            break;

        print_connector_level(current, count, level, height);
        next = calloc((size_t)count * 2, sizeof(*next));
        if (next == NULL)
        {
            free(current);
            return;
        }

        for (index = 0; index < count; index++)
        {
            next[index * 2] = current[index] == NULL ? NULL : current[index]->left;
            next[index * 2 + 1] = current[index] == NULL ? NULL :current[index]->right;
        }

        free(current);
        current = next;
        count *= 2;
    }

    free(current);
}
