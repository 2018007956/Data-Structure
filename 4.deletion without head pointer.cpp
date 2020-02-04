// Deleting a node from a linked list without head pointer
/*Write a program to delete a node in a linked list where the head pointer to the node is not given, 
	only the address of the node to be deleted is provided.
	
	1.  Declare 'temp' to store node values
	2.  Declare 'ListNode* pre' and initialize to address of node to be deleted;
	3.	While node->next
        //swap value only with the next node
        temp =node->data;
        node->data=(node->next)->data;
        (node->next)->data=temp;
        // Go to the next node
        node=node->next;
    END WHILE
	4.  Make the last node NULL
		ListNode *fast=pre->next; //check what pre is at step no 2
	    While (fast->next)
		    pre=pre->next;
			fast=fast->next;
		END WHILE
		pre->next=NULL;
	*/
#include <iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
};

ListNode* creatnode(int d)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = d;
	temp->next = NULL;
	return temp;
}
void traverse(ListNode* head)
{
	ListNode* current = head; // current node set to head
	int count = 0; // to count total no of nodes

	printf("displaying the list\n");
	//traverse until current node isn't NULL
	while ( current != NULL ) {
		count++; //increase node count
		if ( current->next )
			printf("%d->", current->val);
		else
			printf("NULL\n");
		current = current->next; // go to next node
	}
	printf("total no of nodes : %d\n", count);
}

void deleteNode(ListNode* node)
{
	//deleting node without head pointer
	int temp;
	ListNode* pre = node;

	while ( node->next ) {
		pre = node;
		node->val = (node->next)->val;
		node = node->next;
	}
	pre->next = NULL;
	free(node);
}

int main()
{
	ListNode* head = creatnode(4);

	head->next = creatnode(5);
	head->next->next = creatnode(1);
	head->next->next->next = creatnode(6);
	head->next->next->next->next = creatnode(7);
	head->next->next->next->next->next = creatnode(8);

	ListNode* todelete = head->next->next; //1

	cout << "deleting node with value 1\n";

	cout << "before deletion:\n";
	traverse(head);

	deleteNode(todelete);

	cout << "after deletion:\n";
	traverse(head);

	return 0;
}



