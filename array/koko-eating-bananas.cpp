class Solution {
private:
    long long banana(int k, vector<int>& pi) {
        long long a = 0;
        // divind per hour and returning total hours
        for (int i : pi) {
            a += ceil(i / (k * 1.0));
        }
        return a;
    }

public:
    int minEatingSpeed(vector<int>& pi, int h) {
        auto it = max_element(pi.begin(), pi.end());
        int s = 1;
        int e = *it;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (banana(mid, pi) <= h) // checking in banana
            {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};