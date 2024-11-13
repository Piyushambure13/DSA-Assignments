#include<iostream>
#include <stack>
#include <algorithm>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is a number or letter, add it to the postfix string
        if (isalnum(c))
            postfix += c;

        // If the character is '(', push it to the stack
        else if (c == '(')
            st.push('(');
        // If the character is ')', pop from the stack until '(' is encountered
        else if (c == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        // If an operator is encountered
        else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // Pop all remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}
int evaluation_postfix(string postfix)
{
    stack<int> st2;
    for (int i = 0; i < postfix.size(); i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(postfix[i])) {
            st2.push(postfix[i] - '0');
        }
        else {
            int val1 = st2.top();
            st2.pop();
            int val2 = st2.top();
            st2.pop();
            switch (postfix[i]) {
                case '+':
                    st2.push(val2 + val1);
                    break;
                case '-':
                    st2.push(val2 - val1);
                    break;
                case '*':
                    st2.push(val2 * val1);
                    break;
                case '/':
                    st2.push(val2 / val1);
                    break;
            }
        }
    }
    return st2.top();
}
string infixToPrefix(string infix)
{
    long l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int evaluation_infix(){
    
    return 0;
}
int main()
{
    string infix ;
    cout<<"Input Your String :"<<endl;
    cin>>infix;
    
    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);
    
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << prefix << endl;
    
    // Pass the postfix expression for evaluation
    cout << "Evaluation of Postfix Expression: " << evaluation_postfix(postfix) << endl;
    return 0;
}
