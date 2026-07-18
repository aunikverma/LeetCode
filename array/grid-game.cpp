class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = 0,bot = 0,mini = LLONG_MAX;
        for(int i : grid[0]) topSum += i;
        for(int i = 0;i < grid[0].size();i++)
        {
            topSum -= grid[0][i];
            mini = min(mini,max(topSum,bot));
            bot += grid[1][i];
        }
        return mini;
    }
};
// Keep track of total sum of top row (topSum) and accumulating sum of bottom row (botSum)
// For each column, consider if Robot1 turns down at that point:
// Subtract current top element from topSum (remaining top elements)
// Compare max of (topSum, botSum) to find Robot2's best score
// Add current bottom element to botSum
// Track minimum of all possible Robot2 scores