class Solution {
private:
    vector<int> nextsmaller(int arr[], int n) {
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevsmaller(int arr[], int n) {
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
    int largestRectangleArea(int heights[], int n) {
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
    // same like largest in histogram
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int heights[m];
        for (int j = 0; j < m; j++) {
            heights[j] = matrix[0][j] - '0'; // since it is in char
        }
        int area = largestRectangleArea(heights, m);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            area = max(area, largestRectangleArea(heights, m));
        }
        return area;
    }
};