#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor to initialize node with given data
    Node (int d){
        data = d;
        next = nullptr;
    }
};

class Solution{
    public:
    Node* convertArr2LL(vector<int>&arr){
        int n = arr.size();
        if (n == 0) return nullptr;
        Node* head = new Node(arr[0]);
        Node* mover = head;

        for(int i =1;i<n;i++){
            Node* temp = new Node(arr[i]);
            mover -> next = temp;
            //update mover
            mover = mover -> next;
        }
        return head;
    }

    void print(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    //length of LL
    int lengthOFLL(Node* head){
        int count=0;
        Node* temp = head;
        while(temp!=nullptr){
            count++;
            temp = temp -> next;
        }
        return count;
    }

    //search ele in LL
    bool isPresent(Node* head, int target){
        Node* temp = head;
        while(temp!=nullptr){
            if(temp -> data == target) return true;
            temp = temp -> next;
        }
        return false;
    }
};

int main() {
    vector<int>arr ={12,2,4,5,8};
    Solution sol;
    Node* head = sol.convertArr2LL(arr);
    cout<<"the first of LL is "<< head ->data<<endl;

    
    cout<<"print the entire LL "<<endl;
    sol.print(head);

    int len = sol.lengthOFLL(head);
    cout<<"length of LL is "<<len<<endl;
    
    int target=9;
    bool ans= sol.isPresent(head,target);
    cout<<target <<" is present in LL ? "<<(ans?"Yes":"No")<<endl;

    return 0;
}
