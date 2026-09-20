class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int k = 1;
        for (char c : s) {
            sum += (26 - (c - 'a')) * k;
            k++;
        }
        return sum;
    }
};