class Solution {
public:
    string addStrings(string num1, string num2) {
        // now adding string
        string ans = "";
        int carry = 0;
        int i = num1.length() - 1;//start from last indexes
        int j = num2.length() - 1;
        while (i >= 0 || j >= 0 || carry != 0) {
            int d1 = (i >= 0) ? num1[i] - '0' : 0;
            int d2 = (j >= 0) ? num2[j] - '0' : 0;
            int sum = d1 + d2 + carry;
            int val = sum % 10;
            carry = sum / 10;
            ans.push_back(val + '0');
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());//reversing ans
        return ans;
    }
};