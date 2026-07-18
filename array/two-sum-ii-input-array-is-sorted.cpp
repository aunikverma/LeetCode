class Solution {
private:
    int bin(vector<int>& arr, int k,int ind) {
        int s = 0;
        int e = arr.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == k && mid != ind) {
                return mid;
            } else if (arr[mid] > k) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }

public:
    vector<int> twoSum(vector<int>& num, int t) {
        vector<int> ans(2, 0);
        for (int i = 0; i < num.size(); i++) {
            int k = bin(num, t - num[i],i);
            if (k != -1) {
                ans[0] = i + 1;
                ans[1] = k + 1;
                return ans;
            }
        }
        return ans;
    }
};