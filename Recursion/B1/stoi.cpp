#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        long long number = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i == n) return 0;

        // Handle sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // Convert digits
        while (i < n && isdigit(s[i])) {
            number = number * 10 + (s[i] - '0');

            // Clamp to bounds
            if (sign * number >= INT_MAX) return INT_MAX;
            if (sign * number <= INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * number);
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution sol;
    int ans = sol.myAtoi(s);
    cout << ans;

    return 0;
}
