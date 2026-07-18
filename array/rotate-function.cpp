class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int f_prev = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            f_prev += i * nums[i];
            sum += nums[i];
        }
        int ans = f_prev;
        for (int i = n - 1; i >= 1; i--) {
            int f_curr = f_prev + sum - (n * nums[i]);
            ans = max(f_curr, ans);
            f_prev = f_curr;
        }
        return ans;
    }
};
// on f_curr every no is multiplied ind + 1, then every no increased once, therefore sum of arr
// no which is moved from n - 1 to 0 therefore it should be subtracted (6 * (n - 1))
// since in sum it is added by once also therefore it should be subtracted once more
// therefore the no which is moved to first must be subtracted (n times)
// hence we hace the relation
// f_curr = f_prev + sum(nums) - n * (no which was moved to front)
