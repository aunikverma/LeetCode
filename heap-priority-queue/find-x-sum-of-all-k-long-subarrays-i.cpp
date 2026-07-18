class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans(nums.size() - k + 1); // size given
        if (k == x) {
            for (int i = 0; i < ans.size(); i++) {
                int s = accumulate(nums.begin() + i, nums.begin() + i + k, 0);
                ans[i] = s;
            }
            return ans;
        }
        for (int i = 0; i < ans.size(); i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
            for (auto& v : mp) {
                if (pq.empty() || pq.size() < x) {
                    pq.push({v.second, v.first});
                } else if (v.second > pq.top().first) {
                    pq.pop();
                    pq.push({v.second, v.first});
                } else if (v.second == pq.top().first) {
                    if (v.first > pq.top().second) {
                        pq.pop();
                        pq.push({v.second, v.first});
                    }
                }
            }
            int s = 0;
            while (!pq.empty()) {
                s += pq.top().second * pq.top().first;
                pq.pop();
            }
            ans[i] = s;
        }
        return ans;
    }
};