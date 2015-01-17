#include "bst.h"

struct leaf* createLeaf(struct data *d){
	struct leaf* maple = malloc(sizeof(struct leaf));
	maple->right = NULL;
	maple->left = NULL;
	maple->dta = d;
	return maple;
}

struct tree* createTree(){
	struct tree* oak = malloc(sizeof(struct tree));
	oak->root = NULL;
	return oak;
}

void insertBst(struct tree *t,struct data *d){
	struct leaf *newnode = createLeaf(d);
	if(t->root == NULL){
		t->root = newnode;
	}else{
		insertBst_r(t->root,newnode);
	}
}

void insertBst_r(struct leaf* current,struct leaf* newLeaf){
	if(sumData(newLeaf->dta) > sumData(current->dta)){
		if(current->right == NULL){
			current->right = newLeaf;
		}else{
			insertBst_r(current->right,newLeaf);
		}
	
	}else{
		if(current->left == NULL){
			current->left = newLeaf;
		}else{
			insertBst_r(current->left,newLeaf);
		}
	}
}

void inOrderBst(struct tree *t){
	if(t != NULL && t->root != NULL)
		inOrderBst_r(t->root);

}

void inOrderBst_r(struct leaf *current){
	if(current == NULL){
			return;
	}
	inOrderBst_r(current->left);
	printData(current->dta);
	inOrderBst_r(current->right);
}

float totalSum(struct tree *t){
	return (totalSum_r(t->root));
}

float totalSum_r(struct leaf* current){
	float leftsum,rightsum,sum;
	if(current == NULL){
		return 0;
	}
	leftsum = totalSum_r(current->left);
	rightsum = totalSum_r(current->right);
	sum = sumData(current->dta) + leftsum + rightsum;
	return sum;
}

void preOrderBst(struct tree *t){
	if(t != NULL && t->root != NULL)
	preOrderBst_r(t->root);
}

void preOrderBst_r(struct leaf *lf){
	if(lf == NULL){
		return;
	}
	printData(lf->dta);
	preOrderBst_r(lf->left);
	preOrderBst_r(lf->right);
}

void postOrderBst(struct tree *t){
	if(t != NULL && t->root != NULL)
	postOrderBst_r(t->root);
}

void postOrderBst_r(struct leaf *lf){
	if(lf == NULL){
		return;
	}
	postOrderBst_r(lf->left);
	postOrderBst_r(lf->right);
	printData(lf->dta);
}

struct data* getMaxData(struct tree *tr){
	if(tr != NULL && tr->root != NULL)
		return (getMaxData_r(tr->root));
	return NULL;
}

struct data* getMaxData_r(struct leaf* lf){
	if(lf->right == NULL){
		return (lf->dta);
	}
	return (getMaxData_r(lf->right));
}

struct data* getMimData(struct tree *tr){
	if(tr != NULL && tr->root != NULL)
		return (getMimData_r(tr->root));
	return NULL;
}

struct data* getMimData_r(struct leaf* lf){
	if(lf->left == NULL){
		return (lf->dta);
	}
	return (getMimData_r(lf->left));
}

int getBstHeight(struct tree *tr){
	return (getBstHeight_r(tr->root));
}

int getBstHeight_r(struct leaf* lf){
	int leftheight = 0,rightheight = 0;
	if(lf == NULL){
		return 0;
	}
	leftheight = 1 + getBstHeight_r(lf->left);
	rightheight = 1 + getBstHeight_r(lf->right);
	if (leftheight > rightheight){
		return leftheight;
	}else{
		return rightheight;
	}
}

void printInRange(struct tree *tr, float begin, float end){
	printInRange_r(tr->root,begin,end);
}

void printInRange_r(struct leaf* lf, float begin,float end){
	if(lf == NULL){
		return;
	}
	printInRange_r(lf->left,begin,end);
	if (sumData(lf->dta) > begin && sumData(lf->dta) < end){
		printData(lf->dta);
	}
	printInRange_r(lf->right,begin,end);
}

int isCompleteBst(struct tree *tr){
	if(isCompleteBst_r(tr->root)){
		return 1;
	}else{
		return 0;
	}
}

