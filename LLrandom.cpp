#include<iostream>
#include<map>
using namespace std;
struct Node{
	int data;
	struct Node* next;
	struct Node* random;
};

struct Node* newList(struct Node* root)
{
	struct Node* newRoot=NULL;
	struct Node* check = root;
	map<struct Node*,struct Node*> m;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data =check->data;
	m[check] = newNode;
	newNode->next = NULL;
	newRoot = newNode;
	check= check->next;
	while (check!=NULL)
	{
		struct Node* nNode = (struct Node*) malloc(sizeof(struct Node));
		nNode->data = check->data;
		m[check] = nNode;
		nNode->next = NULL;
		newNode->next = nNode;
		newNode = nNode;
		check = check->next;
	}
	check=root;
	while (check != NULL)
	{
		m[check]->random = m[check->random];
		check = check->next;
	}
	return newRoot;
}