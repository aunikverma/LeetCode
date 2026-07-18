class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> s(jewels.begin(), jewels.end());
        int a = 0;
        for (char c : stones) {
            if (s.find(c) != s.end()) {
                a++;
            }
        }
        return a;
    }
};