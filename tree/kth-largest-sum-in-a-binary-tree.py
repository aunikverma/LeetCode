# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        h = []
        q = [root]
        while q:
            temp = []
            sm = 0
            for i in q:
                sm += i.val
                if i.left:
                    temp.append(i.left)
                if i.right:
                    temp.append(i.right)
            if len(h) < k:
                heappush(h, sm)
            else:
                if sm > h[0]:
                    heappop(h)
                    heappush(h, sm)
            q = temp
        return (h[0] if len(h) == k else -1)
        