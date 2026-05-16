#include<iostream>
#include<vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) :data(val), next(nullptr) {}
};

Node* ReverseLinkedlist(Node* head)
{
	if (head == nullptr)
		return head;

	Node* next = nullptr;
	Node* curr = head;
	Node* prev = nullptr;

	while (curr !=nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
void display(Node* head)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << "[" << temp->data << "]";
		if (temp->next != nullptr)
			cout << " ->";
		temp = temp->next;
	}
	cout << "NULL\n";
}
int main()
{
	// Create list: 1->2->3->4->5

	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	cout << "Original : ";
	display(head);
	head = ReverseLinkedlist(head);
	cout << "Reversed :";
	display(head);
	return 0;

}