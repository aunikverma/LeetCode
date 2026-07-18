class Solution {
public:
    double average(vector<int>& s) {
        int n = s.size() - 2;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        double sum = 0;
        for(int i : s)
        {
            maxi = max(maxi,i);
            mini = min(mini,i);
            sum += i;
        }
        sum -= (maxi+mini);
        return sum / (double)n;
    }
};