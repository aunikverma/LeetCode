class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>>ans;
        vector<pair<int,vector<int>>>a;
        for(int i = 0;i < score.size();i++)
        {
            a.push_back({score[i][k],score[i]});//taking input
        }
        sort(a.rbegin(),a.rend());//sort according to numbers
        for(auto &v : a)
        {
            ans.push_back(v.second);
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[k](const vector<int>&a,const vector<int>&b)
        {
            return a[k] > b[k];
        });
        return score;
    }
};

