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


// class Solution {
//   public:
//     void sort012(vector<int>& arr) {
//         // code here
//         sort(arr.begin(),arr.end());
//     }
// };



//              Pair Sum in a Sorted and Rotated Array

// class Solution {
//   public:
//     bool pairInSortedRotated(vector<int>& arr, int target) {
//         // code here
//         int pivot=0;
//         int n = arr.size();
        
//         for(int i=0; i<n-1;i++){
//             if(arr[i] > arr[i+1]){
//                 pivot =i+1;
//                 break;
//             }
//         }
        
//         int i = pivot;
//         int j = (pivot -1 +n)%n;
        
        
//         while (i != j){
//             int sum = arr[i] + arr[j];
//             if(sum == target) return true;
            
//             else if (sum<target){
//                 i = (i+1)%n;
//             }
//             else {
//                 j= (j-1+n)%n;
//             }
//         }
//         return false;
        
//     }
// };


//                  Floor in a Sorted Array


// class Solution {
// public:
//     int findFloor(vector<int>& arr, int x) {

//         int low = 0;
//         int high = arr.size() - 1;
//         int ans = -1;

//         while(low <= high) {

//             int mid = low + (high - low) / 2;

//             if(arr[mid] <= x) {
//                 ans = mid;          
//                 low = mid + 1;      
//             }
//             else {
//                 high = mid - 1;
//             }
//         }

//         return ans;
//     }
// };

//              Reverse array in groups

// class Solution {
//   public:
//     void reverseInGroups(vector<int> &arr, int k) {
//         int n = arr.size();

//         for (int i = 0; i < n; i += k) {
//             int start = i;
//             int end = min(i + k - 1, n - 1);

//             while (start < end) {
//                 swap(arr[start], arr[end]);
//                 start++;
//                 end--;
//             }
//         }
//     }
// };



//                Max Sum Subarray of size K
// class Solution {
// public:
//     int maxSubarraySum(vector<int>& arr, int k) {
//         int n = arr.size();
//         int windowSum = 0;
//         int maxSum = 0;

//         for (int i = 0; i < k; i++) {
//             windowSum += arr[i];
//         }
//         maxSum = windowSum;

//         for (int i = k; i < n; i++) {
//             windowSum += arr[i];        
//             windowSum -= arr[i - k];    
//             maxSum = max(maxSum, windowSum);
//         }
//         return maxSum;
//     }
// };


// First Repeated Character

// class Solution {
// public:
//     string firstRepChar(string s) {
//         unordered_set<char> st;

//         for (char ch : s) {
//             if (st.count(ch))
//                 return string(1, ch);
//             st.insert(ch);
//         }

//         return "-1";
//     }
// };
