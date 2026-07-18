class Solution {
private:
    int find(int n) {
        int ans = 0;
        for (int i = 0; i <= 30; i++) {
            if (pow(2, i) > n) {
                ans = i;
                return ans;
            }
        }
        return ans;
    }

public:
    bool reorderedPowerOf2(int n) {
        if (n == 1) return true; // base case
        unordered_map<string, int> mp; //storing all from 0 to e in sorted manner
        string a = to_string(n);
        sort(a.rbegin(), a.rend());
        int x = stoi(a); //largest no that can be formed by rearranging
        int e = find(x); //largest powerof 2 from which n is small
        for (int i = 0; i <= e; i++) {
            int a = pow(2, i);
            string s = to_string(a);
            sort(s.begin(), s.end());
            mp[s]++;
        }
        string s1 = to_string(n);
        sort(s1.begin(), s1.end());
        if (mp.find(s1) != mp.end()) { //if s1 is present then true
            return true;
        } else {
            return false;
        }
    }
};