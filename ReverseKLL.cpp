#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};


struct Node* revK(struct Node* root)
{
	struct Node* move = root->next;
	struct Node* last = root;
	while (move != NULL)
	{
		last->next = move->next;
		move->next = root;
		root = move;
		move = last->next;
	}
	return root;
}




struct Node* reverse(struct Node* root,int k)
{
	struct Node* root1=root;
	struct Node* nxt = root;
	for (int i =1; i < k; i++)
	{
		if (nxt == NULL)
			return root;
		nxt = nxt->next;
		
	}
	struct Node* nxtRoot = nxt->next;
	nxt->next = NULL;
	root= revK(root1);
	root1->next = nxtRoot;
	while (root1->next != NULL)
	{
		nxt = root1->next;
		struct Node* first = root1->next;
		for (int i = 1; i < k; i++)
		{
			if (nxt == NULL)
				return root;
			nxt = nxt->next;
		}
		nxtRoot = nxt->next;
		nxt->next = NULL;
		root1->next= revK(root1);
		first->next = nxtRoot;
		root1 = first;
	}
	return root;
}
