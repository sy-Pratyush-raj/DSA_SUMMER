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



//                    199. Binary Tree Right Side View



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){

                TreeNode* frontNode = q.front();
                q.pop();

                // Last node of the current level
                if(i == levelSize - 1){
                    ans.push_back(frontNode->val);
                }

                if(frontNode->left)
                    q.push(frontNode->left);

                if(frontNode->right)
                    q.push(frontNode->right);
            }
        }

        return ans;
    }
};

//           236. Lowest Common Ancestor of a Binary Tree


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        if(root== p || root  ==q) return root;
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p,q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p,q);

        if(leftLCA && rightLCA){
            return root;
        }
        else if(leftLCA !=NULL) return leftLCA;
         else return rightLCA;   
        
     }
};