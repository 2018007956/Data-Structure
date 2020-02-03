//C implementation of inserting a new node to a link list
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node;
void insert_node(node** head, int val, int position)
{
	struct node *curr = *head, *tmp_node = NULL;
	int count = 1;

	tmp_node = (node*)malloc(sizeof(node));
	if ( tmp_node == NULL ) {
		printf("Memory allocation is failed:");
		return;
	}
	tmp_node->data = val;
	tmp_node->next = NULL;

	if ( *head == NULL ) {
		//List is empty, assigning head pointer to tmp_node
		*head = tmp_node;
		return;
	}
	if ( position == 1 ) {
		//inserting node at the beginning of the list
		tmp_node->next = *head; 
		    //Update next pointer of the new node (node to be inserted) to point to the current node
		*head = tmp_node;
		    //update new node as head node
		return;
	}
	if ( count + 1 == position && curr->next == NULL ) { 
		// Inserting node at the end of the list  (The next pointer of the new node to be NULL)
		curr->next = tmp_node;
		    //Last node of the existing node is linked with the new node
		    //i.e. , the last node's(existing) next pointer points to the new node
		return;
	}

	// Inserting node in the list at given position
	while ( curr&&count < position - 1 ) {
		curr = curr->next;//Move the current pointer upto the position where node to be inserted
		count++;
	}
	if ( position > (count + 1) ) {
		printf("\n position doesn't exists in the list ");
		return;
	}
	tmp_node->next = curr->next;
	    //Store current next pointer address to tmp_node next
	curr->next = tmp_node;
	    //Store tmp_node address to current next
}
void print_list(node* head)
{
	printf("\nList elements:\n");
	while ( head ) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
	return;
}
int main(){
	int num_nodes, value, index, position;
	node* head = NULL;

	printf("Enter te no. of nodes to create list: ");
	scanf("%d", &num_nodes);

	for ( index = 1; index <= num_nodes; index++ ) {
		printf("Enter node data for position %d in the list: ", index);
		scanf("%d", &value);
		insert_node(&head, value, index);
	}
	print_list(head);

	/*
	printf("\nInsert the element at 1st position: ");
	scanf("%d", &value);
	insert_node(&head, value, 1);
	//We have inserted one more element, hence num_nodes get increased by 1 num_nodes +=1;
	num_nodes += 1;
	print_list(head);

	printf("\nInsert the element at last position:  ");
	scanf("%d", &value);
	insert_node(&head, value, num_nodes + 1);
	num_nodes += 1;
	print_list(head);
	*/

	printf("\nInsert the element at any position in the list\n");
	printf("Enter the position: ");
	scanf("%d", &position);
	printf("Enter the element value: ");
	scanf("%d", &value);
	insert_node(&head, value, position);
	num_nodes += 1;
	print_list(head);

	return 0;
}
