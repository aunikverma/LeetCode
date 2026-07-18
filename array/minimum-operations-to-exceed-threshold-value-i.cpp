class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a = 0;
        for(int i : nums)
        {
            if(i >= k)
            {
                a++;
            }
        }
        return (nums.size() - a);
    }
};