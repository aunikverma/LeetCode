class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long ans = 0;
        while (k) {
            int c = sqrt(pq.top());
            pq.pop();
            pq.push(c);
            k--;//heap after k secs
        }
        while (!pq.empty()) {
            ans += pq.top();//adding all remaining to ans
            pq.pop();
        }
        return ans;
    }
};