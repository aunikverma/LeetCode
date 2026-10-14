class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         int sum=0;
        unordered_map<int,int>m;
         m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)
            {
                rem+=k;
            }
            if(m.find(rem)!=m.end())
            {
                 if((i-m[rem]) > 1)
                 {
                    return true;
                 }

            }
            else
            {
               m[rem]=i;
            }
                
            
        }
        return false;
    }
};