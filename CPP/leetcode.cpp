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




//                          283. Move Zeroes

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int k = 0;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] != 0) {
//                 nums[k] = nums[i];
//                 k++;
//             }
//         }
//         while (k < n) {
//             nums[k] = 0;
//             k++;
//         }
//     }
// };


// class Solution{
//     public:
//     void moveZeroes(vector<int> &nums){
//         int j =0;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]!=0){
//                 swap(nums[i],nums[j]);
//                 j++;
//             }
//         }
//     }
// };


// 167. Two Sum II - Input Array Is Sorted

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {

//         int i = 0;
//         int j = numbers.size() - 1;

//         while(i < j) {

//             int sum = numbers[i] + numbers[j];

//             if(sum == target)
//                 return {i + 1, j + 1};

//             else if(sum < target)
//                 i++;

//             else
//                 j--;
//         }

//         return {};
//     }
// };


// 121. Best Time to Buy and Sell Stock

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int minPrice = prices[0];
//         int maxProfit = 0;

//         for (int i = 0; i < prices.size(); i++) {
//             if (prices[i] < minPrice) {
//                 minPrice = prices[i];
//             } else {
//                 maxProfit = max(maxProfit, prices[i] - minPrice);
//             }
//         }
//         return maxProfit;
//     }
// };