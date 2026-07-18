class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        for (auto& e : trust) {
            indegree[e[1]]++;
            outdegree[e[0]]++;
        }
        for (int i = 1; i <= n; i++) { //everybody trusts judge
            if (outdegree[i] == 0 && indegree[i] == n - 1) {
                return i; //judge trust nobody 
            }
        }
        return -1;
    }
};