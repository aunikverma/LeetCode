class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        using p = pair<int, int>;                    // using keyword
        priority_queue<p, vector<p>, greater<p>> pq; // creating min heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i}); // pushing element and its index
        }
        vector<bool> arr(nums.size(), true);
        while (!pq.empty()) {
            auto [value, i] = pq.top(); // accessing
            pq.pop();                   // deleting
            if (arr[i] == true) {
                ans += value;
                if (i > 0) {//in range
                    arr[i - 1] = false;
                }
                if (i + 1 < nums.size()) {
                    arr[i + 1] = false;//in range
                }
            }
        }
        return ans;
    }
};