class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for (int i : arr) {
            mp[i] = 0;
        }
        int prev = 1;
        for (auto& v : mp) {
            v.second = prev;
            prev += 1;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};