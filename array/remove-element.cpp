class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = 0;
        while(s <= e)
        {
            if(nums[s] == val && nums[e] != val)//when nums[s] == val and last value not matches to it then,swap
            {
                swap(nums[s],nums[e]);
                s++;
                e--;
                ans++;//ans++ because now value is placed
            }
            else if(nums[s] == val && nums[e] == val)
            {
                e--;//when first and last are equal decrease e
            }
            else if(nums[s] != val)
            {
                s++;
                ans++;//when nums[s] not equal to val then ans++;
            }
        }
        return ans;
    }
};