//                      Largest in Array using STL

// class Solution {
//   public:
//     int largest(vector<int> &arr) {
//         return *max_element(arr.begin(), arr.end());
//     }
// };

//                       Largest in Array without STL

// int largest(vector<int> &arr) {
//     int maxi = arr[0];

//     for(int i = 1; i < arr.size(); i++) {
//         if(arr[i] > maxi) {
//             maxi = arr[i];
//         }
//     }

//     return maxi;
// }


//                       Second Largest

// class Solution {
//   public:
//     int getSecondLargest(vector<int> &arr) {
//         int largest = -1;
//         int secondLargest = -1;

//         for(int i = 0; i < arr.size(); i++) {
//             if(arr[i] > largest) {
//                 secondLargest = largest;
//                 largest = arr[i];
//             }
//             else if(arr[i] > secondLargest && arr[i] != largest) {
//                 secondLargest = arr[i];
//             }
//         }

//         return secondLargest;
//     }
// };
