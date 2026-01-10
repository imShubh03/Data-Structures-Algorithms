#include <bits/stdc++.h>
using namespace std;

/* TC:O(n)+O(n) SC=O(1)
pair<int, int> findFirstAndLastOccurrence(vector<int> &arr, int target) {
    int first = -1, last = -1;

    // First pass: Find the first occurrence
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            first = i;
            break;
        }
    }

    // Second pass: Find the last occurrence
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] == target) {
            last = i;
            break;
        }
    }

    return {first, last};
}
*/

/* TC:O(n) SC:O(1)
pair<int, int> findFirstAndLastOccurrence(vector<int> &arr, int target) {
    int first = -1, last = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
}
*/

int firstmost(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2; // To avoid overflow
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int lastocc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2; // To avoid overflow
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[6] = {1, 3, 3, 3, 4, 7};

    int first = firstmost(arr, 6, 3);
    int last = lastocc(arr, 6, 3);
    cout << "First occurrence of 3 is at index: " << first << endl;
    cout << "Last occurrence of 3 is at index: " << last << endl;
    return 0;
}
