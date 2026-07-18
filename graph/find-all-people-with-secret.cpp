class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& meet : meetings) {
            int p1 = meet[0], p2 = meet[1], time = meet[2];
            adj[p1].push_back({p2, time});
            adj[p2].push_back({p1, time});
        }
        queue<pair<int, int>> q; // person - time
        q.push({0, 0});
        q.push({firstPerson, 0});
        vector<int> time_secret(n, INT_MAX);
        time_secret[0] = time_secret[firstPerson] = 0;
        // Min-heap: (time, person)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [t, p] = pq.top();
            pq.pop();

            if (t > time_secret[p])
                continue; // skip outdated entry

            for (auto& [p2, meet_time] : adj[p]) {
                if (meet_time >= t && time_secret[p2] > meet_time) {
                    time_secret[p2] = meet_time;
                    pq.push({meet_time, p2});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (time_secret[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};