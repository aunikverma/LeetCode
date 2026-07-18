class Solution {
public:
    typedef long long ll;

    bool check(vector<ll>& arr, int k, int side, int d) {
        int n = arr.size();
        ll L = 4LL * side; // perimeter
        vector<ll> extended(2 * n, 0);
        for (int i = 0; i < n; i++) {
            extended[i] = arr[i];
            extended[i + n] = arr[i] + L;
        }
        for (int i = 0; i < n; i++) {
            int count = 1;
            ll pos = extended[i];
            int ind = 1;
            for (int j = 1; j < k; j++) {
                ll target = pos + d;
                auto it = lower_bound(extended.begin() + ind + 1, extended.begin() + i + n, target);
                if (it == extended.begin() + i + n) {
                    count -= 1; // not enough points
                    break;
                }
                ind = it - extended.begin();
                pos = extended[ind];
                count++;
            }
            if (count == k && (extended[i] + L - pos) >= d) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> arr;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (y == 0) {
                arr.push_back(x);
            } else if (x == side) {
                arr.push_back(side + y);
            } else if (y == side) {
                arr.push_back(2LL * side + (side - x));
            } else {
                arr.push_back(3LL * side + (side - y));
            }
        }
        // sorting flattend points
        sort(arr.begin(), arr.end());

        int l = 0, r = 2 * side, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(arr, k, side, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};