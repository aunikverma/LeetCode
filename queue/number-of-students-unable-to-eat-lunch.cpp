class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one = 0, zero = 0;
        for (int i : students) {
            (i == 0) ? zero++ : one++;
        }
        for (int i : sandwiches) {
            if (i == 0) {
                if (zero > 0) zero--;
                else break;
            } else {
                if (one > 0) one--;
                else break;
            }
        }
        return zero + one;
    }
};