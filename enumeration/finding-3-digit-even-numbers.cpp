class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq(10, 0); // Frequency count of digits
        for (int d : digits) freq[d]++;

        // Generate all valid three-digit even numbers
        for (int num = 100; num < 1000;num += 2) { 
            int temp = num;
            vector<int> needed(10, 0);
            // Extract digits of num
            needed[temp / 100]++;       // Hundreds place
            needed[(temp / 10) % 10]++; // Tens place
            needed[temp % 10]++;        // Units place

            // Check if we have enough digits in digits
            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (needed[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.push_back(num);
        }
        return ans;
    }
};