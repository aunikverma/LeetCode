class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        // lambda function
        auto msb = [&](int i) {
            int count = 0;
            while (i > 0) {
                count++;
                i >>= 1;
            }
            return count;
        };
        return (1 << msb(n));
    }
};