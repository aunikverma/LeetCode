class Solution {
private:
    int digitsum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int differenceOfSum(vector<int>& nums) {
        int s = 0;
        int s1 = 0;
        for(int i : nums)
        {
            s += digitsum(i);
            s1 += i;
        }
        return abs(s - s1);
    }
};