class Solution {
public:
    int maxProduct(vector<int>& n) {
        priority_queue<int>pq(n.begin(),n.end());
        int a = pq.top() - 1;
        pq.pop();
        int b = pq.top() - 1;
        return (a*b);
    }
};