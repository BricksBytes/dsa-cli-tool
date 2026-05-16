#include<iostream>

using namespace std;

//List: 1 -> 2 -> 3 -> 4 -> 5
//
//Start : slow = 1, fast = 1
//Step 1 : slow = 2, fast = 3
//Step 2 : slow = 3, fast = 5
//Step 3 : fast->next = NULL → STOP!
//
//slow = 3 ← MIDDLE!

struct Node
{
	int data;
	Node* next;
	Node(int val) :data(val), next(nullptr) {}

};

Node* MiddleElement(Node* head)
{
	if (head == nullptr)
		return head;

	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
};

static void display(Node* head)
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
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	cout << "Original: ";
	display(head);

	Node* mid = MiddleElement(head);
	cout << "Middle: " << mid->data << "\n";

	return 0;
}