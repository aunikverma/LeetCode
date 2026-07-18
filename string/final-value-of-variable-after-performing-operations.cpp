class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& v : operations) {
            if (v[0] == '+' || v[v.size() - 1] == '+') {
                x += 1;
            } else {
                x -= 1;
            }
        }
        return x;
    }
};