#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp->data == k) {
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            
            if (temp == head) {
                // Update head if the node to delete is the head
                head = nextNode;
            }
            
            if (nextNode != nullptr) nextNode->prev = prevNode;
            if (prevNode != nullptr) prevNode->next = nextNode;

            // Delete the node
            delete temp;
            
            // Move temp to the next node
            temp = nextNode;
        } else {
            // Move to the next node
            temp = temp->next;
        }
    }
    
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert a new node at the end of the linked list
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int main() {
    Node* head = nullptr;

    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 2);
    insertEnd(head, 4);
    insertEnd(head, 2);

    cout << "Original List: ";
    printList(head);

    // Delete all occurrences of 2
    head = deleteAllOccurrences(head, 2);

    cout << "List after deleting all occurrences of 2"<<endl;
    printList(head);

    return 0;
}
