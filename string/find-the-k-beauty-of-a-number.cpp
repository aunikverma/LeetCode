class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int left = 0;
        int count = 0;
        string s = to_string(num);

        for (int right = 0; right < s.length(); right++) {
            if (right - left + 1 == k) {
                string d = s.substr(left, k);
                int a = stoi(d);
                if (a != 0 && num % a == 0) {
                    count += 1;
                }
                left += 1;
            }
        }
        return count;
    }
};