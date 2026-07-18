class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.size() < 2) return barcodes; //if size less than 2
        unordered_map<int, int> mp;
        for (int i : barcodes) mp[i]++; //getting freq
        priority_queue<pair<int, int>> pq;
        for (auto& v : mp) pq.push({v.second, v.first}); // freq : no
        vector<int> ans;
        while (pq.size() >= 2) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans.push_back(a.second);
            ans.push_back(b.second);
            a.first -= 1;
            b.first -= 1;
            if (a.first > 0) pq.push(a); //if any freq left
            if (b.first > 0) pq.push(b);
        }
        if (!pq.empty()) ans.push_back(pq.top().second); //according to ques ans will exist 
        return ans; //then if any left then add to ans
    }
};