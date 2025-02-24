// Approach - 1 : Using Standard Recursion
class Solution
{
public:
    // TC: O(N^2)
    // SC: O(N)
    TreeNode *construct(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder)
    {
        if (preStart > preEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return root;

        int nextNode = preorder[preStart + 1]; // root of left SubTree

        int j = postStart;
        while (postorder[j] != nextNode)
        {
            j++;
        }

        int numNodes = j - postStart + 1;

        root->left = construct(preStart + 1, postStart, preStart + numNodes, preorder, postorder);
        root->right = construct(preStart + numNodes + 1, j + 1, preEnd, preorder, postorder);

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        return construct(0, 0, n - 1, preorder, postorder);
    }
};
// Approach - 2 : Using Map TC: O(N)
TreeNode *constructUsingMap(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder, unordered_map<int, int> &mp)
{
    if (preStart > preEnd)
        return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);
    if (preStart == preEnd)
        return root;

    int nextNode = preorder[preStart + 1]; // root of left SubTree

    int j = mp[nextNode];

    int numNodes = j - postStart + 1;

    root->left = constructUsingMap(preStart + 1, postStart, preStart + numNodes, preorder, postorder, mp);
    root->right = constructUsingMap(preStart + numNodes + 1, j + 1, preEnd, preorder, postorder, mp);

    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n = preorder.size();
    // return construct(0,0,n-1,preorder,postorder);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[postorder[i]] = i;
    }
    return constructUsingMap(0, 0, n - 1, preorder, postorder, mp);
}