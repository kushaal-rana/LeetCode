// Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

// Different ways to write the same code
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if ((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val))
            return root;

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return lowestCommonAncestor(root->right, p, q);
    }
};