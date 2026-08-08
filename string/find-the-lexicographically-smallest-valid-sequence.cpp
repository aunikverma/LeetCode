class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> RightHandSideMatched(n, 0);

        int rightMatched = 0;
        int i = n - 1;
        int j = m - 1;

        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatched += 1;
                j--;
            }
            RightHandSideMatched[i] = rightMatched;
            i--;
        }

        vector<int> seq;
        bool change = true;

        i = 0;
        j = 0;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if (change && i + 1 < n &&
                       RightHandSideMatched[i + 1] >= m - j - 1) {
                seq.push_back(i);
                j++;
                change = false;
            }
            i++;
        }
        if (j == m) {
            return seq;
        }
        return {};
    }
};