class Router {
public:
    int maxsize;                       // memory limit
    queue<tuple<int,int,int>> q;       // FIFO packets (source,dest,timestamp)
    unordered_set<string> seen;        // to detect duplicate packets
    unordered_map<int, vector<int>> destToTimestamps; // dest -> all timestamps
    unordered_map<int, int> destProcessed;            // how many forwarded for each dest

    Router(int memoryLimit) {
        maxsize = memoryLimit;
    }

    // helper to build a unique key for duplicates
    string makeKey(int s,int d,int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source,destination,timestamp);
        if (seen.count(key)) {
            return false; // duplicate packet
        }

        // if full, evict oldest
        if ((int)q.size() == maxsize) {
            auto [os,od,ot] = q.front(); q.pop();
            string oldKey = makeKey(os,od,ot);
            seen.erase(oldKey);
            destProcessed[od]++; // one more forwarded for this dest
        }

        // push new packet
        q.emplace(source,destination,timestamp);
        seen.insert(key);
        destToTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto [s,d,t] = q.front(); q.pop();
        string key = makeKey(s,d,t);
        seen.erase(key);
        destProcessed[d]++;
        return {s,d,t};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto &vec = destToTimestamps[destination];
        int processed = destProcessed[destination]; // skip old forwarded ones
        // vec is in arrival order; use binary search on the unprocessed tail
        auto lb = lower_bound(vec.begin()+processed, vec.end(), startTime);
        auto ub = upper_bound(vec.begin()+processed, vec.end(), endTime);
        return (int)(ub - lb);
    }
};