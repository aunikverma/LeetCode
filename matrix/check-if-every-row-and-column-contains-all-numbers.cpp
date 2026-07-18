class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        bool rows = true;
        bool column = true;
        unordered_map<int,int>mp;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            mp[i + 1]++;
        for (int i = 0; i < n; i++) {
            unordered_map<int,int>mp1;
            unordered_map<int,int>mp2;
            for (int j = 0; j < n; j++) {
                mp1[matrix[i][j]]++;
                mp2[matrix[j][i]]++;
            }
            if (mp1 != mp || mp2 != mp) return false;
        }
        return true;
    }
};