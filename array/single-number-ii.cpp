class Solution {

public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();

        int result = 0;

        for (int i = 0; i < 32; i++) {

            int ones = 0, zeros = 0;

            for (int j = 0; j < n; j++) {
                if ((nums[j] >> i) & 1) {

                    ones += 1;

                } else {

                    zeros += 1;
                }
            }

            if (ones % 3 == 1) {

                result = (result | (1 << i));
            }
        }

        return result;
    }
};