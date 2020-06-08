/*
Get intersection point of two linked lists
1.use two loops 
time - O(m*n)

2.mark visited node - require modification in list
time- O(m+n) 

3.use hash map
time - O(m+n)
space - O(m+n)

4.use difference of node counts
Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
time - O(m+n)


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

Node* intersection_point(Node *head1, Node *head2) {
	unordered_set<Node*> s;
	while(head1 != NULL) {
		s.insert(head1);
		head1 = head1->next;
	}
	while(head2 != NULL) {
		if(s.find(head2) != s.end()) {
			return head2;
		}
		head2 = head2->next;
	}
	return NULL;
}

int main() {
	Node *head1 = create_node(5);
	head1->next = create_node(4);
	head1->next->next = create_node(3);
	head1->next->next->next = create_node(2);
	head1->next->next->next->next = create_node(1);
	Node *head2 = create_node(6);
	head2->next = create_node(5);
	head2->next->next = head1->next->next;
	Node *result = intersection_point(head1, head2);
	if(result == NULL) {
		cout<<"No intersection point"<<endl;
	}
	else {
		cout<<"intersection node: "<<(result->data)<<endl;
	}
	return 0;
}