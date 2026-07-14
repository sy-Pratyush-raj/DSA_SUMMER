//                                 prefix

// #include<iostream>
// #include<stack>
// using namespace std;

// int prefixEval(string s){
//     // create a stack

//     //traverse from right to left 

//     //if s[i] is operand -> push in the stack

//     // else if it is operator -> create two variable to store two elements,
//     // pop  them and evaluate with operator, them push the resulant back in stack

//     // return the last remaining elements from stack -> it is the ans 

//     stack<int > st;
//     for(int i = s.length()-1; i>=0;i--){
//         if(s[i] >= '0' && s[i]<= '9' ){
//             st.push(s[i] -'0');
//         }else{
//             int operand1 = st.top();
//             st.pop();
//             int operand2 = st.top();
//             st.pop();

//             switch (s[i])
//             {
//             case '+':
//                 st.push(operand1 - operand2);
//                 break;
            
//             case '*':
//                 st.push(operand1 * operand2);
//                 break;

//             case '/':
//                 st.push(operand1 / operand2);
//                 break;

//             case '^':
//                 st.push(operand1 ^ operand2);
//                 break;
            
            
//             }
//         }
//     }
//     return st.top();
// }
// int main(){
//     string s = "-+7*45+20";
// }