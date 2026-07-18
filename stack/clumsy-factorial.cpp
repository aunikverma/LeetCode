class Solution {
public:
    int clumsy(int n) {
        stack<int> s;
        int ans = 0;
        s.push(n--);
        int ind = 0;
        while (n > 0) {
            if (ind % 4 == 0) {
                s.top() *= n;//multiply
            } else if (ind % 4 == 1) {
                s.top() /= n;//divide
            } else if (ind % 4 == 2) {
                s.push(n);//add
            } else {
                s.push(-n);//sub
            }
            ind++;
            n--;
        }
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};