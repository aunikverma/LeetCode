class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, list<int>> adj;
        unordered_map<int, int> indeg;
        unordered_map<int, int> outdeg;
        for (auto& e : pairs) {
            adj[e[0]].push_back(e[1]);
            // update in and out
            outdeg[e[0]]++;
            indeg[e[1]]++;
        }
        // start node find
        int s = pairs[0][0]; // start node
        for (auto& i : adj) {
            int node = i.first;
            if (outdeg[node] - indeg[node] == 1) {
                s = node;
                break;
            }
        }
        vector<int> EulerPath;
        stack<int> st;
        st.push(s);
        while (!st.empty()) {
            int curr = st.top();
            if (!adj[curr].empty()) // until start node neigh not empty
            {
                int neigh = adj[curr].back();
                adj[curr].pop_back();
                st.push(neigh);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }
        for(int i : EulerPath) cout << i << " ";
        // build result
        reverse(EulerPath.begin(), EulerPath.end());
        vector<vector<int>> ans;
        for (int i = 0; i < EulerPath.size() - 1; i++) {
            ans.push_back({EulerPath[i], EulerPath[i + 1]});
        }
        return ans;
    }
};