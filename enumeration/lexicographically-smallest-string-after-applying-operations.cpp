class Solution {
public:
    string rotate(string s1, int b) {
        reverse(s1.begin(), s1.end());
        reverse(s1.begin(), s1.begin() + b);
        reverse(s1.begin() + b, s1.end());
        return s1;
    }

    string add_odd(string s1, int a) {
        for (int i = 0; i < s1.length(); i++) {
            if (i & 1) {
                int x = ((s1[i] - '0') + a) % 10;
                s1[i] = '0' + x;
            }
        }
        return s1;
    }

    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(s);
        // finding all possible combos
        while (!q.empty()) {
            string s1 = q.front();
            q.pop();
            // finding min among them
            ans = min(ans, s1);
            if (visited[s1]) {
                continue;
            } else {
                visited[s1] = true;
                string op1 = rotate(s1, b);
                string op2 = add_odd(s1, a);
                if (!visited[op1]) {
                    q.push(op1);
                }
                if (!visited[op2]) {
                    q.push(op2);
                }
            }
        }
        return ans;
    }
};