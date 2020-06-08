/* 
Detecting loop in linked list
1. Hashing
Traverse the list one by one and keep putting the node addresses in a Hash Table. 
At any point, if NULL is reached then return false and if next of current node points to any of the previously stored nodes in Hash then return true.
Time complexity - O(n)
Space complexity - O(n)

2. Floyd's Cycle-Finding Algorithm
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

/* Floyd's cycle detection */
bool detect_loop(Node *head) {
	Node *slow_ptr = head, *fast_ptr = head;
	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(fast_ptr == slow_ptr) {
			return true;
		}
	}
	return false;
}

int main() {
	Node *head = create_node(1);
	head->next = create_node(2);
	head->next->next = create_node(3);
	head->next->next->next = create_node(4);
	head->next->next->next->next = create_node(5);
	head->next->next->next->next->next = head->next;
	bool detection_flag = detect_loop(head);
	if(detection_flag) {
		cout<<"Loop found\n";
	}
	else {
		cout<<"No loop\n";
	}
	return 0;
}