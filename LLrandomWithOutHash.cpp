#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* newListWithoutHash(struct Node* root)
{
	struct Node* list = root;
	while (list != NULL)
	{
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->data = list->data;
		newNode->next = list->next;
		list->next = newNode;
		list = newNode->next;
	}
	list = root;
	while (list != NULL)
	{
		list->next->random = list->random->next;
		list = list->next->next;
	}
	struct Node* newRoot = root->next;
	list = newRoot;
	while (list->next!= NULL)
	{
		list->next = list->next->next;
		list = list->next;
	}
	return newRoot;
}