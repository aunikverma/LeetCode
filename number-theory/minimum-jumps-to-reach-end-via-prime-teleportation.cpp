class Solution {
public:
    vector<int> isPrime;

    void buildSieve(int maxi) {
        isPrime.resize(maxi + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int n = 2; n * n <= maxi; n++) {
            for (int factor = n * n; factor <= maxi; factor += n) {
                isPrime[factor] = false;
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        // nums[i]-> indexes
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxi = max(nums[i], maxi);
        }

        // building sieve
        buildSieve(maxi);

        vector<bool> visited(n, false);
        // already seen prime
        unordered_set<int> seen;

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int n1 = q.size();
            while (n1--) {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    return steps;
                }
                if (i + 1 < n && !visited[i + 1]) {
                    q.push(i + 1);
                    visited[i + 1] = true;
                }
                if (i - 1 >= 0 && !visited[i - 1]) {
                    q.push(i - 1);
                    visited[i - 1] = true;
                }
                if (!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }
                for (int factor = nums[i]; factor <= maxi; factor += nums[i]) {
                    if (!mp.count(factor)) {
                        continue;
                    }
                    for (int j : mp[factor]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};