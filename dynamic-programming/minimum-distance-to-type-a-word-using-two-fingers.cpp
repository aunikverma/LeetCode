class Solution {
public:

    pair<int,int> getCoordinates(int n){
        //since stores in 6 cols
        int x = n / 6;
        int y = n % 6;
        return make_pair(x,y);
    }

    int getCost(int curr, int prev) {
        if (prev == 26) {
            return 0;
        }
        auto [x, y] = getCoordinates(curr);
        auto [x1, y1] = getCoordinates(prev);
        return (abs(x1 - x) + abs(y1 - y));
    }

    int solve(int i, int finger_1, int finger_2, string& word, vector<vector<vector<int>>>& dp) {
        if (i >= word.length()) {
            return 0;
        }
        if(dp[i][finger_1][finger_2] != -1){
            return dp[i][finger_1][finger_2];
        }
        int curr = word[i] - 'A';
        int move1 = getCost(curr, finger_1) + solve(i + 1, curr, finger_2, word, dp);
        int move2 = getCost(curr, finger_2) + solve(i + 1, finger_1, curr, word, dp);
        return dp[i][finger_1][finger_2] = min(move1, move2);
    }

    int solveTab(string& word){
        int n = word.length();
        vector<vector<vector<int>>>dp(n + 1,vector<vector<int>>(27,vector<int>(27,INT_MAX)));
        for(int f1 = 0;f1 < 27;f1++){
            for(int f2 = 0;f2 < 27;f2++){
                dp[n][f1][f2] = 0;
            }
        }
        for(int i = n - 1;i >= 0;i--){
            for(int finger_1 = 26;finger_1 >= 0;finger_1--){
                for(int finger_2 = 26;finger_2 >= 0;finger_2--)
                {
                    int curr = word[i] - 'A';
                    int move1 = getCost(curr,finger_1) + dp[i + 1][curr][finger_2];
                    int move2 = getCost(curr,finger_2) + dp[i + 1][finger_1][curr];
                    dp[i][finger_1][finger_2] = min(move1,move2);
                }
            }
        }
        return dp[0][26][26];
    }

    int minimumDistance(string word) { 
        // int n = word.length();
        // vector<vector<vector<int>>>dp(n + 1,vector<vector<int>>(27,vector<int>(27,-1)));
        // return solve(0, 26, 26, word,dp); 
        return solveTab(word);
    }
};