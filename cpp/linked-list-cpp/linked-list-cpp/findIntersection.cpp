#include<iostream>
using namespace std;

//Pointer 1 → travels List 1 then List 2
//Pointer 2 → travels List 2 then List 1
//They will MEET at intersection point!

struct Node
{
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr){}
};

// ── FIND INTERSECTION POINT ───────────────────────

Node* findIntersection(Node* l1, Node* l2)
{
	// If either list is empty no intersection
	if ((l1 == nullptr) || (l2 == nullptr))
		 return nullptr;

	Node* ptr1 = l1;
	Node* ptr2 = l2;

	// Traverse both lists
	while (ptr1 != ptr2)
	{
		// If ptr1 reaches end switch to l2
		ptr1 = (ptr1 == nullptr) ? l2 : ptr1->next;
		// If ptr2 reaches end switch to l1
		ptr2 = (ptr2 == nullptr) ? l1 : ptr2->next;
	}

	// Either intersection node or nullptr
	return ptr1;

}
// ── DISPLAY ───────────────────────────────────────
void display(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << "[" << temp->data << "]";
		if (temp->next != nullptr) std::cout << " -> ";
		temp = temp->next;
	}
    std::cout << " -> NULL\n";
}
// ── MAIN ──────────────────────────────────────────
int main() {
    std::cout << "================================\n";
    std::cout << "   FIND INTERSECTION POINT      \n";
    std::cout << "     by Bricks (BricksBytes)    \n";
    std::cout << "================================\n";

    // Create common part: 8 -> 9
    Node* common = new Node(8);
    common->next = new Node(9);

    // Create List 1: 1 -> 2 -> 8 -> 9
    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = common;

    // Create List 2: 3 -> 4 -> 8 -> 9
    Node* l2 = new Node(3);
    l2->next = new Node(4);
    l2->next->next = common;

    std::cout << "\nList 1: ";
    display(l1);
    std::cout << "List 2: ";
    display(l2);

    // Find intersection
    Node* intersection = findIntersection(l1, l2);

    if (intersection != nullptr)
        std::cout << "\nIntersection Point: "
        << intersection->data << " \n";
    else
        std::cout << "\nNo Intersection Found!\n";

    return 0;
}