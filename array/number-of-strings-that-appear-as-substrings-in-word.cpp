class Solution {
public:
    int numOfStrings(vector<string>& patterns, string w) {
        int c = 0;//count of words in patterns
        for (auto& v : patterns) {//if exists then increment count
            if (w.find(v) != -1) {
                c++;
            }
        }
        return c;
    }
};