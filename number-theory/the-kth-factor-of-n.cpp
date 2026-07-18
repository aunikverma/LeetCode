class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> arr;
        if (k == 1)
            return k;
        arr.push_back(1);
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                arr.push_back(i);
            }
        }
        arr.push_back(n);
        for (int i : arr) {
            cout << i << " ";
        }
        if (arr.size() < k) {
            return -1;
        }
        return arr[k - 1];
    }
};