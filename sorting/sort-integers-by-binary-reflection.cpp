class Solution {
private:
    int convert(int n) {
        int ans = 0;
        while (n > 0) {
            ans <<= 1;
            ans += n % 2;
            n /= 2;
        }
        return ans;
    }

public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (int i : nums) {
            int a = convert(i);
            arr.push_back({a, i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto& i : arr) {
            ans.push_back(i.second);
        }
        return ans;
    }
};