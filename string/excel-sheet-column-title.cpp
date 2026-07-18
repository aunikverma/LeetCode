class Solution {
public:
    string convertToTitle(int N) {
        vector<char> s;
        char a = 'A';
        for (int i = 0; i < 26; i++) {
            s.push_back(a++);
        }
        string ans = "";
        while (N > 0) {
            N--;
            ans += s[N % 26];
            N /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution1 {
public:
    string convertToTitle(int N) {
        vector<char> s;
        // char a = 'A';
        // for (int i = 0; i < 26; i++) {
        //     s.push_back(a++);
        // }
        string ans = "";
        while (N > 0) {
            N--;
            ans += char(N % 26) + 'A';
            N /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};