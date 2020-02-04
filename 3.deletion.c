// C implementation of deletion in a linked list
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* next;
};
void traverse(struct node* head)
{
	struct node* current = head; //current node set to head
	int count = 0; //to count total no of nodes
	printf("n traversing the list\n");
	while ( current != NULL ) { //traverse until current node isn't NULL
		count++; //increase node count
		printf("%d ", current->data);
		current = current->next; //go to next node
	}
	printf("\ntotal no of nodes : %d\n", count);
}
struct node* createnode(int d)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = d;
	temp->next = NULL;
	return temp;
}
int main()
{
	printf("creating the linked list by inserting new nodes at the beginning\n");

	printf("enter 0 to stop building the list, else enter any integer\n");

	int k, count = 1, x;

	struct node *curr, *temp, *prev;
	scanf("%d", &k);
	struct node* head = createnode(k); //building list, first node
	scanf("%d", &k);
	//////////////////inserting at beginning////////////////
	while ( k ) {
		curr = createnode(k);
		curr->next = head; //inserting each new node at the beginning
		head = curr;
		scanf("%d", &k);
	}
	traverse(head); //displaying the list

	///////////////////deleting the first node//////////////////
	printf("\ndeleting the first node..............\n");
/* 1. Create a temporary node, say `temp` which points to the head node (first node) of the list
	2. Move head node pointer to the immediate next node and delete (dispose) the temp node. */
	temp = head; //first node assigned to temp
	head = head->next; //head node is updated
	free(temp); //deleting the first node

	traverse(head); //displaying the list

	printf("\nfirst node deleted.............\n");

/* 1. We need to keep track of the previous node of last node. That's why while traversing to the last node we need to set a `prev` node also which will point to the previous node of the `tail` node( last node) after traversal.
	2. So, we have two pointer, one `tail` node pointing to the last node and another is `prev` node pointing to the previous node of the last node.
	3. Set the next pointer of the `prev` node to NULL and delete the tail node. (last node) */
	temp = head->next;
	prev = head;
	while ( temp->next != NULL ) {
		temp = temp->next;
		prev = prev->next;
	}
	//after traversal temp points to the last
	//node and prev to the previous node of the last node
	prev->next = NULL;
	free(temp);
	traverse(head);
	printf("\last node deleted..................\n");

	////////////////////deleting any intermediate node in the list/////////////
/*	1. Smilar to the previous case, a `curr` node and a `prev` node is to be maintained. `Curr` node will point to the node to be deleted and `prev` node will point to the previous node.
	2. Set the `next` pointer of the `prev` node to the `next` pointer of `curr` node.
	3. Delete the `curr` node. */
	printf("\n enter the position of the node you want to delete\n");
	scanf("%d", &x);
	temp = head->next;
	prev = head;
	while ( count != x - 1 ) {
		temp = temp->next;
		prev = prev->next;
		count++;
	} // temp pointing to the node to be deleted and prev to the previous node 

	prev->next = temp->next;
	free(temp);

	traverse(head);

	return 0;
}