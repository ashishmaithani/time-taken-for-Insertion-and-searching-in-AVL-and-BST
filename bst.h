#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"
#include "stack.h"
#include "queue.h"



struct leaf* createLeaf(struct data *d);
struct tree* createTree();
// Inserts the leaves in BST
void insertBst(struct tree *t,struct data *d);
void insertBst_r(struct leaf* current,struct leaf* newLeaf);
// Prints the leaves in Inorder way
void inOrderBst(struct tree *t);
void inOrderBst_r(struct leaf *current);
// Prints the leaves in Preorder way
void preOrderBst(struct tree *t);
void preOrderBst_r(struct leaf *lf);
// Prints the leaves in Postorder way
void postOrderBst(struct tree *t);
void postOrderBst_r(struct leaf *lf);
// Returns the pointer to Struct data of Maximum Value 
struct data* getMaxData(struct tree *tr);
struct data* getMaxData_r(struct leaf* lf);
// Retruns the pointer to the Struc data of Minimum Value
struct data* getMimData(struct tree *tr);
struct data* getMimData_r(struct leaf* lf);
// Returns 1 if the BST is complete
int isCompleteBst(struct tree *tr);
int isCompleteBst_r(struct leaf* lf);
// Returns the Height of the BST
int getBstHeight(struct tree *tr);
int getBstHeight_r(struct leaf* lf);
// Prints all the Leaves for which the sum is between begin and end
void printInRange(struct tree *tr, float begin, float end);
void printInRange_r(struct leaf* lf, float begin,float end);
// Returns 1 if the BST is full
int isFullBst(struct tree *tr);
int isFullBst_r(struct leaf *lf);
// Reverse the BST
void reverseBST(struct tree *t);
void reverseBST_r(struct leaf *lf);
// Returns the sum of all the leaves of the BST
float sumLeaves(struct tree *t);
float sumLeaves_r(struct leaf *lf);
// Prints the BST in the order of BFS
void printBreadthFirstSearch(struct tree *t);
// Prints the BST in the DFS order
void printDepthFirstSearch(struct tree *t);
// Returs the sum of all the leaves of BST
float totalSum(struct tree *t);
float totalSum_r(struct leaf* current);
// Returs 1 if the tree is BST
int isBst(struct tree *t);
int isBst_r(struct leaf* current);
void printBreadthFirstSearch(struct tree *t);
// frees all the memory allocated to the tree
void cleanBST(struct tree *t);
void cleanBST_r(struct leaf *lf);
// Returns 1 if found else 0
int searchBst(struct tree *t, struct data *d);
int searchBst_r(struct leaf *curr,struct data *d);
#endif
