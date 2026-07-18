class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        if (a == b) {
            return a;
        }
        return gcd(b, a % b);
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd;
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd.push_back(gcd(maxi, nums[i]));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int maxi = max(prefixGcd[i], prefixGcd[j]);
            int mini = min(prefixGcd[i], prefixGcd[j]);
            ans += gcd(maxi, mini);
            i++;
            j--;
        }
        return ans;
    }
};