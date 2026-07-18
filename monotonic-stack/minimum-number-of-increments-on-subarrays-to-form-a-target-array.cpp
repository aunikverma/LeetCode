class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1])
                ans += target[i] - target[i - 1];
        }
        return ans;
    }
};
// Imagine building a skyline from the ground up.

// Each number in target is the height of a building and you start with an empty flatland of zeros.
// Every time the skyline rises, you need to pour in fresh effort (an operation that lifts that section higher). But when it falls or stays level, no extra effort is needed, gravity or flatness takes care of it.
// So, the total effort is just the sum of all upward climbs.