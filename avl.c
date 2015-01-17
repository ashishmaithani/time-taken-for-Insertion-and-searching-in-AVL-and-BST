#include "avl.h"

struct avlLeaf* createAvlLeaf(struct data *d)
{
  struct avlLeaf* maple = malloc(sizeof(struct avlLeaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->parent = NULL;
  maple->dta = d;
  maple->height = 1;
  return maple;
}

struct avlTree* createAvlTree(){
	struct avlTree* oak = malloc(sizeof(struct avlTree));
	oak->root = NULL;
	return oak;
}

int getHeight(struct avlLeaf *lf){
	int leftheight=0,rightheight=0;
	if(lf == NULL){
		return 0;
	}
	if(lf->left != NULL){
		leftheight = lf->left->height;
	}
	if(lf->right != NULL){
		rightheight = lf->right->height;
	}
	lf->height = 1 + maxHeight(leftheight,rightheight);
	return (lf->height);
}

int maxHeight(int a,int b){
	if(a >= b){
		return a;
	}else{
		return b;
	}
}

int getBalanceFact(struct avlLeaf *lf){
	int leftheight,rightheight;
	if(lf != NULL){
		leftheight = getHeight(lf->left);
		rightheight = getHeight(lf->right);
		return (rightheight - leftheight);
	}
	return 0;
}

void rotateLeft(struct avlTree *t,struct avlLeaf *current){
	struct avlLeaf * temp = current->right;
	if(t->root == current){
		t->root = temp;
	}else{
		if(current->parent->right == current){
			current->parent->right = temp;
		}else{
			current->parent->left = temp;
		}
	}
	current->right = temp->left;
	if(current->right != NULL){
		current->right->parent = current;
	}
	temp->parent = current->parent;
	current->parent = temp;
	temp->left = current;
	current->height = getHeight(current);
	temp->height = getHeight(temp);
}

void rotateRight(struct avlTree *t,struct avlLeaf *current){
	struct avlLeaf * temp = current->left;
	if(t->root == current){
		t->root = temp;
	}else{
		if(current->parent->right == current){
			current->parent->right = temp;
		}else{
			current->parent->left = temp;
		}
	}
	current->left = temp->right;
	if(current->left != NULL){
		current->left->parent = current;
	}
	temp->parent = current->parent;
	current->parent = temp;
	temp->right = current;
	current->height = getHeight(current);
	temp->height = getHeight(temp);
}

void insertAvl(struct avlTree *t,struct data *d){
	struct avlLeaf * nLf = createAvlLeaf(d);
	if(t->root == NULL){
		t->root = nLf;
		return;
	}
	insertAvl_r(t,t->root,nLf);
}

void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf){
	int balfac;
	if(sumData(newLeaf->dta) > sumData(current->dta)){
		if(current->right == NULL){
			current->right = newLeaf;
			newLeaf->parent = current;
		}else{
			insertAvl_r(t,current->right,newLeaf);
		}
	}else{
		if(current->left == NULL){
			current->left = newLeaf;
			newLeaf->parent = current;
		}else{
			insertAvl_r(t,current->left,newLeaf);
		}
	}
	current->height = getHeight(current);
	balfac = getBalanceFact(current);
	if(balfac == 2){
		if(getBalanceFact(current->right) == -1){
			rotateRight(t,current->right);
			rotateLeft(t,current);
		}else if(getBalanceFact(current->right) == 1){
			rotateLeft(t,current);
		}
	}
	else if(balfac == -2){
		if(getBalanceFact(current->left) == 1){
			rotateLeft(t,current->left);
			rotateRight(t,current);
		}else if(getBalanceFact(current->left) == -1){
			rotateRight(t,current);
		}
	}
}

void inOrderAvl(struct avlTree *t){
	if(t->root != NULL){
		inOrderAvl_r(t->root);
	}
}

void inOrderAvl_r(struct avlLeaf *current){
	if(current == NULL){
		return;
	}
	inOrderAvl_r(current->left);
	printData(current->dta);
	printf("%d \n",current->height);
	inOrderAvl_r(current->right);
}

void cleanAvl(struct avlTree *t){
	if(t->root != NULL){
		cleanAvl_r(t->root);	
	}
	free(t);
}
void cleanAvl_r(struct avlLeaf *lf){
	if(lf == NULL){
		return;
	}
	cleanAvl_r(lf->left);
	cleanAvl_r(lf->right);
	free(lf->dta);
	free(lf);
}

int searchAvl(struct avlTree *t,struct data *d){
	int found;
	if(t->root == NULL){
		free(d);
		return 0;
	}
	found = searchAvl_r(t->root,d);
	free(d);
	return found;
}

int searchAvl_r(struct avlLeaf *curr,struct data *d){
	if(curr == NULL){
		return 0;
	}
	if(compareData(curr->dta,d) == 1){
		return 1;
	}
	if(sumData(d) > sumData(curr->dta)){
		return searchAvl_r(curr->right,d);
	}else{
		return searchAvl_r(curr->left,d);
	}
	return 0;
}
