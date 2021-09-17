#include "binary_trees.h"

/**
 * heap_extract - extracts root node from max binary heap
 * @root: double pointer to root of max binary heap
 * Return: value of root or 0 on fail
 */

int heap_extract(heap_t **root)
{
   int val, hght;
   heap_t *top;

   if (root == NULL || (*root) == NULL)
       return (0);

   top = *root;
   val = top->n;

   if (top->left == NULL && top->right)
       *root = NULL;
   else
   {
       hght = Gethght(*root, 1);
       top = GetTop(*root, hght, 1);
       (*root)->n = top->n;
       if (top->parent->right == top)
           top->parent->right = NULL;
       else
           top->parent->left = NULL;
       Reheap(*root);
   }
   free(top);

   return (val);
}
/**
 * Reheap - re heaps the heap after root is moved
 * @node: starting place to reheap
 */

void Reheap(heap_t *node)
{
	int tmp;
	heap_t *max = node;

	if (node->left != NULL && node->left->n > max->n)
		max = node->left;

	if (node->right != NULL && node->right->n > max->n)
		max = node->right;

	if (max != node)
	{
		tmp = node->n;
		node->n = max->n;
		max->n = tmp;
		Reheap(max);
	}
}

/**
 * Gethght - gets the height of the heap
 * @node: start of the heap
 * @hght: height of start
 * Return: heap height
 */
int Gethght(heap_t *node, int hght)
{
    	int left, right;

	if (node == NULL)
		return (hght - 1);

	hght++;
	left = Gethght(node->left, hght);
	right = Gethght(node->right, hght);
	if (left > right)
		return (left);

	return (right);
}
/**
 * GetTop - gets the new top of the heap
 * @node: starting node
 * @hght: height of the heap
 * @NodeHght: height of the node
 * Return: the new top
 */
heap_t *GetTop(heap_t *node, int hght, int NodeHght)
{
    	heap_t *tmp;

	if (NodeHght >= hght - 1)
	{
		if (node->right != NULL)
		{
			return (node->right);
		}
		return (node->left);
	}
	tmp = GetTop(node->right, hght, NodeHght + 1);
	if (tmp != NULL)
		return (tmp);

	return (GetTop(node->left, hght, NodeHght + 1));
}
