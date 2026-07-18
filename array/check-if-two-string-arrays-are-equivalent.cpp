class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";
        for(auto &v : word1)
        {
            a += v;
        }
        for(auto &v : word2)
        {
            b += v;
        }
        return (a == b);
    }
};