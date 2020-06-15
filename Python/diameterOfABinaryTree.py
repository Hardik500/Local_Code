class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def height(self, node, count):
        count += 1
        if(self.node.left == None and self.node.right == None):
            return count
        count = height(self.node.left, count)
        count += height(self.node.right, count)
        return count

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        x = self.height(self.root.left, 1)
        y = self.height(self.root.right, 1)

        print(x, y)
