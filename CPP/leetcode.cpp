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

//               26. Remove Duplicates from Sorted Array



// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() == 0) return 0;

//         int k = 1;   

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] != nums[i - 1]) {
//                 nums[k] = nums[i];
//                 k++;
//             }
//         }
//         return k;
//     }
// };


//                       88. Merge Sorted Array


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1;
//         int j = n - 1;
//         int k = m + n - 1;

//         while (i >= 0 && j >= 0) {
//             if (nums1[i] > nums2[j]) {
//                 nums1[k] = nums1[i];
//                 i--;
//             } else {
//                 nums1[k] = nums2[j];
//                 j--;
//             }
//             k--;
//         }

//         while (j >= 0) {
//             nums1[k] = nums2[j];
//             j--;
//             k--;
//         }
//     }
// };

// 34. Find First and Last Position of Element in Sorted Array


// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int first = -1, last = -1;

//         int l = 0, r = n - 1;
//         while (l <= r) {
//             int mid = (l + r) / 2;
//             if (nums[mid] == target) {
//                 first = mid;
//                 r = mid - 1;
//             } else if (nums[mid] < target) {
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }

//         l = 0; r = n - 1;
//         while (l <= r) {
//             int mid = (l + r) / 2;
//             if (nums[mid] == target) {
//                 last = mid;
//                 l = mid + 1;
//             } else if (nums[mid] < target) {
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }

//         return {first, last};
//     }

//  };


//                         7. Reverse Integer



// class Solution {
// public:
//     int reverse(int x) {
//         long long rev = 0;

//         while(x != 0){
//             rev = rev * 10 + x % 10;
//             x /= 10;
//         }

//         if(rev > INT_MAX || rev < INT_MIN)
//             return 0;

//         return rev;
//     }
// };

//                       53. Maximum Subarray

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {

//         int currSum =0;
//         int maxSum =  nums[0];

//         for(int i=0; i<nums.size(); i++){
//             currSum += nums[i];

//             if(currSum > maxSum) maxSum = currSum;

//             if(currSum < 0) currSum =0;

//         }
//         return maxSum;   
//     }
// };

//                      875. Koko Eating Bananas


// class Solution {
// public:
//     bool isPos(vector<int>& piles, int hours, long long speed){
//         for(int i=0; i<piles.size(); i++){
//             int time_for_this_pile=(piles[i]/speed);
//             time_for_this_pile = time_for_this_pile + (piles[i]%speed !=0 ? 1:0);
//             hours-=time_for_this_pile;
//         }
//         if(hours<0)
//             return false;
//         return true;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         long long l=1 , r=1e9;
//         while (l<r){
//             long long mid = (l+r)/2;
//             if(isPos(piles, h , mid))
//             r = mid;
//             else 
//             l = mid+1;
//         }
//         return l;
    
        
//     }
// };

             // 84. Largest Rectangle in Histogram


// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         stack<int> st;
//         int n = heights.size(), area = 0;

//         for(int i = 0; i <= n; i++) {
//             int h = (i == n ? 0 : heights[i]);

//             while(!st.empty() && heights[st.top()] > h) {
//                 int height = heights[st.top()];
//                 st.pop();
//                 int width = st.empty() ? i : i - st.top() - 1;
//                 area = max(area, height * width);
//             }
//             st.push(i);
//         }
//         return area;
//     }
// };


//                       392. Is Subsequence



// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int i = 0, j = 0;

//         while (i < s.length() && j < t.length()) {
//             if (s[i] == t[j]) {
//                 i++;
//             }
//             j++;
//         }

//         return i == s.length();
//     }
// };

                // 876. Middle of the Linked List

// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         return slow;
//     }
// };


//                   206. Reverse Linked List


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* next = NULL;

//         while (curr != NULL) {
//             next = curr->next;   
//             curr->next = prev;   
//             prev = curr;        
//             curr = next;         
//         }

//         return prev;
//     }
// };


//                     160. Intersection of Two Linked Lists

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(!headA || !headB) return nullptr;

//         ListNode *a = headA;
//         ListNode *b = headB;

//         while(a != b) {
//             a = (a == nullptr) ? headB : a->next;
//             b = (b == nullptr) ? headA : b->next;
//         }

//         return a; 
//     }
// };



//                            141. Linked List Cycle



// class Solution {
// public:
//     bool hasCycle(ListNode *head) {

//         ListNode* slow = head;
//         ListNode* fast = head;


//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

//                 328. Odd Even Linked List


// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {

//         if (head == NULL || head->next == NULL) {
//             return head;
//         }

//         ListNode* odd = head;
//         ListNode* even = head->next;
//         ListNode* evenHead = even;

//         while (even != NULL && even->next != NULL) {
//             odd->next = even->next;
//             odd = odd->next;

//             even->next = odd->next;
//             even = even->next;
//         }

//         odd->next = evenHead;

//         return head;
//     }
// };


//                 19. Remove Nth Node From End of List


// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;

//         ListNode* fast = dummy;
//         ListNode* slow = dummy;

//         for(int i = 0; i < n; i++){
//             fast = fast->next;
//         }

//         while(fast->next != nullptr){
//             fast = fast->next;
//             slow = slow->next;
//         }
//         slow->next = slow->next->next;

//         return dummy->next;
//     }
// };





//                           86. Partition List


// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {

//         ListNode* beforeHead = new ListNode(0);
//         ListNode* afterHead = new ListNode(0);

//         ListNode* before = beforeHead;
//         ListNode* after = afterHead;

//         while (head != NULL) {

//             if (head->val < x) {
//                 before->next = head;
//                 before = before->next;
//             } else {
//                 after->next = head;
//                 after = after->next;
//             }

//             head = head->next;
//         }

//         after->next = NULL;
//         before->next = afterHead->next;

//         return beforeHead->next;
//     }
// };

//                       86. Partition List

// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         ListNode* left = new ListNode(-1);
//         ListNode* right = new ListNode(-1);

//         ListNode* lp = left;
//         ListNode* rp = right;

//         ListNode* temp = head;

//         while(temp != NULL){
//             if(temp->val < x){
//                 left -> next = temp;
//                 left = left -> next;
//             }else{
//                 right -> next = temp;
//                 right = right-> next;
//             }
//             temp = temp ->next;
//         }
//         right -> next = NULL;
//         left -> next = rp->next;

//         return lp->next;
//     }      
// };



//                   25. Reverse Nodes in k-Group


// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp = head;
        
//         for(int i = 0; i < k; i++) {
//             if(!temp) return head;
//             temp = temp->next;
//         }
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         for(int i = 0; i < k; i++) {
//             ListNode* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         head->next = reverseKGroup(curr, k);
//         return prev;
//     }
// };





















