#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr){}
};

// ── MERGE TWO SORTED LISTS ────────────────────────

Node* mergeSortedLists(Node* l1, Node* l2)
{
	// If either list is empty return the other
	if (l1 == nullptr)return l2;
	if (l2 == nullptr)return l2;

	Node* result = nullptr;

	if (l1->data <= l2->data)
	{
		result = l1;
		result->next = mergeSortedLists(l1->next, l2);
	}
	else
	{
		result = l2;
		result->next = mergeSortedLists(l1, l2->next);
	}
	return result;
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
		temp = temp->next;
	temp->next = newNode;
}


// ── DISPLAY ───────────────────────────────────────
void display(Node* head)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << "[" << temp->data << "]";
		if (temp->next != nullptr) cout << " -> ";
		temp = temp->next;
	}
	cout << " -> NULL\n";
}

int main()
{
	Node* list1 = nullptr;
	Node* list2 = nullptr;
	int n, val;

	std::cout << "================================\n";
	std::cout << "   MERGE TWO SORTED LISTS       \n";
	std::cout << "       by Bricks (BricksBytes)  \n";
	std::cout << "================================\n";

	// Input List 1
	std::cout << "\nHow many nodes in List 1? ";
	std::cin >> n;
	std::cout << "Enter " << n << " sorted values:\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << "Value " << i + 1 << ": ";
		std::cin >> val;
		insertEnd(list1, val);
	}

	// Input List 2
	std::cout << "\nHow many nodes in List 2? ";
	std::cin >> n;
	std::cout << "Enter " << n << " sorted values:\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << "Value " << i + 1 << ": ";
		std::cin >> val;
		insertEnd(list2, val);
	}

	// Display both lists
	std::cout << "\nList_1:";
	display(list1);
	std::cout << "\nList_2: ";
	display(list2);

	// Merge
	Node* merged = mergeSortedLists(list1, list2);

	// Display result
	std::cout << "\nMerged: ";
	display(merged);

	return 0;
}