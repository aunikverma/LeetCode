class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); // sort by start day
        priority_queue<int, vector<int>, greater<int>>
            pq; // min-heap for end times

        int i = 0, n = events.size();
        int day = 0, count = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                day = events[i][0]; // jump to next event start
            }
            // add all events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            // remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            // attend one event today
            if (!pq.empty()) {
                pq.pop();
                count++;
            }
            day++;
        }
        return count;
    }
};