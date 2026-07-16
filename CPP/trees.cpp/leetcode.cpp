// 
//                 404. Sum of Left Leaves


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        // Base Case
        if(root == nullptr){
            return 0;
        }

        int sum = 0;

        // Check if left child is a leaf
        if(root->left != nullptr &&
           root->left->left == nullptr &&
           root->left->right == nullptr){

            sum += root->left->val;
        }

        // Recursively calculate left and right subtree
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};