class Solution {
private:
    int digitSum(int n) {
        int s = 0;
        while (n > 0) {
            s += (n % 10);
            n /= 10;
        }
        return s;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (int i : nums) {
            int a = digitSum(i);
            mp[a].push(i);
            if (mp[a].size() > 2) { //same digit sum = max 2 element in pq
                mp[a].pop();
            }
        }
        int ans = -1;
        for (auto& [sum, pq] : mp) {
            if (pq.size() == 2) { //if pq has 2 elements
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                ans = max(ans, first + second);
            }
        }
        return ans;
    }
};