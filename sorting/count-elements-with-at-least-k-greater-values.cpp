class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        // base case
        if (k == 0) {
            return nums.size();
        }
        // frequency
        map<int, int> freq;
        for (int i : nums) {
            freq[i] += 1;
        }
        // now int - (no of elements greater)
        unordered_map<int, int> greater;
        int count = 0;
        for (auto i = freq.rbegin(); i != freq.rend(); i++) {
            greater[i->first] = count;
            count += i->second;
        }
        // now count ans
        int ans = 0;
        for (int i : nums) {
            if (greater[i] >= k) {
                ans += 1;
            }
        }
        return ans;
    }
};