class Solution {
public:
    int countVowelStrings(int n) {
        int num = (n + 1) * (n + 2) * (n + 3) * (n + 4);
        return (num / 24);
    }
};