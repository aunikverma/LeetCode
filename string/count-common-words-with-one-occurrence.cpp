class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mp1;
        for (auto w : words1) {
            mp[w]++;
        }
        for (auto w : words2) {
            mp1[w]++;
        }
        int count = 0;
        for (auto& v : mp) {
            if (v.second == 1 && mp1.find(v.first) != mp1.end() &&
                mp1[v.first] == 1) {
                count++;
            }
        }
        return count;
    }
};