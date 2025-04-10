#include<bits/stdc++.h>
using namespace std;

/* TC:O(n) SC:O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long power = n;

        if(power < 0) {
            power = -power;
            x = 1.0 / x;
        }

        for(long long i = 0; i < power; i++) {
            result = result * x;
        }

        return result;
    }
};
*/


//TC:O(log n) SC:O(1)
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long pow = n;
        if (pow < 0) {
            pow = -pow;
        }

        while (pow) {

            if (pow % 2 == 0) {
                x = x * x;
                pow = pow / 2;
            } else {
                ans = ans * x;
                pow = pow - 1;
            }
        }
        if (n < 0) {
            ans = (double)(1.0) / (double)(ans);
        }

        return ans;
    }
};

int main() {
    double x;
    int n;
    cin >> x >> n;
    Solution sol;
    cout << sol.myPow(x, n) << endl;
    return 0;
}
