class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;//taking count 0
        int ans = 0;//ans also 0
        for (char c : s) {
            if (count == 0) {
                ans++;//if count 0 ans++
            }
            if (c == 'L') {
                count++;//when encounter L count++
            } else {
                count--;//else count--
            }
        }
        return ans;
    }
};