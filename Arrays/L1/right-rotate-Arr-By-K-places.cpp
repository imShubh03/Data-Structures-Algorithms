#include <bits/stdc++.h>
using namespace std;

/*TC:O(n) SC:O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // [1, 2, 3, 4, 5] k = 3; n= 5
        // [3, 4, 5, 1, 2]
        int n = nums.size();
        vector<int>temp(n);
        k = k % n;

        for(int i =0; i<k; i++){
            temp[i] = nums[n - k + i];
        }

        for(int i = k; i < n; i++){
            temp[i] = nums[i-k];
        }

        nums = temp;
    }
};
*/

// TC:O(n) SC:O(1)
class Solution{
    public:
    void reverse(int arr[], int s, int e){
        while(s<e){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }

    void rotate(int arr[], int n, int k){
        k = k % n;

        reverse(arr, 0, n-1);
        reverse(arr, 0, k-1);
        reverse(arr, k, n-1);

        // print arr
        for(int i =0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }
};


int main() {
    int n;
    cin>>n;

    int arr[n];

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    Solution sol;
    sol.rotate(arr, n, k);

    return 0;
}