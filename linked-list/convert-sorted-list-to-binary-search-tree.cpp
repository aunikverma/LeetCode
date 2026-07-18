/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(vector<int> nums, int s, int e) {
        if (s > e)
            return nullptr;
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(nums, s, mid - 1);
        root->right = solve(nums, mid + 1, e);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        if (head == NULL) {
            TreeNode* root = NULL;
            return root;
        }
        ListNode* curr = head;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        TreeNode* root = solve(nums, 0, nums.size() - 1);
        return root;
    }
};