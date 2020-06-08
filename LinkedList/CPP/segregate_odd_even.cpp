/*
Segregate even and odd nodes
Method 1:
The idea is to get pointer to the last node of list.
And then traverse the list starting from the head node and move the odd valued nodes from their current position to end of the list.
Method 2:
The idea is to split the linked list into two: one containing all even nodes and other containing all odd nodes. 
And finally attach the odd node linked list after the even node linked list

*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node* create_node(int data) {
	Node *new_node = new Node;
	new_node->next = NULL;
	new_node->data = data;
	return new_node;
}

void print_list(Node *head) {
	while(head != NULL) {
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL\n";
}

void segregate_even_odd(Node **head_ref) {
	Node *evenHead = NULL;
	Node *evenEnd = NULL;
	Node *oddHead = NULL;
	Node *oddEnd = NULL;
	Node *currNode = *head_ref;
	while(currNode != NULL) {
		int val = currNode->data;
		if(val%2 == 0) {
			if(evenHead == NULL) {
				evenHead = currNode;
				evenEnd = currNode;
			}
			else {
				evenEnd->next = currNode;
				evenEnd = evenEnd->next;
			}
		}
		else {
			if(oddHead == NULL) {
				oddHead = currNode;
				oddEnd = currNode;
			}
			else {
				oddEnd->next = currNode;
				oddEnd = oddEnd->next;
			}
		}
		currNode = currNode->next;
	}
	if(evenHead == NULL || oddHead == NULL) {
		return;
	}
	evenEnd->next = oddHead;
	oddEnd->next = NULL;

	*head_ref = evenHead;
}

int main() {
	Node *head = create_node(5);
	head->next = create_node(4);
	head->next->next = create_node(3);
	head->next->next->next = create_node(2);
	head->next->next->next->next = create_node(1);
	segregate_even_odd(&head);
	print_list(head);
	return 0;
}