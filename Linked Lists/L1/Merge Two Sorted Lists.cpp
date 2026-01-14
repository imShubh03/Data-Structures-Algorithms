#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* brute: TC:O(n1) + O(n2) + O(n logn) + O(n) SC:O(n)+O(n)
class Solution {
public:
    ListNode* convertToArr(const vector<int>& arr){
        if(arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(size_t i = 1; i < arr.size(); ++i){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        vector<int> arr;
        for (ListNode* t = list1; t; t = t->next) arr.push_back(t->val);
        for (ListNode* t = list2; t; t = t->next) arr.push_back(t->val);
        sort(arr.begin(), arr.end());
        return convertToArr(arr);
    }
};
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(t1 != nullptr && t2 != nullptr){
            if(t1 -> val < t2 -> val){
                temp -> next = t1;
                temp = temp -> next;
                t1 = t1 -> next;
            }
            else{
                temp -> next = t2;
                temp = temp -> next;
                t2 = t2 -> next;
            }
        }

        if(t1 != nullptr) 
            temp -> next = t1;
        else 
            temp -> next = t2;

        return dummyNode -> next;
    }
};

static void printList(ListNode* head){
    for (ListNode* cur = head; cur; cur = cur->next){
        cout << cur->val;
        if (cur->next) cout << " -> ";
    }
    cout << '\n';
}

int main(){
    Solution sol;
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};

    ListNode* l1 = sol.convertToArr(a);
    ListNode* l2 = sol.convertToArr(b);

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    ListNode* merged = sol.mergeTwoLists(l1, l2);
    cout << "Merged: "; printList(merged);

    return 0;
}