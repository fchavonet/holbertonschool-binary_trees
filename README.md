<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Binary Trees

## Table of contents

<details>
    <summary>
        CLICK TO ENLARGE 😇
    </summary>
    <a href="#description">Description</a>
    <br>
    <a href="#objectives">Objectives</a>
    <br>
    <a href="#requirements">Requirements</a>
    <br>
    <a href="#instructions">Instructions</a>
    <br>
    <a href="#tech-stack">Tech stack</a>
    <br>
    <a href="#files-description">Files description</a>
    <br>
    <a href="#installation_and_how_to_use">Installation and how to use</a>
    <br>
    <a href="#thanks">Thanks</a>
    <br>
    <a href="#authors">Authors</a>
</details>

## <span id="description">Description</span>

This project explores the implementation of binary trees in C.

It introduces the core concepts of tree structures, including creation, traversal, and manipulation of nodes.

The project also covers more advanced types such as Binary Search Trees (BST), AVL Trees, and Heaps, with a focus on efficiency and memory management.

## <span id="objectives">Objectives</span>

At the end of this project, I should be able to explain to anyone, **without the help of Google**:

- What is a binary tree?
- What is the difference between a binary tree and a Binary Search Tree?
- What is the possible gain in terms of time complexity compared to linked lists?
- What are the depth, the height, the size of a binary tree?
- What are the different traversal methods to go through a binary tree?
- What is a complete, a full, a perfect, a balanced binary tree?

## <span id="requirements">Requirements</span>

- My programs and functions will be compiled with `gcc` using the flags `-Wall`, `-Werror`, `-Wextra`, `-pedantic` and `-std=gnu89`.
- All my files should end with a new line.
- My code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- I am not allowed to use global variables.
- No more than 5 functions per file.
- The prototypes of all my functions should be included in my header file called `binary_trees.h`.
- All my header files should be include guarded.

## <span id="instructions">Instructions</span>

### Mandatory

<details>
    <summary>
        <b>0. New node</b>
    </summary>
    <br>

Write a function that creates a binary tree node:

- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`.
- Where `parent` is a pointer to the parent node of the node to create.
- And `value` is the value to put in the new node.
- When created, a node does not have any child.
- Your function must return a pointer to the new node, or `NULL` on failure.

```bash
alex@/tmp/binary_trees$ cat 0-main.c 
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `0-binary_tree_node.c`.
<hr>
</details>

<details>
    <summary>
        <b>1. Insert left</b>
    </summary>
    <br>

Write a function that inserts a node as the left-child of another node:

- Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`.
- Where `parent` is a pointer to the node to insert the left-child in
- And `value` is the value to store in the new node.
- Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`.
- If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.

```bash
alex@/tmp/binary_trees$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_left(root->right, 128);
    binary_tree_insert_left(root, 54);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
alex@/tmp/binary_trees$ ./1-left
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)                                            
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `1-binary_tree_insert_left.c`.
<hr>
</details>

<details>
    <summary>
        <b>2. Insert right</b>
    </summary>
    <br>

Write a function that inserts a node as the right-child of another node:

- Prototype: `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`.
- Where `parent` is a pointer to the node to insert the right-child in.
- And `value` is the value to store in the new node.
- Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`.
- If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.

```bash
alex@/tmp/binary_trees$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_left(root->right, 128);
    binary_tree_insert_left(root, 54);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
alex@/tmp/binary_trees$ ./1-left
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)                                            
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `2-binary_tree_insert_right.c`.
<hr>
</details>

<details>
    <summary>
        <b>3. Delete</b>
    </summary>
    <br>

Write a function that deletes an entire binary tree:

- Prototype: `void binary_tree_delete(binary_tree_t *tree);`.
- Where `tree` is a pointer to the root node of the tree to delete.
- If `tree` is `NULL`, do nothing.

```bash
alex@/tmp/binary_trees$ cat 3-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
alex@/tmp/binary_trees$ valgrind ./3-del
==13264== Memcheck, a memory error detector
==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==13264== Command: ./3-del
==13264== 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
==13264== 
==13264== HEAP SUMMARY:
==13264==     in use at exit: 0 bytes in 0 blocks
==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
==13264== 
==13264== All heap blocks were freed -- no leaks are possible
==13264== 
==13264== For counts of detected and suppressed errors, rerun with: -v
==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `3-binary_tree_delete.c`.
<hr>
</details>

<details>
    <summary>
        <b>4. Is leaf</b>
    </summary>
    <br>

Write a function that checks if a node is a leaf:

- Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`.
- Where `node` is a pointer to the node to check
- Your function must return `1` if `node` is a leaf, otherwise `0`.
- If `node` is `NULL`, return `0`.

```bash
alex@/tmp/binary_trees$ cat 4-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_leaf(root);
    printf("Is %d a leaf: %d\n", root->n, ret);
    ret = binary_tree_is_leaf(root->right);
    printf("Is %d a leaf: %d\n", root->right->n, ret);
    ret = binary_tree_is_leaf(root->right->right);
    printf("Is %d a leaf: %d\n", root->right->right->n, ret);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf
alex@/tmp/binary_trees$ ./4-leaf 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a leaf: 0
Is 128 a leaf: 0
Is 402 a leaf: 1
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `4-binary_tree_is_leaf.c`.
<hr>
</details>

<details>
    <summary>
        <b>5. Is root</b>
    </summary>
    <br>

Write a function that checks if a given node is a root:

- Prototype: `int binary_tree_is_root(const binary_tree_t *node);`.
- Where `node` is a pointer to the node to check.
- Your function must return `1` if `node` is a root, otherwise `0`.
- If `node` is `NULL`, return `0`.

```bash
alex@/tmp/binary_trees$ cat 5-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_root(root);
    printf("Is %d a root: %d\n", root->n, ret);
    ret = binary_tree_is_root(root->right);
    printf("Is %d a root: %d\n", root->right->n, ret);
    ret = binary_tree_is_root(root->right->right);
    printf("Is %d a root: %d\n", root->right->right->n, ret);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root
alex@/tmp/binary_trees$ ./5-root 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a root: 1
Is 128 a root: 0
Is 402 a root: 0
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `5-binary_tree_is_root.c`.
<hr>
</details>

<details>
    <summary>
        <b>6. Pre-order traversal</b>
    </summary>
    <br>

Write a function that goes through a binary tree using pre-order traversal:

- Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`.
- Where `tree` is a pointer to the root node of the tree to traverse.
- And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
- If `tree` or `func` is `NULL`, do nothing.

```bash
alex@/tmp/binary_trees$ cat 6-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    binary_tree_preorder(root, &print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre
alex@/tmp/binary_trees$ ./6-pre
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
98
12
6
56
402
256
512
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `6-binary_tree_preorder.c`.
<hr>
</details>

<details>
    <summary>
        <b>7. In-order traversal</b>
    </summary>
    <br>

Write a function that goes through a binary tree using in-order traversal:

- Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`.
- Where `tree` is a pointer to the root node of the tree to traverse.
- And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
- If `tree` or `func` is `NULL`, do nothing.

```bash
alex@/tmp/binary_trees$ cat 7-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    binary_tree_inorder(root, &print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in
alex@/tmp/binary_trees$ ./7-in
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
12
56
98
256
402
512
alex@/tmp/binary_trees$
Repo:
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `7-binary_tree_inorder.c`.
<hr>
</details>

<details>
    <summary>
        <b>8. Post-order traversal</b>
    </summary>
    <br>

Write a function that goes through a binary tree using post-order traversal:

- Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`.
- Where `tree` is a pointer to the root node of the tree to traverse.
- And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
- If `tree` or `func` is `NULL`, do nothing.

```bash
alex@/tmp/binary_trees$ cat 8-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    binary_tree_postorder(root, &print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post
alex@/tmp/binary_trees$ ./8-post
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
56
12
256
512
402
98
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `8-binary_tree_postorder.c`.
<hr>
</details>

<details>
    <summary>
        <b>9. Height</b>
    </summary>
    <br>

Write a function that measures the height of a binary tree:

- Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`.
- Where `tree` is a pointer to the root node of the tree to measure the height.
- If `tree` is `NULL`, your function must return `0`.

```bash
alex@/tmp/binary_trees$ cat 9-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_height(root->right);
    printf("Height from %d: %lu\n", root->right->n, height);
    height = binary_tree_height(root->left->right);
    printf("Height from %d: %lu\n", root->left->right->n, height);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height
alex@/tmp/binary_trees$ ./9-height 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Height from 98: 2
Height from 128: 1
Height from 54: 0
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `9-binary_tree_height.c`.
<hr>
</details>

<details>
    <summary>
        <b>10. Depth</b>
    </summary>
    <br>

Write a function that measures the depth of a node in a binary tree:

- Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`.
- Where `tree` is a pointer to the node to measure the depth.
- If `tree` is `NULL`, your function must return `0`.

