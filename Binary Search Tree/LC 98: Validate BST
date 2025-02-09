//  //This Apporach of checking only with root will not work as what if the subtree is not a BST
//     bool isValidBST(TreeNode* root) {
//         if(!root) return true;
//         if(root->left && root->left->val>=root->val){
//             return false;
//         }
//         else if(root->right && root->right->val<=root->val){
//             return false;
//         }
//         return isValidBST(root->left)||isValidBST(root->right);
//     }

//By passing value 
class Solution {
    private: bool helper(TreeNode* root, long min, long max){
        if(root==NULL) return true;
        if(root->val<=min || root->val>=max) return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }

// Approach: Instead of checking only with 1 ele(root) check with 2ele(range)
    public: bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// By Passing TreeNode 
class Solution {
    private: bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root==NULL) return true;
        if((min!=NULL && root->val<=min->val) || (max!=NULL && root->val>=max->val)) return false;
        return helper(root->left, min, root) && helper(root->right, root, max);
    }

    public: bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};
//Different ways of writing same code
class Solution {
    private: bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root==NULL) return true;
        if((min==NULL || root->val>min->val) && (max==NULL || root->val<max->val)) 
            return helper(root->left, min, root) && helper(root->right, root, max);
        return false;
    }

    public: bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};
