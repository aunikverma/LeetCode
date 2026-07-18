class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long k = 0; k <= 60; k++) {
            long target = num1 - k * num2;
            if (target < 0)
                break;
            if (__builtin_popcountll(target) <= k && target >= k) {
                return k;
            }
        }
        return -1;
    }
};

// num1 = k∗num2 + 2 a1 + 2 a2 + ... +
//        2 ak

//            where k is the total number of operations
//                .The term k∗num2 represents the cumulative subtractions of num2
//                    over k operations.The sum of powers of 2,
//     2 a1 + 2 a2 + ... + 2 ak,
//     represents the total subtractions of powers of 2.

//     We can simplify this to :

//     num1−k∗num2 = 2 a1 + 2 a2 + ... + 2 ak