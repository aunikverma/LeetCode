class Solution {
public:
    long long nCr(int n, int r, int k) {
        // nCr = nC(n - r)
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res >= k) {
                return k;
            }
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();
        // middle char
        char mid = ' ';
        if (n & 1) {
            mid = s[n / 2];
        }

        // count of char
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            if (n & 1 && i == n / 2) {
                continue;
            }
            freq[s[i] - 'a'] += 1;
        }
        // half freq will be used only
        for (int i = 0; i < 26; i++) {
            freq[i] >>= 1;
        }

        // now making result
        string halfRes = "";
        int half = n / 2;

        for (int i = 0; i < half; i++) {
            // did i able to put ith char
            bool filled = false;
            // which char to put
            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    freq[j] -= 1;
                    // counting ways
                    long long ways = 1;
                    int letters = 0;
                    for (int c = 0; c < 26; c++) {
                        letters += freq[c];
                    }
                    for (int c = 0; c < 26; c++) {
                        if (freq[c] > 0) {
                            ways *= nCr(letters, freq[c], k);
                            letters -= freq[c];
                        }
                        if (ways >= k) {
                            break;
                        }
                    }
                    // if this block contains result
                    if (ways >= k) {
                        // fixed this char
                        halfRes.push_back(j + 'a');
                        filled = true;
                        break;
                    } else {
                        k -= ways;
                        freq[j] += 1;
                    }
                }
            }
            // not able to put
            if (!filled) {
                return "";
            }
        }

        string rev = halfRes;
        reverse(rev.begin(), rev.end());

        if (mid != ' ') {
            halfRes.push_back(mid);
        }
        halfRes += rev;
        return halfRes;
    }
};

// O(n * 26 * 26 * logk)