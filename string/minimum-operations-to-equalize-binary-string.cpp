class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int startZeroes = 0;
        for (char c : s) {
            if (c == '0') {
                startZeroes++;
            }
        }
        if (startZeroes == 0) {
            return 0;
        }
        vector<int> operations(n + 1, -1);
        set<int> evenSet, oddSet;

        for (int count = 0; count <= n; count++) {
            if (count & 1) {
                oddSet.insert(count);
            } else {
                evenSet.insert(count);
            }
        }

        queue<int> q;
        q.push(startZeroes);
        operations[startZeroes] = 0;

        if (startZeroes & 1) {
            oddSet.erase(startZeroes);
        } else {
            evenSet.erase(startZeroes);
        }

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            int min_new_z = z + k - 2 * min(k, z);
            int max_new_z = z + k - 2 * max(0, k - n + z);

            set<int>& currSet = (min_new_z & 1) ? oddSet : evenSet;

            auto it = currSet.lower_bound(min_new_z);

            while (it != currSet.end() && *it <= max_new_z) {
                int new_z = *it;
                if (operations[new_z] == -1) {
                    operations[new_z] = operations[z] + 1;
                    if (new_z == 0) {
                        return operations[new_z];
                    }
                    q.push(new_z);
                }
                it = currSet.erase(it);
            }
        }
        return -1;
    }
};
// operations[i] = min  opns reqd to reach state in which we have z zeros