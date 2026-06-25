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


// Triplet Sum in Array



// class Solution {
// public:
//     bool hasTripletSum(vector<int> &arr, int target) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());

//         for (int i = 0; i < n - 2; i++) {
//             int left = i + 1;
//             int right = n - 1;

//             while (left < right) {
//                 int sum = arr[i] + arr[left] + arr[right];

//                 if (sum == target)
//                     return true;
//                 else if (sum < target)
//                     left++;
//                 else
//                     right--;
//             }
//         }
//         return false;
//     }
// };


//                    Sort 0s, 1s and 2s


class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
    }
};
