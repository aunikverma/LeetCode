class Solution {
private:
    int count_vowel(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int count = 0;
        string a = "aeiou";
        for (int i = 0; i < 5; i++) {
            if (mp.find(a[i]) != mp.end()) {
                count += mp[a[i]];
            }
        }
        return count;
    }

public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        vector<string> arr;
        while (getline(ss, token, ' ')) {
            arr.push_back(token);
        }
        int k = count_vowel(arr[0]); // vowel in first word
        string ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            ans += ' ';
            int a = count_vowel(arr[i]);
            if (k == a) {
                string rev = arr[i];
                reverse(rev.begin(), rev.end());
                ans += rev;
            } else {
                ans += arr[i];
            }
        }
        return ans;
    }
};