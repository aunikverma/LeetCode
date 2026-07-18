class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int skip = n / 20;//5% is (1/20)
        sort(arr.begin(),arr.end());
        double ans = accumulate(arr.begin()+skip,arr.begin()+n-skip,0);//start from skip to n-skip
        ans = ans/(double) (n - skip*2);//n - skip*2(for 5 on both sides)
        return ans;
    }
};