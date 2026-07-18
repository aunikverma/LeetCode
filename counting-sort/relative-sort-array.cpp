class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> a;
        vector<int> ans;
        unordered_map<int, int> mp;
        unordered_map<int, int> mp1;
        for (int i : arr2) {
            mp[i]++;
        }
        for (int i : arr1) {
            mp1[i]++;
        }
        for (int i : arr1) {
            if (mp.find(i) == mp.end()) {
                a.push_back(i);
            }
        }
        sort(a.begin(), a.end()); // elements which are not present
        for (int i : arr2) {
            int c = mp1[i];
            while (c) {
                ans.push_back(i);//taking no of times repeating and adding
                c--;
            }
        }
        for (int i : a) {
            ans.push_back(i);//adding sorting no which are not present
        }
        return ans;
    }
};