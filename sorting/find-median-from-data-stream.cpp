class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    double median = 0;
    int signum(int a, int b) {
        if (a == b)
            return 0;
        else if (a > b)
            return 1;
        else
            return -1;
    }
    void callmedian(int element, priority_queue<int>& maxi,
                    priority_queue<int, vector<int>, greater<int>>& mini,
                    double& median) {
        switch (signum(maxi.size(), mini.size())) {
        case 0: // a == b
            if (element > median) {
                mini.push(element);
                median = mini.top(); // b has more then b.top
            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;

        case 1: // a > b
            if (element > median) {
                mini.push(element);
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
            }
            median = (maxi.top() + mini.top()) / 2.0;
            break;

        case -1: // a < b
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            } else {
                maxi.push(element);
            }
            median = (maxi.top() + mini.top()) / 2.0;
            break;
        }
    }
    MedianFinder() {}

    void addNum(int num) { callmedian(num, maxi, mini, median); }

    double findMedian() { return median; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */