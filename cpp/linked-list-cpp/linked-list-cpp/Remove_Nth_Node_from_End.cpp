#include<iostream>
using namespace std;

//Pointer 1 → moves N steps ahead first
//Pointer 2 → starts from head
//Then both move together
//When Pointer 1 reaches end
//Pointer 2 is at the node to delete!

struct Node
{
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr){}
};

// ── REMOVE NTH NODE FROM END ──────────────────────
Node* removeNthFromEnd(Node* head, int n)
{
	if (head == nullptr)
		return head;

	// Create dummy node to handle edge cases
	Node* dummy = new Node(0);
	dummy->next = head;

	Node* fast = dummy;
	Node* slow = dummy;

	// Move fast pointer N+1 steps ahead
	for (int i = 0; i <= n; i++)
	{
		fast = fast->next;
	}

	// Move both pointers until fast reaches end
	while (fast != nullptr)
	{
		slow = slow->next;
		fast = fast->next;
	}

	// slow is now just before the node to delete
	Node* tobeDelete = slow->next;
	slow->next = slow->next->next;
	delete tobeDelete;

	return dummy->next;
}

// ── INSERT AT END ─────────────────────────────────
void insertEnd(Node*& head, int val)
{
	Node* newNode = new Node(val);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

// ── DISPLAY ───────────────────────────────────────
void display(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << "[" << temp->data << "]";
		if (temp->next != nullptr) cout << " -> ";
		temp = temp->next;
	}
	cout << " -> NULL\n";
}

int main()
{
	Node* head = nullptr;
	int n, val, nth;

	cout << "================================\n";
	cout << "   REMOVE NTH NODE FROM END     \n";
	cout << "     by Bricks (BricksBytes)    \n";
	cout << "================================\n";

	// User Input
	cout << "\nHow many nodes? ";
	cin >> n;
	cout << "Enter " << n << " values:\n";
	for (int i = 0; i < n; i++) {
		cout << "Value " << i + 1 << ": ";
		cin >> val;
		insertEnd(head, val);
	}


	cout << "\nOriginal List: ";
	display(head);

	cout << "\nWhich node to remove from end? ";
	cin >> nth;

	head = removeNthFromEnd(head, nth);

	cout << "\nAfter Removing " << nth << "th node from end: ";
	display(head);

	return 0;
}