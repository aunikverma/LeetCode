class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        // positions indexing
        int n = positions.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[positions[i]] = i;
        }
        sort(positions.begin(), positions.end());
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int ind = mp[positions[i]];
            if (directions[ind] == 'R') {
                st.push(ind);
            } else {
                // left until no right one left
                while (!st.empty() && healths[ind] > 0) {
                    int top_ind = st.top();
                    st.pop();
                    if (healths[top_ind] > healths[ind]) {
                        healths[top_ind] -= 1;
                        healths[ind] = 0;
                        st.push(top_ind);
                    } else if (healths[top_ind] < healths[ind]) {
                        healths[top_ind] = 0;
                        healths[ind] -= 1;
                    } else {
                        healths[top_ind] = 0;
                        healths[ind] = 0;
                    }
                }
            }
        }
        for (int i : healths) {
            if (i > 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};