class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 1) {
                int c = i;
                if (i + 2 < arr.size()) {
                    if (arr[c + 1] % 2 == 1 && arr[c + 2] % 2 == 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};