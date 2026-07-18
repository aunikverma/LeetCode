class Solution {
public:
    typedef long long ll;

    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n, 0);
        unordered_map<int, ll> indexSum;
        unordered_map<int, ll> indexCount;

        // left to right
        for (int i = 0; i < n; i++) {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            ans[i] += (freq * i) - sum;
            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        indexSum.clear();
        indexCount.clear();
        // right to left
        for (int i = n - 1; i >= 0; i--) {
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            ans[i] += sum - (freq * i);
            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        return ans;
    }
};