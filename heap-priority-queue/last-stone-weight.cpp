class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) { //if pq.size() >= 1 add d 
                int d = abs(x - y);
                pq.push(d);
            } else { //if pq null then push 0
                if (pq.empty()) {
                    pq.push(0);
                }
            }
        }
        return pq.top();
    }
};