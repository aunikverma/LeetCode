class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int, int> mp; // row no = no of ones
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) count++;
            }
            mp[i] = count; //storing count of one according to row index
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq; //min heap
        for (auto& v : mp) {
            pq.push({v.second, v.first}); //storing frequency and row no
        }
        vector<int> ans;
        while (k > 0) { //adding first k rows index
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans; //ans
    }
};