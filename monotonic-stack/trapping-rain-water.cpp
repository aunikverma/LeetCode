class Solution {
private:
    vector<int> prevGreater(vector<int>& height) {
        vector<int> ans(height.size(), 0);
        int c = height[0];
        for (int i = 0; i < height.size(); i++) {
            int curr = height[i];
            if (curr >= c) {
                c = curr;
            }
            ans[i] = c;
        }
        return ans;
    }
    vector<int> nextGreater(vector<int>& height) {
        vector<int> ans(height.size(), 0);
        int c = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; i--) {
            int curr = height[i];
            if (curr >= c) {
                c = curr;
            }
            ans[i] = c;
        }
        return ans;
    }

public:
    int trap(vector<int>& height) {
        vector<int> left = prevGreater(height);
        vector<int> right = nextGreater(height);
        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};