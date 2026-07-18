class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == 5) {
                five++;
            } else if (b[i] == 10) {
                ten++;
                if (five <= 0) {
                    return false;
                } else if (five > 0) {
                    five--;
                }
            } else if (b[i] == 20) {
                if (five <= 0) {
                    return false;
                } else if (ten == 0) {
                    if (five >= 3) {
                        five -= 3;
                    } else {
                        return false;
                    }
                } else {
                    ten--;
                    five--;
                }
            }
        }
        return true;
    }
};