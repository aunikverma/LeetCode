class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_map<int, long long> freq;
        for (int i : nums) {
            freq[i]++;
        }

        // sort unique
        set<int> unique;
        for (auto& i : freq) {
            unique.insert(i.first);
        }

        // map to store min replacement
        unordered_map<int, int> mp;
        for (int i : unique) {
            mp[i] = i;
        }

        int maxi = *unique.rbegin();
        for (int i : unique) {
            for (int j = i * 2; j <= maxi; j += i) {
                if (mp.count(j)) {
                    mp[j] = min(mp[j], mp[i]);
                }
            }
        }

        long long sum = 0;
        for (auto& v : freq) {
            sum += 1LL * mp[v.first] * v.second;
        }
        return sum;
    }
};