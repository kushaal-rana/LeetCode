// Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:
    TreeNode* helper(vector<int> &preorder, int pre_st, int pre_end, vector<int> &inorder, int in_st, int in_end, map<int,int>& mp){
        if(pre_st>pre_end || in_st>in_end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pre_st]);
        int in_root_idx = mp[preorder[pre_st]];
        int num_in_left = in_root_idx-in_st;

        root->left = helper(preorder, pre_st+1, pre_st+num_in_left, inorder, in_st, in_root_idx-1,mp);
        root->right = helper(preorder, pre_st+num_in_left+1, pre_end, inorder, in_root_idx+1, in_end, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        //Taking map for storing the index of inorder values
        int n = preorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]] = i;
        return helper(preorder, 0, n-1, inorder, 0, n-1, mp);
    }
};