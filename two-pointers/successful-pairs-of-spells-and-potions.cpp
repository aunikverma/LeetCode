class Solution {
private:
    int bin(vector<int>& arr, int k, long long out) {
        int res = -1;
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] >= (out + k - 1) / k) {
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        if (res != -1) {
            return (arr.size() - res);
        }
        return 0;
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (int i : spells) {
            int r = bin(potions, i, success);
            ans.push_back(r);
        }
        return ans;
    }
};