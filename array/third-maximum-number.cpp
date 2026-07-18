class Solution {
public:
    int thirdMax(vector<int>& n) {
        set<int> s(n.begin(), n.end());
        vector<int> a(s.begin(), s.end());
        if (a.size() < 3) {
            return a[a.size() - 1];
        }
        return a[a.size() - 3];
    }
};