```bash
alex@/tmp/binary_trees$ cat 10-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t depth;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root->n, depth);
    depth = binary_tree_depth(root->right);
    printf("Depth of %d: %lu\n", root->right->n, depth);
    depth = binary_tree_depth(root->left->right);
    printf("Depth of %d: %lu\n", root->left->right->n, depth);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth
alex@/tmp/binary_trees$ ./10-depth 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Depth of 98: 0
Depth of 128: 1
Depth of 54: 2
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `10-binary_tree_depth.c`.
<hr>
</details>

<details>
    <summary>
        <b>11. Size</b>
    </summary>
    <br>

Write a function that measures the size of a binary tree:

- Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`.
- Where `tree` is a pointer to the root node of the tree to measure the size.
- If `tree` is `NULL`, the function must return `0`.

```bash
alex@/tmp/binary_trees$ cat 11-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t size;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    size = binary_tree_size(root);
    printf("Size of %d: %lu\n", root->n, size);
    size = binary_tree_size(root->right);
    printf("Size of %d: %lu\n", root->right->n, size);
    size = binary_tree_size(root->left->right);
    printf("Size of %d: %lu\n", root->left->right->n, size);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size
alex@/tmp/binary_trees$ ./11-size 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Size of 98: 5
Size of 128: 2
Size of 54: 1
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `11-binary_tree_size.c`.
<hr>
</details>

<details>
    <summary>
        <b>12. Leaves</b>
    </summary>
    <br>

Write a function that counts the leaves in a binary tree:

- Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`.
- Where `tree` is a pointer to the root node of the tree to count the number of leaves.
- If `tree` is `NULL`, the function must return `0`.
- A `NULL` pointer is not a leaf.

```bash
alex@/tmp/binary_trees$ cat 12-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t leaves;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves in %d: %lu\n", root->n, leaves);
    leaves = binary_tree_leaves(root->right);
    printf("Leaves in %d: %lu\n", root->right->n, leaves);
    leaves = binary_tree_leaves(root->left->right);
    printf("Leaves in %d: %lu\n", root->left->right->n, leaves);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves
alex@/tmp/binary_trees$ ./12-leaves 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Leaves in 98: 2
Leaves in 128: 1
Leaves in 54: 1
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `12-binary_tree_leaves.c`.
<hr>
</details>

<details>
    <summary>
        <b>13. Nodes</b>
    </summary>
    <br>

Write a function that counts the nodes with at least 1 child in a binary tree:

- Prototype: `size_t binary_tree_nodes(const binary_tree_t *tree);`.
- Where `tree` is a pointer to the root node of the tree to count the number of nodes.
- If `tree` is `NULL`, the function must return `0`.
- A `NULL` pointer is not a node.

```bash
alex@/tmp/binary_trees$ cat 13-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t nodes;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    nodes = binary_tree_nodes(root);
    printf("Nodes in %d: %lu\n", root->n, nodes);
    nodes = binary_tree_nodes(root->right);
    printf("Nodes in %d: %lu\n", root->right->n, nodes);
    nodes = binary_tree_nodes(root->left->right);
    printf("Nodes in %d: %lu\n", root->left->right->n, nodes);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 13-binary_tree_nodes.c 13-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes
alex@/tmp/binary_trees$ ./13-nodes
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Nodes in 98: 3
Nodes in 128: 1
Nodes in 54: 0
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `13-binary_tree_nodes.c`.
<hr>
</details>

<details>
    <summary>
        <b>14. Balance factor</b>
    </summary>
    <br>

Write a function that measures the balance factor of a binary tree:

- Prototype: `int binary_tree_balance(const binary_tree_t *tree);`.
- Where `tree` is a pointer to the root node of the tree to measure the balance factor.
- If `tree` is `NULL`, return `0`.

```bash
alex@/tmp/binary_trees$ cat 14-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int balance;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root->left, 50);
    binary_tree_insert_left(root->left->left, 10);
    binary_tree_insert_left(root->left->left->left, 8);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance of %d: %+d\n", root->n, balance);
    balance = binary_tree_balance(root->right);
    printf("Balance of %d: %+d\n", root->right->n, balance);
    balance = binary_tree_balance(root->left->left->right);
    printf("Balance of %d: %+d\n", root->left->left->right->n, balance);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 14-binary_tree_balance.c 14-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c -o 14-balance
alex@/tmp/binary_trees$ ./14-balance
                      .-------(098)--.
            .-------(045)--.       (128)--.
       .--(012)--.       (050)          (402)
  .--(010)     (054)
(008)
Balance of 98: +2
Balance of 128: -1
Balance of 54: +0
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `14-binary_tree_balance.c`.
<hr>
</details>

<details>
    <summary>
        <b>15. Is full</b>
    </summary>
    <br>

Write a function that checks if a binary tree is full:

- Prototype: `int binary_tree_is_full(const binary_tree_t *tree);`.
- Where `tree` is a pointer to the root node of the tree to check.
- If `tree` is `NULL`, your function must return `0`.

```bash
alex@/tmp/binary_trees$ cat 15-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int full;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    root->left->left = binary_tree_node(root->left, 10);
    binary_tree_print(root);

    full = binary_tree_is_full(root);
    printf("Is %d full: %d\n", root->n, full);
    full = binary_tree_is_full(root->left);
    printf("Is %d full: %d\n", root->left->n, full);
    full = binary_tree_is_full(root->right);
    printf("Is %d full: %d\n", root->right->n, full);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 15-binary_tree_is_full.c 15-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 15-full
