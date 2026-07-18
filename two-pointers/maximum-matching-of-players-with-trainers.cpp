class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = players.size() - 1;  // players last
        int j = trainers.size() - 1; // trainers last
        int ans = 0;                 // how many matches
        while (i >= 0 && j >= 0) {
            if (trainers[j] < players[i]) {
                i--;
            } else if (trainers[j] >= players[i]) {
                i--;
                j--;
                ans++;
            }
        }
        return ans;
    }
};