class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int push = 1;
        int count = 0;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] != '1' && word[i] != '*' && word[i] != '#' &&
                word[i] != '0') {
                count += 1;
            }
            ans += push;
            if (count % 8 == 0) {
                count = 0;
                push += 1;
            }
        }
        return ans;
    }
};