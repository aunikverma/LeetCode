class Solution {
private:
    bool check(string s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1])
                return false;
        }
        return true;
    }

public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp; // freq : char
        for (char c : s) mp[c]++;
        priority_queue<pair<int,char>>pq;
        for(auto& v : mp) pq.push({v.second,v.first}); 
        string ans = "";
        while (pq.size() >= 2) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans += a.second;
            ans += b.second;
            if (--a.first > 0) pq.push(a);
            if (--b.first > 0) pq.push(b);
        }
        while (!pq.empty()) // if any left
        {
            for (int i = 0; i < pq.top().first; i++) {
                ans += pq.top().second;
            }
            pq.pop();
        }
        if (check(ans)) { //if any char is adjacent
            return ans;
        }
        return "";
    }
};