class Solution {
public:
    int minChanges(int n, int k) {
        if ((n & k) != k) return -1; // if its impossible to make them equal
        string n1 = bitset<32>(n).to_string();
        string k1 = bitset<32>(k).to_string();

        int count = 0;

        for (int i = 0; i < n1.size(); i++) {
            if (n1[i] - k1[i] == 1) {
                count++;
            }
        }
        return count;
    }
};