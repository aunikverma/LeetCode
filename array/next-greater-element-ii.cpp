class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s; // similar like next greater small change for circular
        vector<int> ans(nums.size(), -1); // intializing -1
        int n = nums.size();
        for (int i = (2 * n - 1); i >= 0;i--) { // iterating 2*n times for circulary
            int ind = i % n;
            while (!s.empty() && nums[ind] >= nums[s.top()]) {
                s.pop();
            }
            ans[ind] = s.empty() ? -1 : nums[s.top()]; // if stack is empty then
                                                       // -1 else nums[s.top()]
            s.push(ind);
        }
        return ans;
    }
};