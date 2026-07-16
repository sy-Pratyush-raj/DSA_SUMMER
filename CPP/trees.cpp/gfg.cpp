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