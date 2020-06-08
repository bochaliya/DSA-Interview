/*
Check if given list is palindrome
1.Use stack
Traverse the list from head to tail and push every node data in stack.
Traverse list form head and pop one by one from stack, compare it with list data, if don't match return false.
If all nodes matched return true.
Time - O(n)
Space- O(n)

2.By reversing the list
This method takes O(n) time and O(1) extra space.
1) Get the middle of the linked list.
2) Reverse the second half of the linked list.
3) Check if the first half and second half are identical.
4) Construct the original linked list by reversing the second half again and attaching it back to the first half.

3,Using recursion
Use two pointers left and right. Move right and left using recursion and check for following in each recursive call.
1) Sub-list is palindrome.
2) Value at current left and right are matching.

If both above conditions are true then return true.
Time - O(n)
Space - O(n) if Function stack size is considered else O(1)

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

bool palindrome(Node **left, Node *right) {
	if(right == NULL || *left == NULL) {
		return true;
	}
	if(palindrome(left, right->next) == false) {
		return false;
	}
	if((*left)->data != right->data) {
		return false;
	}
	*left = (*left)->next;
	return true;
}

bool check_palindrome(Node *head) {
	return palindrome(&head, head);
	
}
int main() {
	Node *head = create_node(1);
	head->next = create_node(2);
	head->next->next = create_node(3);
	head->next->next->next = create_node(2);
	head->next->next->next->next = create_node(1);
	bool checkFlag = check_palindrome(head);
	if(checkFlag) {
		cout<<"List is palindrome\n";
	}
	else {
		cout<<"List is not palindrome\n";
	}
	return 0;
}