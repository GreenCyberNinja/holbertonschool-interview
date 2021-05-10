#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node of the heap
 * @value: value store in the node to be inserted
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	parent = find_parent(*root);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	if (parent == NULL)
		*root = new;
	else if (!(parent->left))
		parent->left = new;
	else
		parent->right = new;
	swap_nodes(&new);
	return (new);
}

/**
 * find_parent - finds the parent to insert a new child
 * @root: double pointer to the root node of the heap
 * Return: a pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *p;
	int left, right;
	bool left_full, right_full;

	if (root == NULL)
		return (NULL);

	p = root;
	left = count_nodes(p->left);
	right = count_nodes(p->right);
	left_full = is_full(p->left);
	right_full = is_full(p->right);

	if (!left || !right)
		return (p);
	if (!left_full || (left_full && right_full && left == right))
		return (find_parent(p->left));
	else if (!right_full || (left_full && right_full && left > right))
		return (find_parent(p->right));
	return (p);
}

/**
 * is_full - checks if the subtree is full
 * @node: node from which to start
 * Return: 1 if true or 0 if false
 */

bool is_full(const heap_t *node)
{
	int p1, p2;

	if (node == NULL)
		return (0);
	p1 = count_nodes(node->left);
	p2 = count_nodes(node->right);
	if (p1 == p2)
		return (true);
	else
		return (false);
}

/**
 * count_nodes - count nodes in subtree
 * @node: node to count from
 * Return: number of nodes
 */
int count_nodes(heap_t *node)
{
	int n;

	if (node == NULL)
		return (0);
	n = 1;
	n += count_nodes(node->left);
	n += count_nodes(node->right);

	return (n);
}

/**
 * swap_nodes - swaps between two nodes
 * @new: inserted node
 * Return: nothing
 */
void swap_nodes(heap_t **new)
{
	heap_t *cur;
	int temp;

	cur = *new;
	while (cur->parent)
	{
		if (cur->parent->n < cur->n)
		{
			temp = cur->parent->n;
			cur->parent->n = cur->n;
			cur->n = temp;
			*new = cur->parent;
		}
		cur = cur->parent;
	}
}
