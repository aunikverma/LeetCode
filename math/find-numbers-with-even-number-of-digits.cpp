class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            int a = (int)log10(i) + 1;
            if (a % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};