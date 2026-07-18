class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5}; // only three primes
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> s;

        pq.push(1);
        s.insert(1); // 1

        long curr;
        for (int i = 0; i < n; i++) {
            curr = pq.top();
            pq.pop();
            for (int i : primes) {
                long new_ugly = curr * i;
                if (s.find(new_ugly) == s.end()) {
                    s.insert(new_ugly);
                    pq.push(new_ugly);
                }
            }
        }
        return (int)curr;
    }
};