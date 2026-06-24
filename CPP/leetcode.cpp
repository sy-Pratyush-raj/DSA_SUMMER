//                    485. Max Consecutive Ones

// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int count = 0;
//         int maxi = 0;

//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == 1) {
//                 count++;
//                 maxi = max(maxi, count);
//             } else {
//                 count = 0;
//             }
//         }

//         return maxi;
//     }
// };

// class Solution{
//     public:
//     int findMaxConsecutiveOnes(vector<int> &nums){
//         int count , maxcount =0;

//         for(int i : nums){
//             if(i==1){
//                 count++;
//                 maxcount = max(maxcount, count);
//             }else {
//                 count=0;
//             }
//         }
//         return maxcount;
//     }
// };
