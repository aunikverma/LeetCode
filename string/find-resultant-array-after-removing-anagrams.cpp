class Solution {
private:
    bool check(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return (a == b);
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        int i = 1;
        while (i < words.size()) {
            string s = ans[ans.size() - 1];
            while (i < words.size() && check(s, words[i])) {
                i++;
            }
            if (i < words.size()) {
                ans.push_back(words[i]);
                i++;
            }
        }
        return ans;
    }
};