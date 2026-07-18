class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            balance += (gas[i] - cost[i]); // find cost
            if (balance <= 0) // if cost is less set balance to zero and start
                              // to i+1 using queue approach
            {
                deficit += balance;
                balance = 0;
                start = i + 1;
            }
        }
        if (balance + deficit >= 0)
            return (start %
                    gas.size()); // if balance+deeficit >= 0 return start index
        // mod if in case starting index is 0 then it must be reset to 0
        return -1;
    }
};