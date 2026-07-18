class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        vector<int>runsum(arr.size());
        partial_sum(begin(arr),end(arr),begin(runsum));
        for(int i = 0;i < arr.size();i++)
        {
            int k = i*(i+1) / 2;
            if(runsum[i] == k)
            {
                ans++;
            }
        }
        return ans;
    }
};