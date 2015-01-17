#include <stdio.h>

#include "random.h"
#include "structures.h"
#include "avl.h"
#include "bst.h"
#include "timing.h"

int main(int argc,char* argv[]){
	randSeed();
	int i,mul,srch;
	clock_t start,end;

//	Return if the input from command line is passed
	if(argc != 2){
		printf("Please enter the multiple from command line");
		return 0;
	}

	struct avlTree * pine = createAvlTree();
	struct tree * tr = createTree();

	mul = atoi(argv[1]);

//	Insert into Avl Tree
	start = getTime();
	for(i=0;i < (mul * 1000000);i++){
		insertAvl(pine,randomData());
	}
	end = getTime();
	printf("%f \n",timeDiff(start,end));

// Insert into BST
	start = getTime();
	for(i=0;i < (mul * 1000000); i++){
		insertBst(tr,randomData());
	}
	end = getTime();
	printf("%f \n",timeDiff(start,end));

// Search into AVL
	start = getTime();
	for(i=0;i< (mul * 1000000);i++){
		srch = searchAvl(pine,randomData());
	}
	end = getTime();
	printf("%f \n",timeDiff(start,end));

// Search into BST
	start = getTime();
	for(i=0;i< (mul * 1000000);i++){
		srch = searchBst(tr,randomData());
	}
	end = getTime();
	printf("%f \n",timeDiff(start,end));

	cleanAvl(pine);
	cleanBST(tr);
	return 0;
}
