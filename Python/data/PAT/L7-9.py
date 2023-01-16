class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 中序遍历，后序遍历，
# 后序遍历最后一个元素必为根
# 找到后序遍历在中序遍历中的位置便可以将数组一分为2
# 递归操作
def tree_build(in_order, post_order):
    if not post_order:
        return None
    root = TreeNode(post_order[-1])
    root_index = in_order.index(post_order[-1])
    left_inorder = in_order[:root_index]
    right_inorder = in_order[root_index + 1:]
    l_left = len(left_inorder)
    left_postorder = post_order[:l_left]
    right_postorder = post_order[l_left:-1]
    root.left = tree_build(left_inorder, left_postorder)
    root.right = tree_build(right_inorder, right_postorder)
    return root


def levelOrder(root: TreeNode):
    # res = []
    dfs(root, 0)
    return res


def dfs(root: TreeNode, level: int) -> None:
    if not root:
        return
    if len(res) <= level:
        res.append([])
    res[level].append(root.val)
    dfs(root.left, level + 1)
    dfs(root.right, level + 1)


res = []
n = int(input())
in_order = input().split()
post_order = input().split()
root = tree_build(in_order, post_order)
levelOrder(root)
print("R:", end="")
for i in range(len(res)):
    print(f' {res[i][-1]}', end="")
print()
print("L:", end="")
for i in range(len(res)):
    print(f' {res[i][0]}', end="")
print()
