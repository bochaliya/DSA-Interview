/*

Linked list implementation.
1.Create Node - time complexity O(1)
2.Print List - time complexity O(n)
3.Insert node at head - time complexity O(1)
4.Insert node at end - time complexity O(n)
5.Insert node after a given node - time complexity O(n)
6.Delete key - time complexity O(n)
7.Get length - time Complexity O(n)

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

void insert_at_head(Node **head, int new_data) {
	Node *new_node = create_node(new_data);
	new_node->next = *head;
	*head = new_node;
}

void insert_at_end(Node **head, int new_data) {
	if(*head == NULL) {
		insert_at_head(head, new_data);
	}
	else {
		Node *temp = *head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		Node *new_node = create_node(new_data);
		temp->next = new_node;
	}
}

void insert_after(Node *prev, int new_data) {
	Node *new_node = create_node(new_data);
	if(prev == NULL) {
		cout<<"prev node cannot be NULL\n";
		return;
	}
	new_node->next = prev->next;
	prev->next = new_node;
}

void delete_node(Node **head, int key) {
	Node *temp = *head, *prev = *head;
	if(temp != NULL && temp->data == key) {
		*head = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL) {
		cout<<"key not found\n";
		return;
	}
	prev->next = temp->next;
	free(temp);
}

int get_length(Node *head) {
	if(head == NULL) {
		return 0;
	}
	return 1 + get_length(head->next);
}

int main() {
	Node *head = NULL;
	insert_at_head(&head, 2);
	print_list(head);
	insert_at_head(&head, 1);
	print_list(head);
	insert_after(head->next, 3);
	print_list(head);
	insert_after(head->next->next, 4);
	print_list(head);
	insert_at_end(&head, 5);
	print_list(head);
	insert_at_end(&head, 6);
	print_list(head);
	cout<<"length: "<<get_length(head)<<endl;
	delete_node(&head, 3);
	print_list(head);
	delete_node(&head, 1);
	print_list(head);
	delete_node(&head, 3);
	print_list(head);
	cout<<"length: "<<get_length(head)<<endl;
	return 0;
}