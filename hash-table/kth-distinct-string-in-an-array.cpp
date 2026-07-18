class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto w : arr) {
            mp[w]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (mp[arr[i]] == 1 && k == 1) {
                return arr[i];
            } else if (mp[arr[i]] == 1) {
                k -= 1;
            }
        }
        return "";
    }
};