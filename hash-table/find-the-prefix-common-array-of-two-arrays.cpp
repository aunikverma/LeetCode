class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> mp(n + 1, 0);
        int count = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (A[i] == B[i]) {
                mp[A[i]]++;
                mp[B[i]]++;
                count++;
                ans.push_back(count);
                continue;
            }
            if (mp[A[i]] == 0) {
                mp[A[i]]++;
            } else {
                count++;
            }
            if (mp[B[i]] == 0) {
                mp[B[i]]++;
            } else {
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};