#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void add(struct Node* list1, struct Node* list2, struct Node** sum, int c1, int c2, int* carry)
{
	if (c1 == 0 && c2==0)
	{
		return;
	}
	if (c1 == c2)
	{
		add(list1->next, list2->next, sum, c1 - 1, c2 - 1, carry);
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->data = (list1->data + list2->data + (*carry)) % 10;
		(*carry) = (list1->data + list2->data + (*carry))/10;
		newNode->next = *sum;
		(*sum)= newNode;
	}
	else if (c1 > c2)
	{
		add(list1->next, list2, sum, c1 - 1, c2, carry);
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->data = (list1->data + (*carry)) % 10;
		(*carry) = (list1->data+ (*carry)) / 10;
		newNode->next = *sum;
		(*sum) = newNode;
	}
	else
	{
		add(list1, list2->next, sum, c1, c2-1, carry);
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->data = (list1->data + (*carry)) % 10;
		(*carry) = (list1->data + (*carry)) / 10;
		newNode->next = *sum;
		(*sum) = newNode;
	}
}
struct Node* addLists(struct Node* l1, struct Node* l2)
{
	struct Node* temp1 = l1;
	struct Node* temp2 = l2;
	int c1 = 0, c2 = 0;
	while (temp1 != NULL)
	{
		c1++;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		c2++;
		temp2 = temp2->next;
	}
	int* carry;
	int c = 0;
	carry = &c;
	struct Node *nRoot= NULL;
	add(l1, l2, &nRoot, c1, c2, carry);
	return nRoot;
}
