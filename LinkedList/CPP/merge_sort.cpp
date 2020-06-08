/*
Merge sort for linked List.
Below implementation changes next links to sort the linked list.
merge_sort(head_ref)
if head is null or there is only one element in list
then return
else
Split the list into two halves.

call merge_sort(a);
call merge_sort(b);

merge sorted list a and b
return head_ref

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

Node* mergeLists(Node *left, Node *right) {
	Node *result = NULL;
	if(left == NULL) {
		return right;
	}
	else if(right == NULL) {
		return left;
	}
	if(left->data <= right->data) {
		result = left;
		result->next = mergeLists(left->next, right);
	}
	else {
		result = right;
		result->next = mergeLists(left, right->next);
	}
	return result;
}

void merge_sort(Node **head_ref) {
	if(*head_ref == NULL || (*head_ref)->next == NULL) {
		return;
	}
	Node *slow = *head_ref, *fast = *head_ref, *prev = *head_ref;
	while(fast != NULL && fast->next != NULL) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(prev != NULL) {
		prev->next = NULL;
	}
	merge_sort(head_ref);
	merge_sort(&slow);
	*head_ref = mergeLists(*head_ref, slow);
}

int main() {
	Node *head = create_node(5);
	head->next = create_node(4);
	head->next->next = create_node(3);
	head->next->next->next = create_node(2);
	head->next->next->next->next = create_node(1);
	merge_sort(&head);
	print_list(head);
	return 0;
}