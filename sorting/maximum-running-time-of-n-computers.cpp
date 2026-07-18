class Solution {
public:
    typedef long long ll;

    bool possible(ll mid, int n, vector<int>& batteries) {
        ll target_min = n * mid;
        ll sum = 0;
        for (int i = 0; i < batteries.size(); i++) {
            target_min -= min((ll)batteries[i], mid);
            if (target_min <= 0) {
                return true;
            }
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(begin(batteries), end(batteries)); // min element
        ll sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        ll r = sum / n;
        ll result = 0; // max_minutes
        while (l <= r) {
            ll mid = l + (r - l) / 2; // mid_min
            if (possible(mid, n, batteries)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};