#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        this -> val = x;
        this -> next = NULL;
    }
};

/*
// Brute Force (using a visited set)
// Example implementation:
//
// class SolutionBrute {
// public:
//     bool hasCycle(ListNode* head) {
//         unordered_set<ListNode*> seen;
//         ListNode* cur = head;
//         while (cur != nullptr) {
//             if (seen.count(cur)) return true;
//             seen.insert(cur);
//             cur = cur->next;
//         }
//         return false;
//     }
// };
*/

class Solution {
public:
    // Function to detect cycle in a linked list
    bool hasCycle(ListNode* head) {
        // Using tortoise and hare approach
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    // Function to insert a node at the head of the linked list
    ListNode* insertAtHead(ListNode* head, int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        return newNode;
    }
};

int main() {
    Solution sol;
    ListNode* head = nullptr;

    // Inserting elements at the head of the linked list
    head = sol.insertAtHead(head, 5);
    head = sol.insertAtHead(head, 4);
    head = sol.insertAtHead(head, 3);
    head = sol.insertAtHead(head, 2);
    head = sol.insertAtHead(head, 1);

    // Creating a cycle for demonstration purposes
    // Connect the last node to the second node
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head->next;

    // Checking if there's a cycle
    if (sol.hasCycle(head)) {
        cout << "Linked List contains a cycle.\n";
    } else {
        cout << "Linked List doesn't contain a cycle.\n";
    }

    return 0;
}
