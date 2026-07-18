class Solution {
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b; // to avoid overflow first divide
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        st.push(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            long long curr = nums[i];
            while (!st.empty() && gcd(st.top(), curr) > 1) {
                curr = lcm(st.top(), curr);
                st.pop();
            }
            st.push(curr);
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};