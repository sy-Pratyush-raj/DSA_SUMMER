#include<iostream>
#include<stack>
using namespace std;

void reverseString(string str){
    stack<string> st;

    for(int i = 0; i < str.length(); i++){

        if(str[i] == ' ')
            continue;

        string ans = "";

        while(i < str.length() && str[i] != ' '){
            ans += str[i];
            i++;
        }

        st.push(ans);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){

    string str = "Hello How Are You";

    reverseString(str);

    return 0;
}