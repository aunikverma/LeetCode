class Solution {
public:

    void FloydWarshall(vector<vector<long long>>& adj,vector<char>& original,vector<char>& changed,vector<int>& cost){
        //populating adj
        for(int i = 0;i < original.size();i++){
            int s = original[i] - 'a',t = changed[i] - 'a';
            adj[s][t] = min(adj[s][t],(long long)cost[i]);
        }
        //floydwarshall algorithm
        for(int k = 0;k < 26;k++){
            for(int i = 0;i < 26;i++){
                for(int j = 0;j < 26;j++){
                    if(adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original,vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26,vector <long long>(26, LLONG_MAX));
        // FloydWarshall
        FloydWarshall(adj, original, changed, cost);
        // now ans(min cost)
        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            // src and target
            int s = source[i] - 'a', t = target[i] - 'a';
            if (s == t) {
                continue;
            }
            if (adj[s][t] == LLONG_MAX) {
                return -1;
            } else {
                ans += adj[s][t];
            }
        }
        return ans;
    }
};