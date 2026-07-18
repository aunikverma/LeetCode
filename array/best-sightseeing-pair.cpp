class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n = v.size();
        if(n == 2) return (v[0]+v[1] - 1);//base case
        int dp = v[0],score = 0;
        for(int i = 1;i < n;i++)
        {
            score = max(score,dp + v[i] - i);//get max score
            dp = max(dp, v[i] + i);//+i for max value
        }
        return score;
    }
};