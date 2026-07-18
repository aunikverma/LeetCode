class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> p; // even
        priority_queue<int> q; // odd
        string s = to_string(num);
        for (char c : s) {
            int a = c - '0';
            (a % 2 == 0) ? p.push(a) : q.push(a);
        }
        int ans = 0;
        for (char c : s) {
            int a = c - '0';
            if (a % 2 == 0) {
                ans = ans * 10 + p.top();
                p.pop();
            } else {
                ans = ans * 10 + q.top();
                q.pop();
            }
        }
        return ans;
    }
};