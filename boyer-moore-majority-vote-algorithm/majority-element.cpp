class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int f = 0,ans = 0;
        for(int i : nums)
        {
            if(f == 0)
            {
                ans = i;
            }
            if(ans == i)
            {
                f += 1;
            }
            else
            {
                f -= 1;
            }
        }
        return ans;
    }
};