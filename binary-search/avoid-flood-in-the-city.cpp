class Solution {
public:
        vector<int> avoidFlood(vector<int>& r) {
        int n = r.size();
        vector<int> ans(n, 1);
        unordered_map<int,int> last; //day : index
        set<int> dry;
        for (int i = 0; i < n; ++i) {
            if (r[i]) {
                ans[i] = -1;
                if (last.count(r[i])) { //if occur second time
                    auto it = dry.lower_bound(last[r[i]]); //need to dry it 
                    if (it == dry.end()) return {};
                    ans[*it] = r[i]; //lower_bound index to place dry the day
                    dry.erase(it); //delete index from dry 
                }
                last[r[i]] = i;
            } else dry.insert(i);
        }
        return ans;
    }
};