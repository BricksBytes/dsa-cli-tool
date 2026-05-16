#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr){}
};

bool DetectCylcle(Node* head)
{
	if (head == nullptr)
		return head;

	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}
	return false;
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

//int main()
//{
//	// Create list: 1->2->3->4->5
//	Node* head = new Node(1);
//	head->next = new Node(2);
//	head->next->next = new Node(3);
//	head->next->next->next = new Node(4);
//	head->next->next->next->next = new Node(5);
//
//	// Create cyycle : 5 points back to 3
//	head->next->next->next->next->next = head->next->next;
//
//	std::cout << "with Cycle: ";
//	if (DetectCylcle(head))
//		std::cout << "Cycle Dtected! \n";
//	else
//		std::cout << "NO Cycle!\n";
//
//	// Remove cycle for testing
//	head->next->next->next->next->next = nullptr;
//
//	std::cout << "Without Cycle: ";
//	if (DetectCylcle(head))
//		std::cout << "Cycle DETECTED!\n";
//	else
//		std::cout << "No Cycle! \n";
//
//	return 0;
//}