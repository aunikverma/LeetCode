class Solution {
private:
    vector<int> solve(vector<int> arr,
                      int n) { // same like next greater element 1
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0;
             i--) { // here i stored the index of next greater
            int curr = arr[i];
            while (s.top() != -1 && curr >= arr[s.top()]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans; // ans return
    }

public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> next = solve(temp, temp.size());
        for (int i = 0; i < temp.size(); i++) {
            if (next[i] == -1) // if next greater is not found then ans = 0
                temp[i] = 0;
            else
                temp[i] =
                    (next[i] - i); // else count of ith day can be given by
                                   // subtracting nextgreater index and i
        }
        return temp;
    }
};