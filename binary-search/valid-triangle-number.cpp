class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        if (n < 3) {
            return count;
        }
        sort(arr.begin(), arr.end());      // sort and try from biggest element
        for (int k = n - 1; k >= 2; k--) { // fix k
            int i = 0, j = k - 1;          // now check for smallest and k - 1
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) { // if i and j satisfies
                    count += (j - i); // element between i j also satisfy
                    j--;              // j--
                } else {              // if arr[i + j] is small i ++
                    i++;
                }
            }
        }
        return count;
    }
};