/*
Find length of loop in linked list
Floyd's Cycle-Finding Algorithm
N = distance traveled by slow pointer
2N = distance traveled by fast pointer
D = distance between head to start of loop
K = distance between start of loop to meeting point of fast and slow pointer
C = perimeter of loop
i,j = positive intergers 0,1,2,3...

N = D + K + C(i)
2N = D + K + C(j)
N = C(j-i) =>this equation has always a solutions, so slow and fast pointer will definitely meet at some point on cycle.

2D + 2K = 2C(i) = D + K + C(j)
D = (j-2i)C - K => This proves that if we start one pointer from meeting point and one pointer from head and after some time they will meet a the start of loop.

Find common pointer(start pointer of loop) using algoritm. We store the address of this common point in a pointer variable say ptr. 
Then we initialize a counter with 1 and start from the common point and keeps on visiting next node and increasing the counter till we again reach the common point(ptr). 
At that point, the value of the counter will be equal to the length of the loop.

Time complexity - O(n)
Space complexity - O(1)

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node* create_node(int data) {
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

int countNodes(Node *temp) {
	int count = 0;
	Node *n = temp;
	while(n->next != temp) {
		count++;
		n = n->next;
	}
	return count;
}

int loopLength(Node *head) {
	Node *slow_ptr = head, *fast_ptr = head;
	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if(slow_ptr == fast_ptr) {
			// loop detected
			return countNodes(slow_ptr);
		}
	}
	return 0;
}

int main() {
	Node *head = create_node(1);
	head->next = create_node(2);
	head->next->next = create_node(3);
	head->next->next->next = create_node(4);
	head->next->next->next->next = create_node(5);
	head->next->next->next->next->next = head->next;
	cout<<loopLength(head)<<endl;
	return 0;
}