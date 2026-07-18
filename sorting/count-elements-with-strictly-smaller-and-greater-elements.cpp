class Solution {
public:
    int countElements(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        if(s.size() == 1) return 0; 
        int mini = INT_MAX,maxi = INT_MIN;//min and max cannot be counted
        for(int i : nums){
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        int c1 = 0,c2 = 0;
        for(int i : nums){
            if(i == mini) c1++;//count of min is repeating
            if(i == maxi) c2++;//count of max is repeating
        }
        return (nums.size() - (c1 + c2));//now size of nums - count of(min+max)
    }
};