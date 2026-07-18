class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> ans;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        int j = 0, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                ans.push_back(a[j++]);
            } else {
                ans.push_back(b[k++]);
            }
        }
        return ans;
    }
};