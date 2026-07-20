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

//               700. Search in a Binary Search Tree


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
        return NULL;
        if(root->val==val)
        return root;
        if(root->val<val)
        return searchBST(root->right,val);
        return searchBST(root->left, val);
        
    }
};

//                    938. Range Sum of BST


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;

        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        if(root->val > high)
            return rangeSumBST(root->left, low, high);

        return root->val 
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
};




         // 108. Convert Sorted Array to Binary Search Tree

class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r){
        if(l > r) return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};

//                  701. Insert into a Binary Search Tree

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        if(val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }
};