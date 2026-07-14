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

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;

        for(int n : nums2){
            while(!st.empty() && st.top() < n){
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        vector<int> ans;
        for(int n : nums1)
            ans.push_back(mp.count(n) ? mp[n] : -1);

        return ans;
    }
};

