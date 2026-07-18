class Solution {
public:
    int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp; // y->count
        for (auto& i : points) {
            mp[i[1]]++;
        }
        long long result = 0; // count of trapezoids
        long long prev = 0;   // prev horizontal lines
        for (auto& i : mp) {
            long long count = i.second;
            long long h_lines = count * (count - 1) / 2; // n * (n - 1) /2
            result += h_lines * prev;               // lines * prev points
            prev += h_lines;
        }
        return (int)(result % mod);
    }
};