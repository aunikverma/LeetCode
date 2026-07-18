class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        int ans = 0; // no of boxes
        sort(capacity.rbegin(), capacity.rend());
        int i = 0;
        while (i < capacity.size() && sum > 0) {
            sum -= capacity[i];
            ans++;
            i++;
        }
        return ans;
    }
};