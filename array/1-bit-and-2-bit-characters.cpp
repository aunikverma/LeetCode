class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        for (int i = 0; i < bits.size(); i++) {
            if (bits[i] == 0) { //if single bit 0
                continue;
            } else if (bits[i] == 1 && i + 1 > n - 1) { //if last bit 1
                return false;
            } else if (bits[i] == 1 && i + 1 != n - 1) { //if second last bit is 1 
                i++;
            } else {
                return false;
            }
        }
        return true;
    }
};