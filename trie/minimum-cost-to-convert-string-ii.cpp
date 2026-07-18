class Solution {
public:
    // variables
    typedef long long ll;
    typedef pair<ll, string> P;
    ll big_val = 1e10;
    // string : string,cost
    unordered_map<string, vector<pair<string, ll>>> adj;
    unordered_map<string, unordered_map<string, ll>> dijkstramemo;
    vector<ll> dp;
    string srcstr;
    string targetstr;
    // sorted order
    set<int> validlengths;

    // dijkstra
    ll dijkstra(string& start, string& end) {
        // check in dijkstramemo
        if (dijkstramemo[start].count(end)) {
            return dijkstramemo[start][end];
        }
        // cost string
        priority_queue<P, vector<P>, greater<P>> pq;
        unordered_map<string, ll> dist;
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [currCost, node] = pq.top();
            pq.pop();

            if (node == end) {
                break;
            }
            for (auto& i : adj[node]) {
                auto [adjNode, edgeCost] = i;
                if (!dist.count(adjNode) ||
                    currCost + edgeCost < dist[adjNode]) {
                    dist[adjNode] = currCost + edgeCost;
                    pq.push({currCost + edgeCost, adjNode});
                }
            }
        }
        return dijkstramemo[start][end] =
                   (dist.count(end) ? dist[end] : big_val);
    }

    // solve(index)
    long long solve(int ind) {
        if (ind >= srcstr.length()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        ll min_cost = big_val;

        if (srcstr[ind] == targetstr[ind]) {
            min_cost = solve(ind + 1);
        }

        for (auto& l : validlengths) {
            if (ind + l > srcstr.length()) {
                break;
            }
            string srcSub = srcstr.substr(ind, l);
            string tgtSub = targetstr.substr(ind, l);
            // not in original sub
            if (!adj.count(srcSub)) {
                continue;
            }
            // dijkstra
            ll min_pathcost = dijkstra(srcSub, tgtSub);
            if (min_pathcost == big_val) {
                continue; // no path
            }

            min_cost = min(min_cost, min_pathcost + solve(ind + l));
        }
        return dp[ind] = min_cost;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        srcstr = source;
        targetstr = target;

        dp.assign(10001, -1);

        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        for (auto& s : original) {
            validlengths.insert(s.length());
        }

        ll ans = solve(0);

        return (ans == big_val) ? -1 : ans;
    }
};