class TaskManager {
public:
    unordered_map<int, int> user;
    unordered_map<int, int> prior;
    set<pair<int, int>> task;

    TaskManager(vector<vector<int>>& tasks) {
        for(vector<int> x : tasks)
            add(x[0], x[1], x[2]);
    }
    
    void add(int userId, int taskId, int priority) {
        user[taskId] = userId;
        prior[taskId] = priority;
        task.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldprior = prior[taskId];
        prior[taskId] = newPriority;
        task.erase({oldprior, taskId});
        task.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        int oldprior = prior[taskId];
        task.erase({oldprior, taskId});
        prior.erase(taskId);
        user.erase(taskId);
    }
    
    int execTop() {
        if(task.empty())
            return -1;
        auto it = task.end();
        it--;
        int taskId = it->second;
        int priority = prior[taskId];
        int userId = user[taskId];
        rmv(taskId);
        return userId;
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