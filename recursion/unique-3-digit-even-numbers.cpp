class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int i : digits) {
            freq[i] += 1;
        }
        int count = 0;
        for (int i = 100; i <= 999; i++) {
            if (i & 1) {
                continue;
            }
            vector<int> mp = freq;
            int n = i;
            bool present = true;
            while (n > 0) {
                mp[n % 10] -= 1;
                if (mp[n % 10] < 0) {
                    present = false;
                    break;
                }
                n /= 10;
            }
            if (present) {
                count += 1;
            }
        }
        return count;
    }
};