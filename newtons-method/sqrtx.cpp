class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        
        long long left = 1, right = x; // Use long long for the right limit
        
        while (left <= right) {
            long long mid = left + (right - left) / 2; // Prevents overflow
            
            long long midSquared = mid * mid; // Calculate mid squared
            
            if (midSquared == x) {
                return mid; // Found exact square root
            } else if (midSquared < x) {
                left = mid + 1; // Move to higher half
            } else {
                right = mid - 1; // Move to lower half
            }
        }
        
        return right; // right is the floor of the square root at the end of the loop
    }
};
