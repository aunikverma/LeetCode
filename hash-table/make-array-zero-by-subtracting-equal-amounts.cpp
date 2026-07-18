class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for (int i : nums) {
            if (i > 0) {
                s.insert(i);
            }
        }
        return s.size();
    }
};