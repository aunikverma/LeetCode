class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mineven = INT_MAX;
        int minodd = INT_MAX;
        int odd = 0, even = 0;

        for (int i : nums1) {
            if (i & 1) {
                minodd = min(minodd, i);
                odd += 1;
            } else {
                mineven = min(mineven, i);
                even += 1;
            }
        }
        return (minodd < mineven || odd == n || even == n);
    }
};
// all even not possible
// since to make smallest odd there is no less odd available
// all odd
// min even must be subtracted with odd which is lesser
// such that subtact is >= 1