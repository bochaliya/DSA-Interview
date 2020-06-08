/*
Reverse List
1.Iterative method
     Initialize three pointers prev as NULL, curr as head and next as NULL.
        Iterate trough the linked list. In loop, do following.
        // Before changing next of current,
        // store next node
        next = curr->next

        // Now change next of current
        // This is where actual reversing happens
        curr->next = prev

        // Move prev and curr one step forward
        prev = curr
        curr = next
2.Recursive method

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

Node* reverse_list(Node *head) {
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	Node *rest = reverse_list(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;

}

int main() {
	Node *head = create_node(5);
	head->next = create_node(4);
	head->next->next = create_node(3);
	head->next->next->next = create_node(2);
	head->next->next->next->next = create_node(1);
	head = reverse_list(head);
	print_list(head);
	return 0;
}