alex@/tmp/binary_trees$ ./15-full
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 full: 0
Is 12 full: 1
Is 128 full: 0
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `15-binary_tree_is_full.c`.
<hr>
</details>

<details>
    <summary>
        <b>16. Is perfect</b>
    </summary>
    <br>

Write a function that checks if a binary tree is perfect

Prototype: `int binary_tree_is_perfect(const binary_tree_t *tree);`.
Where `tree` is a pointer to the root node of the tree to check.
If `tree` is `NULL`, your function must return `0`.

```bash
alex@/tmp/binary_trees$ cat 16-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int perfect;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    root->left->left = binary_tree_node(root->left, 10);
    root->right->left = binary_tree_node(root->right, 10);

    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n\n", perfect);

    root->right->right->left = binary_tree_node(root->right->right, 10);
    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n\n", perfect);

    root->right->right->right = binary_tree_node(root->right->right, 10);
    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n", perfect);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 16-binary_tree_is_perfect.c 16-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 16-perfect
alex@/tmp/binary_trees$ ./16-perfect 
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (010)     (402)
Perfect: 1

       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (010)       .--(402)
                              (010)
Perfect: 0

       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (010)       .--(402)--.
                              (010)     (010)
Perfect: 0
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `16-binary_tree_is_perfect.c`.
<hr>
</details>

<details>
    <summary>
        <b>17. Sibling</b>
    </summary>
    <br>

Write a function that finds the sibling of a node:

- Prototype: `binary_tree_t *binary_tree_sibling(binary_tree_t *node);`.
- Where `node` is a pointer to the node to find the sibling.
- Your function must return a pointer to the sibling node.
- If `node` is `NULL` or the parent is `NULL`, return `NULL`.
- If `node` has no sibling, return `NULL`.

```bash
alex@/tmp/binary_trees$ cat 17-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *sibling;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 402);
    root->left->left = binary_tree_node(root->left, 10);
    root->right->left = binary_tree_node(root->right, 110);
    root->right->right->left = binary_tree_node(root->right->right, 200);
    root->right->right->right = binary_tree_node(root->right->right, 512);

    binary_tree_print(root);
    sibling = binary_tree_sibling(root->left);
    printf("Sibling of %d: %d\n", root->left->n, sibling->n);
    sibling = binary_tree_sibling(root->right->left);
    printf("Sibling of %d: %d\n", root->right->left->n, sibling->n);
    sibling = binary_tree_sibling(root->left->right);
    printf("Sibling of %d: %d\n", root->left->right->n, sibling->n);
    sibling = binary_tree_sibling(root);
    printf("Sibling of %d: %p\n", root->n, (void *)sibling);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 17-main.c 17-binary_tree_sibling.c 0-binary_tree_node.c -o 17-sibling
alex@/tmp/binary_trees$ ./17-sibling
       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (110)       .--(402)--.
                              (200)     (512)
Sibling of 12: 128
Sibling of 110: 402
Sibling of 54: 10
Sibling of 98: (nil)
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `17-binary_tree_sibling.c`.
<hr>
</details>

<details>
    <summary>
        <b>18. Uncle</b>
    </summary>
    <br>

Write a function that finds the uncle of a node:

- Prototype: `binary_tree_t *binary_tree_uncle(binary_tree_t *node);`.
- Where `node` is a pointer to the node to find the uncle.
- Your function must return a pointer to the uncle node.
- If `node` is `NULL`, return `NULL`.
- If `node` has no uncle, return `NULL`.

