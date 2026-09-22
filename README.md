# Red-Black Tree Implementation in C

A **Red-Black Tree (RBT)** implementation in C that demonstrates how a self-balancing Binary Search Tree maintains its balance using **node colors, recoloring, and rotations**.

This project was developed as part of my **Data Structures and Algorithms practice** to understand the internal working of self-balancing trees and implement their operations from scratch.

## What is a Red-Black Tree?

A Red-Black Tree is a **self-balancing Binary Search Tree** in which every node has an additional color — **RED** or **BLACK**.

The tree follows a set of rules that prevent it from becoming highly skewed:

* Every node is either RED or BLACK.
* The root node is always BLACK.
* A RED node cannot have a RED child.
* The number of BLACK nodes along valid paths is maintained.
* Rotations and recoloring are used to restore the Red-Black Tree properties after modifications.

Because of these properties, the height of the tree remains **O(log n)**, providing efficient searching and updating operations.

---

## Features

This implementation supports:

1.Insert, Search, Delete an element

2.Find minimum and maximum value

3.Delete minimum and maximum element

4.Print the tree with node colors

5.Left and Right rotation

6.Duplicate element detection

7.Dynamic memory allocation

8.Modular C implementation

9.Makefile-based compilation

The main program provides a menu-driven interface for performing these operations.

---

## Time Complexity

| Operation    | Red-Black Tree |
| ------------ | -------------: |
| Search       |       O(log n) |
| Insertion    |       O(log n) |
| Deletion     |       O(log n) |
| Find Minimum |       O(log n) |
| Find Maximum |       O(log n) |
| Rotation     |           O(1) |

The main advantage over a normal, unbalanced BST is that a BST can become skewed and degrade to **O(n)** in the worst case, while a Red-Black Tree maintains logarithmic height.

---

## BST vs Red-Black Tree

Consider inserting sorted values:

```text
10
20
30
40
50
```

A normal BST can become:

```text
10
  \
   20
     \
      30
        \
         40
           \
            50
```

This behaves almost like a linked list.

A Red-Black Tree uses rotations and recoloring to keep the structure balanced:

```text
        20
       /  \
     10    40
          /  \
        30    50
```

This allows operations to remain efficient even as more elements are inserted.

---

## 🖥️ Menu-Driven Interface

The program provides the following operations:

```text
================ MENU ================

1. Insert element into BST
2. Search for an element
3. Delete specific element
4. Print tree
5. Find minimum value
6. Find maximum value
7. Delete minimum element
8. Delete maximum element
9. Exit

======================================
```

The tree can also be printed with the color of every node:

```text
root-->(10)(B)-->(7)(B)-->(3)(R)-->(8)(R)-->(18)(B)-->NULL
```
---

## Project Structure

```text
DSA_3_Red_Black_Tree/
│
├── main.c
├── header.h
│
├── insert.c
├── search.c
├── delete.c
│
├── find_min.c
├── find_max.c
├── delete_min.c
├── delete_max.c
│
├── rotate_helpers.c
├── print_tree.c
│
├── makefile
│
└── README.md
```

The project is divided into separate source files so that each tree operation can be developed and understood independently.

---

## Technologies Used

* **Language:** C
* **Data Structure:** Red-Black Tree
* **Compiler:** GCC
* **Build Tool:** Make
* **Concepts:**

  * Binary Search Trees
  * Self-Balancing Trees
  * Dynamic Memory Allocation
  * Pointers
  * Structures
  * Recursion
  * Tree Rotations
  * Recoloring
  * Modular Programming

Enter the project directory:
