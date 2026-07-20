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

//                653. Two Sum IV - Input is a BST


class Solution {
public:

    void inorder(TreeNode* root, vector<int>& nums){

        if(root == NULL)
            return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> nums;

        inorder(root, nums);

        int i = 0;
        int j = nums.size() - 1;

        while(i < j){

            int sum = nums[i] + nums[j];

            if(sum == k)
                return true;

            else if(sum < k)
                i++;

            else
                j--;
        }

        return false;
    }
};


//              230. Kth Smallest Element in a BST

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;

        while(true){
            while(root){
                st.push(root);
                root = root->left;
            }

            root = st.top(); 
            st.pop();

            if(--k == 0) return root->val;

            root = root->right;
        }
    }
};

//            98. Validate Binary Search Tree

class Solution {
public:
    bool check(TreeNode* root, long long low, long long high){
        if(!root) return true;

        if(root->val <= low || root->val >= high)
            return false;

        return check(root->left, low, root->val) &&
               check(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};


//                    450. Delete Node in a BST


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* temp = root->right;
            while(temp->left) temp = temp->left;  
            
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};
