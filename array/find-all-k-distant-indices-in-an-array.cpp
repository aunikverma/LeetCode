class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<int> v(n + 1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int s = max(0, i - k);     // start
                int e = min(n, i + k + 1); // end
                v[s]++;
                v[e]--;
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += v[i];
            if (sum)
                ans.push_back(i);
        }
        return ans;
    }
};