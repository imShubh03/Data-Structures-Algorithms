#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        data = d;
        next = nullptr;
        prev = nullptr;
    }

    Node(int d, Node* nextNode, Node* prevNode){
        data = d;
        next = nextNode;
        prev = prevNode;
    }
};

class Solution{
    public:
    Node* convertArr2DLL(vector<int>&arr){
        if (arr.empty()) return nullptr;
        Node* head = new Node(arr[0]);
        Node* prevNode = head;
        for (int i = 1; i < (int)arr.size(); ++i) {
            Node* temp = new Node(arr[i]);
            prevNode->next = temp;
            temp->prev = prevNode;
            prevNode = temp;
        }
        return head;
    }

    //printing the LL
    void printDLL(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    //insert at head
    Node* insertAtHead(Node* head, int val){
        Node* newHead = new Node(val);
        newHead->next = head;
        if (head != nullptr) head->prev = newHead;
        return newHead;
    }

    Node* insertAtTail(Node* head, int val){
        //base case
        if(head == nullptr){
            return new Node(val);
        }

        Node* temp = head;

        while(temp->next != nullptr){
            temp = temp -> next;
        }
        //at this we have temp at last node
        Node* newNode = new Node(val,nullptr,temp);
        temp -> next = newNode;
        return head;
    }

    Node* insertBeforeTail(Node* head, int val){
        //base case
        if (head == nullptr) {
        return new Node(val);
        }

        Node* temp = head;

        // Traverse to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // At this point, temp is the last node. We need to insert before this.
        Node* back = temp->prev;

        // If the list has only one node, insert before the head node
        if (back == nullptr) {
            Node* newNode = new Node(val, temp, nullptr);
            temp->prev = newNode;
            head = newNode;
        } else {
            Node* newNode = new Node(val, temp, back);
            back->next = newNode;
            temp->prev = newNode;
        }

        return head;
    }

    Node* insertBeforeKth(Node* head, int k, int val){
        if(k==1){
            return insertAtHead(head,val);
        }
        Node* temp = head;
        int cnt =0;
        while(temp!=nullptr){
            cnt++;
            if(cnt == k) break;
            temp = temp -> next;
        }
        Node* back = temp -> prev;
        Node* newNode = new Node(val,temp,back);
        back -> next = newNode;
        temp -> prev = newNode;
        return head;
    }

    //insert before given val
    Node* insertBeforeVal(Node* head, int newVal, int val){
         // If the list is empty, create a new node and return it as the head
        if (head == nullptr) {
            return new Node(newVal);
        }

        Node* temp = head;

        // Traverse the list to find the first node with the target value
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        // If the target is found and it's the head node
        //dont inser at head bcoz it changes the head

        // If the target is found and it's not the head node
        Node* back = temp->prev;
        Node* newNode = new Node(newVal, temp, back);
        back->next = newNode;
        temp->prev = newNode;

        return head;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {12, 2, 4, 5, 8, 4, 15, 21};
    cout<<"the original DLL..."<<endl;
    Node* head = sol.convertArr2DLL(arr);
    sol.printDLL(head);

    // Insert at head
    cout << "Inserting at the head..." << endl;
    head = sol.insertAtHead(head, 100);
    sol.printDLL(head);

    // Insert at tail
    cout << "Inserting at the tail..." << endl;
    head = sol.insertAtTail(head, 300);
    sol.printDLL(head);

    // Insert at kth position
    int k;
    cout << "Enter the position to insert: " << endl;
    cin >> k;
    cout << "Inserting at " << k << " position..." << endl;
    head = sol.insertBeforeKth(head, k, 250);
    sol.printDLL(head);

    // Insert an element/newVal before the given value in LL
    int newVal, ele;
    cout << "Enter the new value to insert..." << endl;
    cin >> newVal;
    cout << "Enter the element in LL before which it has to be inserted..." << endl;
    cin >> ele;
    cout << "Inserting " << newVal << " before " << ele << endl;
    head = sol.insertBeforeVal(head, newVal, ele);
    sol.printDLL(head);


    return 0;
}