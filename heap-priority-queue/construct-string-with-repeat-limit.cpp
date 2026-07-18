class Solution {
public:
    string repeatLimitedString(string s, int r) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;                        // char : freq
        priority_queue<pair<char, int>> pq; // lexixographically bigger
        for (auto& v : mp)
            pq.push({v.first, v.second}); // char : freq(decreasing order)
        string ans = "";
        while (!pq.empty()) {
            auto [ch, a] = pq.top();
            pq.pop();
            int count = min(r, a);    // repeat limit
            ans += string(count, ch); // to repeat char n times
            if (a - count > 0) {
                if (pq.empty())
                    break; // no smaller char to break repetition
                auto [ch1, b] = pq.top();
                pq.pop();
                ans += ch1; // use one occurrence of next char
                if (b - 1 > 0) {
                    pq.push({ch1, b - 1});
                }
                pq.push({ch, a - count});
            }
        }
        return ans;
    }
};