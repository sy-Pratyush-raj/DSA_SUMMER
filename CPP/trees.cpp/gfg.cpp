//                   Height of Binary Tree



// class Solution {
//   public:
//     int height(Node* root) {
        
//         // Height in terms of edges
//         if(root == nullptr){
//             return -1;
//         }
        
//         return max(height(root->left), height(root->right)) + 1;
//     }
// };

//                         Top View of Binary Tree

class Solution {
  public:
    vector<int> topView(Node *root) {

        vector<int> ans;

        if(root == NULL)
            return ans;

        // key = Horizontal Distance
        // value = Node data
        map<int, int> topNode;

        // Queue stores {Node, Horizontal Distance}
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while(!q.empty()){

            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // Store only the first node at each HD
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }

            if(frontNode->left){
                q.push({frontNode->left, hd - 1});
            }

            if(frontNode->right){
                q.push({frontNode->right, hd + 1});
            }
        }

        // Store answer from leftmost HD to rightmost HD
        for(auto it : topNode){
            ans.push_back(it.second);
        }

        return ans;
    }
};

//                        Tree Boundary Traversal


class Solution {
  public:

    void traverseLeft(Node *root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);

        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeaf(Node *root, vector<int> &ans){
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node *root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        if(root == NULL)
            return ans;

        // Add root only if it is not a leaf
        if(!(root->left == NULL && root->right == NULL))
            ans.push_back(root->data);

        traverseLeft(root->left, ans);
        traverseLeaf(root, ans);
        traverseRight(root->right, ans);

        return ans;
    }
};

//                 K distance from root

class Solution {
  public:
  
    void traverse(Node* root, int k, vector<int> &ans){
        
        if(root == NULL)
            return;
        
        if(k == 0){
            ans.push_back(root->data);
        }
        
        traverse(root->left, k - 1, ans);
        traverse(root->right, k - 1, ans);
    }
  
    vector<int> kdistance(int k, Node *root) {
        
        vector<int> ans;
        
        traverse(root, k, ans);
        
        return ans;
    }
};

