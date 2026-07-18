class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int c = arr[1] - arr[0];
        for (int i = 0; i + 1 < arr.size(); i++) {
            if (arr[i] + c !=
                arr[i + 1]) // if no plus difference not equals to next in ap
            {
                return false;
            }
        }
        return true;
    }
};