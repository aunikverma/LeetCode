class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++; // creating map for storing frequency of every character
        }
        vector<pair<int, char>> vec;
        for (auto& v : mp) { // storing frequency and character in pair
            vec.push_back({v.second, v.first});
        }
        sort(vec.rbegin(),vec.rend()); // sorting according to frequency decreasing order
        for (int i = 0; i < vec.size(); i++) {
            ans.append(vec[i].first,vec[i].second); // adding the characters nth time(frequecny)
        }
        return ans;
    }
};