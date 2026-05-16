#include <iostream>
using namespace std;

// ── NODE STRUCTURE ────────────────────────────────
struct Node {
    int data;
    Node* next;

    Node(int val) :data(val), next(nullptr) {};   
};

// ── LINKED LIST CLASS ─────────────────────────────
class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // INSERT at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << val << " inserted at end!\n";
    }

    // INSERT at beginning
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at beginning!\n";
    }

    // DELETE a value
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == val) {
            head = head->next;
            cout << val << " deleted!\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == val) {
                temp->next = temp->next->next;
                cout << val << " deleted!\n";
                return;
            }
            temp = temp->next;
        }
        cout << val << " not found!\n";
    }

    // SEARCH a value
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << val << " found at position " << pos << "!\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << val << " not found!\n";
    }

    // DISPLAY the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << "[" << temp->data << "]";
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    // SIZE of list
    void size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Size: " << count << "\n";
    }
};

// ── MAIN ──────────────────────────────────────────
//int main() {
//    LinkedList ll;
//    int choice, val;
//
//    cout << "================================\n";
//    cout << "   DSA CLI TOOL — LINKED LIST   \n";
//    cout << "       by Bricks (BricksBytes)  \n";
//    cout << "================================\n";
//
//    while (true) {
//        cout << "\n--- MENU ---\n";
//        cout << "1. Insert at End\n";
//        cout << "2. Insert at Beginning\n";
//        cout << "3. Delete Node\n";
//        cout << "4. Search Node\n";
//        cout << "5. Display List\n";
//        cout << "6. Size of List\n";
//        cout << "0. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter value: ";
//            cin >> val;
//            ll.insertEnd(val);
//            ll.display();
//            break;
//        case 2:
//            cout << "Enter value: ";
//            cin >> val;
//            ll.insertBegin(val);
//            ll.display();
//            break;
//        case 3:
//            cout << "Enter value to delete: ";
//            cin >> val;
//            ll.deleteNode(val);
//            ll.display();
//            break;
//        case 4:
//            cout << "Enter value to search: ";
//            cin >> val;
//            ll.search(val);
//            break;
//        case 5:
//            ll.display();
//            break;
//        case 6:
//            ll.size();
//            break;
//        case 0:
//            cout << "Goodbye Bricks! Keep Coding!\n";
//            return 0;
//        default:
//            cout << "Invalid choice!\n";
//        }
//    }
//    return 0;
//}