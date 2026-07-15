//                    20. Valid Parentheses

// class Solution {
//     public:
//         bool isValid(string s) {
//             stack<char>st;

//             for(char ch : s){
//                 if(ch == '(' || ch =='{' || ch == '['){
//                     st.push(ch);
//                 }else{
//                     if(st.empty()) return false;

//                     char top =st.top();
//                     if(ch==')' && top =='('||
//                     ch=='}' && top =='{'||
//                     ch==']' && top=='['){
//                         st.pop();
//                     }else{
//                         return false;
//                     }
//                 }
//             }
//             return st.empty();
//         }
// };

//                        155. Min Stack

// class MinStack {
// public:
//     stack<int> mainStack;
//     stack<int> minStack;

//     MinStack() {

//     }

//     void push(int value) {

//         mainStack.push(value);

//         if (minStack.empty() || value <= minStack.top()) {
//             minStack.push(value);
//         }
//     }

//     void pop() {

//         if (mainStack.top() == minStack.top()) {
//             minStack.pop();
//         }

//         mainStack.pop();
//     }

//     int top() {

//         return mainStack.top();
//     }


//     int getMin() {

//         return minStack.top();
//     }
// };

//                   496. Next Greater Element I

// #include <vector>
// #include <stack>
// #include <unordered_map>
// using namespace std;

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int,int> mp;
//         stack<int> st;

//         for(int n : nums2){
//             while(!st.empty() && st.top() < n){
//                 mp[st.top()] = n;
//                 st.pop();
//             }
//             st.push(n);
//         }

//         vector<int> ans;
//         for(int n : nums1)
//             ans.push_back(mp.count(n) ? mp[n] : -1);

//         return ans;
//     }
// };


//                84. Largest Rectangle in Histogram


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

//                          735. Asteroid Collision


// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {

//         stack<int> st;

//         for (int i : asteroids) {

//             bool destroyed = false;

//             while (!st.empty() && st.top() > 0 && i < 0) {

//                 int topVal = st.top();

//                 if (abs(topVal) < abs(i)) {
//                     st.pop();
//                 }
//                 else if (abs(topVal) > abs(i)) {
//                     destroyed = true;
//                     break;
//                 }
//                 else {
//                     st.pop();
//                     destroyed = true;
//                     break;
//                 }
//             }

//             if (!destroyed) {
//                 st.push(i);
//             }
//         }

//         vector<int> ans(st.size());

//         for (int i = st.size() - 1; i >= 0; i--) {
//             ans[i] = st.top();
//             st.pop();
//         }

//         return ans;
//     }
// };

