class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            int max_element = pq.top();
            pq.pop();
            ans += max_element;
            int new_val = ceil((double)max_element / 3.0);
            pq.push(new_val);
        }
        return ans;
    }
};
//since for max score it is always better to chose the max element