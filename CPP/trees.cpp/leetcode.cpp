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




//                102. Binary Tree Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int levelSize = q.size();
            vector<int> levelElements;

            for(int i = 0; i < levelSize; i++){

                TreeNode* frontNode = q.front();
                q.pop();

                levelElements.push_back(frontNode->val);

                if(frontNode->left)
                    q.push(frontNode->left);

                if(frontNode->right)
                    q.push(frontNode->right);
            }

            result.push_back(levelElements);
        }

        return result;
    }
};


//        103. Binary Tree Zigzag Level Order Traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){

            int levelSize = q.size();
            vector<int> levelElements;

            for(int i = 0; i < levelSize; i++){

                TreeNode* frontNode = q.front();
                q.pop();

                levelElements.push_back(frontNode->val);

                if(frontNode->left)
                    q.push(frontNode->left);

                if(frontNode->right)
                    q.push(frontNode->right);
            }

            if(!leftToRight){
                reverse(levelElements.begin(), levelElements.end());
            }

            result.push_back(levelElements);

            leftToRight = !leftToRight;
        }

        return result;
    }
};