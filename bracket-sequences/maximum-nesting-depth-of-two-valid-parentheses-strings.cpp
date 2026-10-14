class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans(n);

        int depth = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = (depth & 1 ? 0 : 1);
            } else {
                ans[i] = (depth & 1 ? 0 : 1);
                depth--;
            }
        }
        return ans;
    }
};
// find max depth
// since string is balanced itself, we divide in half
// to reduce max depth(A,B)
// for odd depth A,even depth B
// before minus depth, we know which group bracket it is closing
