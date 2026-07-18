class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i : nums) mp[i]++;
        int mini = INT_MAX,maxi = INT_MIN;
        for(auto& v : mp){
            mini = min(mini,v.first);
            maxi = max(maxi,v.first);
        }
        for(int i = mini + 1;i < maxi;i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};