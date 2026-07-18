class Solution {
public:
    int totalMoney(int n) {
        int money = 0;
        int start = 1;
        int a = start;
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 0) {
                money += a;
                start++;
                a = start;
            } else {
                money += a;
                a++;
            }
        }
        return money;
    }
};