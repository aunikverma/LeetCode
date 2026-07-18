class Solution {
private:
    int firstp(vector<int> arr) {
        int a = -1;
        int s = 0, e = arr.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] > 0) {
                a = mid;
                e = mid - 1;
            } else if (arr[mid] == 0 || arr[mid] < 0) {
                s = mid + 1;
            }
        }
        cout << a;
        return a;
    }
    int firstn(vector<int> arr) {
        int a = -1;
        int s = 0, e = arr.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] < 0) {
                a = mid;
                s = mid + 1;
            } else if (arr[mid] == 0 || arr[mid] > 0) {
                e = mid - 1;
            }
        }
        cout << a;
        return a;
    }

public:
    int maximumCount(vector<int>& nums) {
        int a = 0, b = 0;
        if (firstp(nums) != -1) {
            a = nums.size() - firstp(nums);
        }
        if (firstn(nums) != -1) {
            b = firstn(nums) + 1;
        }
        return max(a, b);
    }
};