class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // first sort the array
        sort(arr.begin(), arr.end());

        // since first element will always be 1
        int maxi = 1;
        // we already make first to 1 if not
        int prev = 1;
        int curr = 0;
        for (int i = 1; i < arr.size(); i++) {
            curr = arr[i];
            if (abs(curr - prev) <= 1) {
                maxi = max(maxi, curr);
                prev = curr;
                continue;
            } else {
                curr = prev + 1;
                prev = curr;
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }
};