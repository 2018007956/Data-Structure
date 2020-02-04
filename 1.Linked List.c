/*
[linked list properties]
¡Ü Successive elements are connected by pointers.
¡Ü The last element points to NULL.
¡Ü Can grow or shrink in size during program execution.
¡Ü Can be made as long as needed. (Until system memory exhausts).
¡Ü Doesn¡¯t waste memory space but takes some extra memory for pointers. It allocates memory as it grows.

[Link list as an ADT]
Main link list ADT operation:
	1. Insert: Insert element to the list
	2. Delete: deletes element from the list
Auxiliary link list ADT operations:
	1. Delete list: delete and remove the whole list
	2. Count: returns the number of elements in the list
	3. Find nth node: Returns the nth node from the beginning of the list
*/

//C code to traverse a linked list and count number of nodes
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* next;
};
void traverse(struct node* head)
{
	struct node* current = head;
	int count = 0;
	printf("\n traversing the list\n");

	//traverse until current node isn't NULL
	while ( current != NULL ) {
		count++;
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\ntotal no of nodes : %d\n", count);
}
struct node* createnode(int d)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = d;
	temp->next = NULL;
	return temp;
}
int main()
{
	printf("creating & traversing linked list\n");

	//linked list is built according to 5-10-20-1
	struct node* head = createnode(5);

	head->next = createnode(10);
	head->next->next = createnode(20);
	head->next->next->next = createnode(1);

	traverse(head);
	return 0;
}

/* 
Time complexity: O(n), for scanning the list of size n
Space complexity: O(1), no additional memory required
*/




