class Solution {
public:
    vector<string> findRestaurant(vector<string>& arr1, vector<string>& arr2) {
        vector<string> ans;
        vector<pair<int, string>> pq;
        unordered_map<string, int> mp;
        int c = INT_MAX;
        for (int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]] = i; // stored index of 1st array
        }
        for (int i = 0; i < arr2.size(); i++) {
            if (mp.find(arr2[i]) != mp.end()) {
                pq.push_back({i + mp[arr2[i]], arr2[i]});
                c = min(c, i + mp[arr2[i]]);
            }
        }

        for (auto& v : pq) {
            if (v.first == c) {
                ans.push_back(v.second);
            }
        }

        return ans;
    }
};