int isCompleteBst_r(struct leaf* lf){
	int leftheight=0,rightheight=0;
	if(lf == NULL){
		return 0;
	}
	leftheight = 1 + isCompleteBst_r(lf->left);
	rightheight = 1 + isCompleteBst_r(lf->right);
	if(lf->left != NULL && lf->right == NULL){
			return leftheight;
	}
	if(lf->left == NULL && lf->right != NULL){
			return rightheight;
	}
	if(leftheight == rightheight){
			return leftheight;
	}
	return 0;
}

int isFullBst(struct tree *tr){
	if(tr != NULL && tr->root != NULL)
		return (isFullBst_r(tr->root));
	return 0;
}

int isFullBst_r(struct leaf *lf){
	int lefttree=1,righttree=1;
	if(lf->left == NULL && lf->right == NULL){
		return 1;
	}
	if(lf->left != NULL && lf->right == NULL){
		return 0;
	}
	if(lf->left == NULL && lf->right != NULL){
		return 0;
	}
	lefttree = isFullBst_r(lf->left);
	righttree = isFullBst_r(lf->right);
	if(lefttree == 1 && righttree ==1){
		return 1;
	}else{
		return 0;
	}
}

void reverseBST(struct tree *t){
	reverseBST_r(t->root);
}

void reverseBST_r(struct leaf *lf){
	struct leaf *temp;
	if(lf == NULL){
		return;
	}
	temp = lf->left;
	lf->left = lf->right;
	lf->right = temp;
	reverseBST_r(lf->left);
	reverseBST_r(lf->right);
}

float sumLeaves(struct tree *t){
	return sumLeaves_r(t->root);
}

float sumLeaves_r(struct leaf *lf){
	if(lf != NULL){
		float sumleavesleft=0,sumleavesright=0;
		if(lf->left == NULL && lf->right == NULL){
			return sumData(lf->dta);
		}
		sumleavesleft = sumLeaves_r(lf->left);
		sumleavesright = sumLeaves_r(lf->right);
		return (sumleavesleft + sumleavesright);
	}
	return 0;
}

void printBreadthFirstSearch(struct tree *t){
	if(t->root != NULL){
		struct queue * qu = createQueue();
		pushQueue(qu,t->root);
		while(!isEmptyQueue(qu)){
			printData(topQueue(qu)->dta);
			if(topQueue(qu)->left != NULL){
				pushQueue(qu,topQueue(qu)->left);
			}
			if(topQueue(qu)->right != NULL){
				pushQueue(qu,topQueue(qu)->right);
			}
			popQueue(qu);
		}
		free(qu->que);
		free(qu);
	}
}

void printDepthFirstSearch(struct tree *t){
	struct stack *st = createStack();
	struct leaf *temp = t->root;
	while(temp != NULL){
		printData(temp->dta);
		pushStack(st,temp);
		temp = temp->left;
	}

	while(!isEmptyStack(st)){
		temp = topStack(st);
		popStack(st);
		if(temp->right != NULL){
			temp = temp->right;
			while(temp != NULL){
				printData(temp->dta);
				pushStack(st,temp);
				temp = temp->left;
			}
		}
	}
	free(st->stk);
	free(st);
}

void cleanBST(struct tree *t){
	if(t->root != NULL){
		cleanBST_r(t->root);	
	}
	free(t);
}
void cleanBST_r(struct leaf *lf){
	if(lf == NULL){
		return;
	}
	cleanBST_r(lf->left);
	cleanBST_r(lf->right);
	free(lf->dta);
	free(lf);
}

int searchBst(struct tree *t, struct data *d){
	int found;
	if(t->root != NULL){
		found = searchBst_r(t->root,d);
		free(d);
		return found;
	}
	free(d);
	return 0;
}

int searchBst_r(struct leaf *curr,struct data *d){
	if(curr == NULL){
		return 0;
	}
	if(compareData(curr->dta,d) == 1){
		return 1;
	}
	if(sumData(d) > sumData(curr->dta)){
		return searchBst_r(curr->right,d);
	}else{
		return searchBst_r(curr->left,d);
	}
	return 0;
}
