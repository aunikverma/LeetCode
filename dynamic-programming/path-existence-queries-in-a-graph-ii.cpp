class Solution {
public:
    int rows, cols;
    vector<vector<int>> ancestorTable;

    int upperBin(vector<pair<int, int>>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid].first <= target) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        // val->node
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        // original node ->sorted array index
        vector<int> NodetoIndex(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            int node = arr[i].second;
            NodetoIndex[node] = i;
        }
        // farthest node i can reach by taking 2^j'th jump
        rows = n;
        cols = log2(n) + 1;
        ancestorTable.resize(rows, vector<int>(cols, 0));

        // fill 0th col first
        for (int node = 0; node < n; node++) {
            int farthestIndOne = upperBin(arr, arr[node].first + maxDiff);
            ancestorTable[node][0] = farthestIndOne;
        }

        // fill remaining cols
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                ancestorTable[node][j] =
                    ancestorTable[ancestorTable[node][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int a = NodetoIndex[u];
            int b = NodetoIndex[v];

            if (a == b) {
                ans.push_back(0);
                continue;
            }
            if (a > b) {
                swap(a, b);
            }
            int curr = a;
            int jumps = 0;
            for (int j = cols - 1; j >= 0; j--) {
                if (ancestorTable[curr][j] < b) {
                    curr = ancestorTable[curr][j];
                    jumps += (1 << j);
                }
            }
            if (ancestorTable[curr][0] >= b) {
                ans.push_back(jumps + 1);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};