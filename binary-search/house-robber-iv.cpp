class Solution {
public:
    bool capability(int mid, vector<int>& nums, int& k) {
        int count = 0;
        // if capabaility is less or equal we can and move to i + 2
        // if not i + 1
        // max no of valid houses >= k
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                count++;
                i += 1;
            }
        }
        // it works greedily because for valid mid
        //  It is always possible to steal at least k houses.(given)
        return (count >= k);
    }

    int minCapability(vector<int>& nums, int k) {
        int l = INT_MAX, r = INT_MIN;
        for (int i : nums) {
            l = min(i, l);
            r = max(i, r);
        }
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (capability(mid, nums, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};