```bash
alex@/tmp/binary_trees$ cat 18-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *uncle;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 402);
    root->left->left = binary_tree_node(root->left, 10);
    root->right->left = binary_tree_node(root->right, 110);
    root->right->right->left = binary_tree_node(root->right->right, 200);
    root->right->right->right = binary_tree_node(root->right->right, 512);

    binary_tree_print(root);
    uncle = binary_tree_uncle(root->right->left);
    printf("Uncle of %d: %d\n", root->right->left->n, uncle->n);
    uncle = binary_tree_uncle(root->left->right);
    printf("Uncle of %d: %d\n", root->left->right->n, uncle->n);
    uncle = binary_tree_uncle(root->left);
    printf("Uncle of %d: %p\n", root->left->n, (void *)uncle);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 binary_tree_print.c 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle
alex@/tmp/binary_trees$ ./18-uncle
       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (110)       .--(402)--.
                              (200)     (512)
Uncle of 110: 12
Uncle of 54: 128
Uncle of 12: (nil)
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-binary_trees`.
- File: `18-binary_tree_uncle.c`.
<hr>
</details>

## <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/C-a8b9cc?logo=&logoColor=black&style=for-the-badge" alt="C badge">
    <img src="https://img.shields.io/badge/GIT-f05032?logo=git&logoColor=white&style=for-the-badge" alt="Git badge">
    <img src="https://img.shields.io/badge/GITHUB-181717?logo=github&logoColor=white&style=for-the-badge" alt="GitHub badge">
    <img src="https://img.shields.io/badge/MARKDOWN-000000?logo=markdown&logoColor=white&style=for-the-badge" alt="Markdown badge">
    <img src="https://img.shields.io/badge/VIM-019733?logo=vim&logoColor=white&style=for-the-badge" alt="VIM badge">
</p>

## <span id="files-description">Files description</span>

| **FILES**                      | **DESCRIPTION**                                                   |
| :----------------------------: | ----------------------------------------------------------------- |
| `binary_trees.h`               | Project header: structs, typedefs, prototypes, include guards.    |
| `binary_tree_print.c`          | Helper to pretty-print trees (visualization only, not graded).    |
| `0-binary_tree_node.c`         | Create a new node (no children at creation).                      |
| `1-binary_tree_insert_left.c`  | Insert a node as left child (relinks former left child if any).   |
| `2-binary_tree_insert_right.c` | Insert a node as right child (relinks former right child if any). |
| `3-binary_tree_delete.c`       | Delete an entire tree (post-order free).                          |
| `4-binary_tree_is_leaf.c`      | Return `1` if node is a leaf, else `0`.                           |
| `5-binary_tree_is_root.c`      | Return `1` if node is a root, else `0`.                           | 
| `6-binary_tree_preorder.c`     | Pre-order traversal: `node → left → right`, calls `func(n)`.      |
| `7-binary_tree_inorder.c`      | In-order traversal: `left → node → right`, calls `func(n)`.       |
| `8-binary_tree_postorder.c`    | Post-order traversal: `left → right → node`, calls `func(n)`.     |
| `9-binary_tree_height.c`       | Compute height of a tree.                                         |
| `10-binary_tree_depth.c`       | Compute depth of a given node.                                    |
| `11-binary_tree_size.c`        | Return total number of nodes (tree size).                         |
| `12-binary_tree_leaves.c`      | Count leaf nodes.                                                 |
| `13-binary_tree_nodes.c`       | Count nodes with at least one child.                              |
| `14-binary_tree_balance.c`     | Balance factor = `height(left) − height(right)`.                  |
| `15-binary_tree_is_full.c`     | Check if the tree is full (each node has 0 or 2 children).        |
| `16-binary_tree_is_perfect.c`  | Check if the tree is perfect (full + all leaves at same level).   |
| `17-binary_tree_sibling.c`     | Get the sibling of a node (or `NULL`).                            |
| `18-binary_tree_uncle.c`       | Get the uncle of a node (or `NULL`).                              |
| `README.md`                    | The README file you are currently reading 😉.                    |

## <span id="installation_and_how_to_use">Installation and how to use</span>

### Installation:

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```bash
git clone https://github.com/fchavonet/holbertonschool-binary_trees.git
```

2. Open the repository you've just cloned.

3. Compile the source code:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
```
> Replace the file names in the compilation command with those of the respective tasks. For more details, refer to the <a href="#instructions">Instructions</a> section of this README.

### How to use:

1. Run any task with its corresponding `main.c` (local):

```bash
./0-node
```

## <span id="thanks">Thanks</span>

- A big thank you to all my Holberton School peers for their help and support throughout this project.

## <span id="authors">Authors</span>

**Fabien CHAVONET**
- GitHub: [@fchavonet](https://github.com/fchavonet)
