class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // kadane
        int maxprod = nums[0],minend = nums[0],maxend = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            if(nums[i] < 0) swap(minend,maxend);
            maxend = max(nums[i],nums[i] * maxend);
            minend = min(nums[i],nums[i] * minend);
            maxprod = max(maxprod,maxend);
        }
        return maxprod; //maxproduct
    }
};
// We swap when nums[i] < 0 because negative flips the sign.

// We keep both max and min at each step.

// maxProd stores the overall max.