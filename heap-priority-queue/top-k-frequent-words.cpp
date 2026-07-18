class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans; // just use min heap and freq in negative
        unordered_map<string, int> mp;
        for (auto i : words) {
            mp[i]--;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       greater<pair<int, string>>>
            pq;
        for (auto& v : mp) {
            cout << v.first << " " << v.second << endl;
            pq.push({v.second, v.first});
        }
        while (!pq.empty() && k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};