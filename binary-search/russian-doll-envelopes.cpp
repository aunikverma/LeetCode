class Solution {
public:
    int lis(int n, vector<int>& arr) {
        if (n == 0) {
            return 0;
        }
        vector<int> ans;
        ans.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] > ans[ans.size() - 1]) {
                ans.push_back(arr[i]);
            } else {
                // find just bada element in ans
                int index =
                    lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     return (a[1] > b[1]);
                 }
                 return (a[0] < b[0]);
             });
        vector<int> heights;
        for (auto& i : envelopes) {
            heights.push_back(i[1]);
        }
        return lis(heights.size(), heights);
    }
};
