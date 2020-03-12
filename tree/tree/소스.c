#include <stdio.h>
#include <stdlib.h>

#define numRow 5 /* power of 2 (2, 4, 8, 16, ...)가 아닌 값으로 설정 */
#define numCol 10
int matrix[numRow][numCol] = {
{ 5,90,5,9,80,80,7,90,7,90 },
{ 100,30,30,51,160,160,160,51,160,59 },
{ 500,100,7000,100,900,600,100,100,650,100 },
{ 1000,300,41,300,41,41,41,900,900,950 },
{ 90,81,81,95,81,83,81,90,81,90 }
};

typedef struct _treePointer
{
	int key;
	int count;
	struct _treePointer* leftChild;
	struct _treePointer* rightChild;
} treePointer;

treePointer* insert(treePointer* root, int key)
{
	if (root == NULL) {
		root = (treePointer*)malloc(sizeof(treePointer));
		root->leftChild = root->rightChild = NULL;
		root->key = key;
		root->count = 1;
		return root;
	}
	else if (root->key > key)
		root->leftChild = insert(root->leftChild, key);
	else if (root->key < key)
		root->rightChild = insert(root->rightChild, key);
	else root->count++;
	return root;
}

treePointer* delete(treePointer* root, int key)
{
	treePointer* tNode = NULL;
	if (root == NULL)
		return NULL;

	if (root->key > key)
		root->leftChild = delete(root->leftChild, key);
	else if (root->key < key)
		root->rightChild = delete(root->rightChild, key);
	else
	{
		if (root->rightChild != NULL && root->leftChild != NULL)
		{
			tNode = root->rightChild;
			while (tNode->leftChild != NULL)
				tNode = tNode->leftChild;
			root->key = tNode->key;
			root->rightChild = delete(root->rightChild, tNode->key);
		}
		else
		{
			tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
			free(root);
			return tNode;
		}
	}

	return root;
}

treePointer* search(treePointer* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->key == key)
		return root;
	else if (root->key > key)
		return search(root->leftChild, key);
	else
		return search(root->rightChild, key);
}

treePointer* findMax(treePointer* root) {
	treePointer* maxNode = (treePointer*)malloc(sizeof(treePointer));
	treePointer* left = (treePointer*)malloc(sizeof(treePointer));
	treePointer* right = (treePointer*)malloc(sizeof(treePointer));
	treePointer* rootsave = root;
	if (root != NULL) {
		left = findMax(root->leftChild);
		right = findMax(root->rightChild);
		if (left->count > right->count) {
			maxNode = left;
		}
		else if (right->count < left->count) {
			maxNode = right;
		}
		else {
			maxNode = (right->key > left->key) ? right : left;
		}
		if (rootsave->count > maxNode->count) {
			maxNode = root;
		}
		else if (rootsave->count == maxNode->count && rootsave->key > maxNode->key) {
			maxNode = root;
		}
	}

	return maxNode;
}

void print(treePointer* root)
{
	if (root == NULL)
		return;
	print(root->leftChild);
	printf("%d ", root->key);
	printf("%d ", root->count);
	print(root->rightChild);
}

void main()
{
	treePointer* run[numRow];
	for (int i = 0; i < numRow; i++) {
		run[i] = NULL;
		for (int j = 0; j < numCol; j++) {
			run[i] = insert(run[i], matrix[i][j]);
		}
	}

	for (int i = 0; i < numRow; i++) {
		print(run[i]);
		printf("\n");
	}

	for (int i = 0; i < numRow; i++)
		printf("%d %d\n", findMax(run[i])->key, findMax(run[i])->count);

	treePointer * loserTree[numRow * 2];

	loserTree[8] = findMax(run[0]);
	loserTree[9] = findMax(run[1]);
	loserTree[5] = findMax(run[2]);
	loserTree[6] = findMax(run[3]);
	loserTree[7] = findMax(run[4]);
}