class Solution {
private:
    vector<int> Next_greater(vector<int> arr, int n) {
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && curr >= s.top()) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), 0);
        vector<int> next = Next_greater(nums2, nums2.size());//first we find next greater element of nums2 using stack
        unordered_map<int, int> mp;//stored index of nums2[i] in map
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }
            for (int i = 0; i < nums1.size(); i++) {//now find nums1[i] in nums2[i] and store next greater element of nums2[i]
            ans[i] = next[mp[nums1[i]]];
        }
        return ans;
    }
};