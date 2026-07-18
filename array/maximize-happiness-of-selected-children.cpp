class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq(happiness.begin(), happiness.end());
        long long ans = 0;
        int i = 0;
        while (!pq.empty() && k > 0 && pq.top() - i >= 0) {
            ans += pq.top() - i;
            pq.pop();
            i++;
            k--;
        }
        return ans;
    }
};