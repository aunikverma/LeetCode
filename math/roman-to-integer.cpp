class Solution {
public:
    int romanToInt(string s) {
        int Result = 0;
        // char I, V, X, L, C, D, M;
        // char Symbol[] = {I, V, X, L, C, D, M};
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if ('I' == s[i]) {
                if (s[i + 1] == 'V') {
                    Result += 4;
                    i++;
                    continue;

                } else if (s[i + 1] == 'X') {
                    Result += 9;
                    i++;
                    continue;
                }
                Result += 1;
            } else if ('V' == s[i]) {
                Result += 5;
            } else if ('X' == s[i]) {
                if (s[i + 1] == 'L') {
                    Result += 40;
                    i++;
                    continue;

                } else if (s[i + 1] == 'C') {
                    Result += 90;
                    i++;
                    continue;
                }
                Result += 10;
            } else if ('L' == s[i]) {
                Result += 50;
            } else if ('C' == s[i]) {
                if (s[i + 1] == 'D') {
                    Result += 400;
                    i++;
                    continue;

                } else if (s[i + 1] == 'M') {
                    Result += 900;
                    i++;
                    continue;
                }
                Result += 100;
            } else if ('D' == s[i]) {
                Result += 500;
            } else if ('M' == s[i]) {
                Result += 1000;
            }
        }
        return Result;
    }
};
