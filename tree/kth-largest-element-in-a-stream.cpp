class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int s; // the sth largest we have to return
    KthLargest(int k, vector<int>& nums) {
        s = k; // assingning s to k
        for (int i : nums) {
            if (pq.empty() || pq.size() < s) {
                pq.push(i);
            } else if (i > pq.top()) {
                pq.pop();
                pq.push(i);
            }
        }
    }

    int add(int val) {
        if (pq.empty() || pq.size() < s) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */