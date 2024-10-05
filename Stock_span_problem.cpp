#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to calculate the span of stock prices for all n days.
    vector<int> calculateSpan(int price[], int n) {
        vector<int> span(n);
        stack<int> s; // Stack to store indices of prices

        // Span for the first day is always 1
        span[0] = 1;
        s.push(0); // Push index of the first day

        for (int i = 1; i < n; i++) {
            // Pop indices from the stack while the current price is greater
            // than the price at the index stored at the top of the stack
            while (!s.empty() && price[s.top()] <= price[i]) {
                s.pop();
            }

            // If stack is empty, it means the current price is greater than all previous prices
            // so span is (current index + 1)
            span[i] = (s.empty()) ? (i + 1) : (i - s.top());

            // Push current index onto the stack
            s.push(i);
        }
        return span;
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Number of days
        int price[n];
        for (int i = 0; i < n; i++) {
            cin >> price[i]; // Daily stock prices
        }
        Solution obj;
        vector<int> span = obj.calculateSpan(price, n);

        // Output the calculated spans
        for (int s : span) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
