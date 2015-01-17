#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"

struct avlLeaf* createAvlLeaf(struct data *d);
struct avlTree* createAvlTree();
// Inserts into AVL tree
void insertAvl(struct avlTree *t,struct data *d);
void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf);
// Prints the elements in Inorder
void inOrderAvl(struct avlTree *t);
void inOrderAvl_r(struct avlLeaf *current);
// Rotate Right if balance factor is -2
void rotateRight(struct avlTree *t,struct avlLeaf *current);
// Rotate Left if balance factor is 2
void rotateLeft(struct avlTree *t,struct avlLeaf *current);
// Returns the max of left and right child
int maxHeight(int a,int b);
// Returns the height of a Leaf
int getHeight(struct avlLeaf *lf);
// Returns the balance factor of a Leaf
int getBalanceFact(struct avlLeaf *lf);
// Frees up the memory occupied by Tree
void cleanAvl(struct avlTree *t);
void cleanAvl_r(struct avlLeaf *lf);
// Searches an element in AVL Tree
int searchAvl(struct avlTree *t,struct data *d);
int searchAvl_r(struct avlLeaf *curr,struct data *d);
#endif
