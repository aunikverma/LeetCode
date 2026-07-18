class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;//base case 1
        if(s.length() == k) return true;//base case 2
        int count = 0;
        vector<int> arr(26, 0);
        for (char c : s) {
            arr[c - 'a']++;
        }
        for (int i : arr) {
            if (i % 2 == 1) {
                count++;
            }
        }
        return (count <= k && s.length() >= k);
    }
};