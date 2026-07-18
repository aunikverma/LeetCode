class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        vector<pair<int,int>>freq;//frequency no pair vector
        for(auto &v : mp)
        {
            freq.push_back({v.first,v.second});
        }
        sort(freq.begin(),freq.end(),[](const pair<int,int>& a,const pair<int,int>& b)
        {
            if(a.second == b.second)
            {
                return a.first > b.first;//if frequency is same then see digits
            }
            return a.second < b.second;//other wise frequency
            
        });
        for(auto &v : freq)
        {
            int k = v.second;
            while(k > 0)
            {
                ans.push_back(v.first);
                k--;
            }
        }
        return ans;
    }
};