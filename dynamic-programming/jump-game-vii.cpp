class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        // base case
        if (s[n - 1] == '1') {
            return false;
        }
        queue<int> q;
        vector<bool> visited(n, false);
        visited[0] = true;
        q.push(0);
        // how far we have calculated
        int farthest = 0;
        while (!q.empty()) {
            int n1 = q.size();
            while (n1--) {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    return true;
                }
                int start = max(i + minJump, farthest + 1);
                int end = min(i + maxJump, n - 1);

                for (int j = start; j <= end; j++) {
                    if (!visited[j] && s[j] == '0') {
                        q.push(j);
                        visited[j] = true;
                    }
                }
                farthest = end;
            }
        }
        return false;
    }
};