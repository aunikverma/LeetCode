class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        vector<string> arr;
        string token;
        while (getline(ss, token, ' ')) {
            arr.push_back(token);
        }
        int n = arr.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (arr[i] == first) {
                if (i + 1 < n && arr[i + 1] == second && i + 2 < n) {
                    ans.push_back(arr[i + 2]);
                }
            }
        }
        return ans;
    }
};