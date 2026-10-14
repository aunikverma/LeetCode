class Solution {
public:
    bool canWinNim(int n) { 
        return (n % 4); // since we have only three possibilities to remove 1,2,3 stones
    }// n%4 will return only 0,1,2,3
};