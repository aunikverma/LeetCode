class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string ans = "";
        while (!pq.empty()) {
            auto [count, ch] = pq.top(); pq.pop();
            int len = ans.size();
            if (len >= 2 && ans[len - 1] == ch && ans[len - 2] == ch) { //if ans size >= 2
                if (pq.empty()) break; //if not any in pq
                auto [count2, ch2] = pq.top(); pq.pop(); //non repeat char
                ans += ch2;
                if (--count2 > 0) pq.push({count2, ch2});
                pq.push({count, ch});
            } else {
                ans += ch;
                if (--count > 0) pq.push({count, ch});
            }
        }
        return ans;
    }
};