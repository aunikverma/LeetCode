class TaskManager {
public:
    unordered_map<int, pair<int, int>> mp; // taskid = userid,priority
    set<pair<int, int>> s;                 // priority : taskid
    TaskManager(vector<vector<int>>& tasks) {
        for (auto i : tasks) {
            mp[i[1]] = {i[0], i[2]};
            s.insert({i[2], i[1]});
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        s.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto v = mp[taskId];
        s.erase({v.second, taskId}); //delete
        mp[taskId].second = newPriority; //update
        s.insert({newPriority, taskId}); //reinsert
    }

    void rmv(int taskId) {
        auto v = mp[taskId]; //delete
        s.erase({v.second, taskId});
        mp.erase(taskId);
    }

    int execTop() {
        if (mp.empty()) //if mp is empty
            return -1;
        auto it = s.end(); //return last priority user id
        it--;
        auto v = *it;
        int ans = mp[v.second].first;
        mp.erase(v.second);
        s.erase(it);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */