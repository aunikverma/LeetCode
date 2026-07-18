class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int maxInc = 1,maxDec = 1,inc = 1,dec = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                inc++;
                maxInc = max(maxInc, inc);
            } else {
                inc = 1; // Reset increasing sequence length
            }

            if (arr[i] < arr[i - 1]) {
                dec++;
                maxDec = max(maxDec, dec);
            } else {
                dec = 1; // Reset decreasing sequence length
            }
        }
        return max(maxInc,maxDec);
    }
};