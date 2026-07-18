class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // sort meetings
        priority_queue<int, vector<int>, greater<int>> emptyroom;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            roomused;
        vector<int> roomcount(n, 0);
        for (int i = 0; i < n; i++) { // empty room at start
            emptyroom.push(i);
        }
        for (auto& meet : meetings) {
            int start = meet[0], end = meet[1];
            while (!roomused.empty() &&
                   roomused.top().first <= start) // ended meetings
            {
                emptyroom.push(roomused.top().second); // into empty room
                roomused.pop();
            }
            if (!emptyroom.empty()) // have empty room
            {
                int room = emptyroom.top();
                emptyroom.pop();
                roomused.push({end, room});
                roomcount[room]++;
            } else { // if not using room which has early time
                int room = roomused.top().second;
                long long endtime = roomused.top().first;
                roomused.pop();
                roomused.push({endtime + end - start, room});
                roomcount[room]++;
            }
        }
        int resultroom = -1, max_use = 0;
        for (int i = 0; i < n; i++) {
            if (roomcount[i] > max_use) {
                max_use = roomcount[i];
                resultroom = i;
            }
        }
        return resultroom;
    }
};