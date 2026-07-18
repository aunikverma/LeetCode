class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = 0;
        int win = 0;
        for (int i = 0; i < k; i++) {
            win += nums[i];
        }
        ans = win;
        for (int i = k; i < nums.size(); i++) {
            win = win + nums[i] - nums[i - k];
            ans = max(win,ans);
        }
        double res = (double)ans / (double)k;
        return res;
    }
};