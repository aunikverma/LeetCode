class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp;
        // feeding values
        mp[1000] = "M";
        mp[500] = "D";
        mp[100] = "C";
        mp[50] = "L";
        mp[10] = "X";
        mp[5] = "V";
        mp[1] = "I";
        mp[4] = "IV";
        mp[9] = "IX";
        mp[40] = "XL";
        mp[90] = "XC";
        mp[900] = "CM";
        mp[400] = "CD";

        string ans = "";
        while (num > 0) {
            if (num >= 1000) {
                ans += mp[1000];
                num -= 1000;
            } else if (num >= 900) {
                ans += mp[900];
                num -= 900;
            } else if (num >= 500) {
                ans += mp[500];
                num -= 500;
            } else if (num >= 400) {
                ans += mp[400];
                num -= 400;
            } else if (num >= 100) {
                ans += mp[100];
                num -= 100;
            } else if (num >= 90) {
                ans += mp[90];
                num -= 90;
            } else if (num >= 50) {
                ans += mp[50];
                num -= 50;
            } else if (num >= 40) {
                ans += mp[40];
                num -= 40;
            } else if (num >= 10) {
                ans += mp[10];
                num -= 10;
            } else if (num == 9) {
                ans += mp[9];
                num -= 9;
            } else if (num >= 5) {
                ans += mp[5];
                num -= 5;
            } else if (num == 4) {
                ans += mp[4];
                num -= 4;
            } else if (num >= 1) {
                ans += mp[1];
                num -= 1;
            }
        }
        return ans;
    }
};