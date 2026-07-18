class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> arr(101, 0);
        for (int i : nums) {
            arr[i] += 1;
        }
        int sum = 0;
        for (int i = 0; i < 101; i++) {
            if (arr[i] == 1) {
                sum += i;
            }
        }
        return sum;
    }
};