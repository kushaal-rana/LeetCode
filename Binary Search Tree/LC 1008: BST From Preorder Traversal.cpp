// Problem Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if(start>end) return NULL;

        TreeNode* root = new TreeNode(preorder[start]);
        
        int idx = start;
        // for( idx=start;idx<=end;idx++){ //idx is where the right subtree starts
        //     if(preorder[idx]>preorder[start]) break;
        // }

         //get the index of the element greater then root for the right subtree to starts
        int index = upper_bound(preorder.begin()+start, preorder.end(), preorder[start])-preorder.begin();


        root->left = helper(preorder, start+1, idx-1);//since start is root, also from idx right subtree starts 
        root->right = helper(preorder, idx, end);

        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0, preorder.size()-1); 
    }
};