class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int size = 1 << n;
        for (int i = 0; i < size; i++) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};
// i ^ (i >> 1): This is the bitwise XOR operation. It compares each bit of i
// with the corresponding bit of i >> 1.
//  The result for a given bit position is 1 if the bits being compared are
//  different,
//   and 0 if they are the same. This operation essentially computes the Gray
//   code.