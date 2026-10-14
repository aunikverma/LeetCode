class Solution {
private:
    vector<int> nextsmaller(vector<int> arr, int n) {
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i]; // curr index
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i); // curr index
        }
        return ans;
    }
    vector<int> prevsmaller(vector<int> arr, int n) {
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++) {
            int curr = arr[i]; // curr index
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i); // curr index
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n, 0);
        vector<int> prev(n, 0);
        next = nextsmaller(heights, n);
        prev = prevsmaller(heights, n);
        int maxarea = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i]; // lenght
            if (next[i] == -1) {
                next[i] = n; // if all elements are same
            }
            int b = (next[i] - prev[i] - 1); // breadth
            int area = l * b;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};