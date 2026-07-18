class SmallestInfiniteSet {
public:
    int curr; // pointer to next smallest number
    unordered_set<int> addedBack;
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    SmallestInfiniteSet() { curr = 1; }

    int popSmallest() {
        int ans;
        if (!pq.empty()) {
            ans = pq.top();
            pq.pop();
            addedBack.erase(ans);
        } else {
            ans = curr;
            curr++;
        }
        return ans;
    }

    void addBack(int num) {
        if (num < curr && addedBack.count(num) == 0) { //All numbers < curr are already popped at some point
            pq.push(num);
            addedBack.insert(num);
        }
    }
};
