#include <iostream>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

// Node structure for singly linked list
struct Node {
    char data;
    Node* next;
};

// Push function to add an element to the stack
void push(Node*& top, char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function to remove an element from the stack
char pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack underflow!\n";
        return -1;
    }
    char value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

// Peek function to view the top element of the stack
char peek(Node* top) {
    return top ? top->data : -1;
}

// Check if the stack is empty
bool isEmpty(Node* top) {
    return top == nullptr;
}

// Function to check operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix
void infixToPostfix(const char* infix, char* postfix) {
    Node* stack = nullptr; // Stack for operators
    int j = 0; // Index for postfix

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) { // Operand
            postfix[j++] = token;
        } else if (token == '(') { // Left parenthesis
            push(stack, token);
        } else if (token == ')') { // Right parenthesis
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Remove '('
        } else if (isOperator(token)) { // Operator
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(token)) {
                postfix[j++] = pop(stack);
            }
            push(stack, token);
        }
    }

    // Pop remaining operators
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0'; // Null-terminate postfix string
}

// Reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        swap(str[i], str[len - i - 1]);
    }
}

// Convert infix to prefix
void infixToPrefix(const char* infix, char* prefix) {
    char revInfix[100], revPostfix[100];

    strcpy(revInfix, infix);
    reverseString(revInfix);

    // Reverse brackets
    for (int i = 0; revInfix[i] != '\0'; i++) {
        if (revInfix[i] == '(') revInfix[i] = ')';
        else if (revInfix[i] == ')') revInfix[i] = '(';
    }

    infixToPostfix(revInfix, revPostfix); // Convert reversed infix to postfix
    reverseString(revPostfix); // Reverse postfix to get prefix
    strcpy(prefix, revPostfix);
}

// Evaluate postfix expression
int evaluatePostfix(const char* postfix) {
    Node* stack = nullptr;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        if (isdigit(token)) { // Operand
            push(stack, token - '0');
        } else if (isOperator(token)) { // Operator
            int b = pop(stack);
            int a = pop(stack);
            switch (token) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': push(stack, a / b); break;
                case '^': push(stack, pow(a, b)); break;
            }
        }
    }

    return pop(stack); // Result
}

// Evaluate prefix expression
int evaluatePrefix(const char* prefix) {
    Node* stack = nullptr;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char token = prefix[i];

        if (isdigit(token)) { // Operand
            push(stack, token - '0');
        } else if (isOperator(token)) { // Operator
            int a = pop(stack);
            int b = pop(stack);
            switch (token) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': push(stack, a / b); break;
                case '^': push(stack, pow(a, b)); break;
            }
        }
    }

    return pop(stack); // Result
}

int main() {
    char infix[100], postfix[100], prefix[100];

    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    // Convert infix to prefix
    infixToPrefix(infix, prefix);
    cout << "Prefix expression: " << prefix << endl;

    // Evaluate postfix expression
    cout << "Postfix evaluation result: " << evaluatePostfix(postfix) << endl;

    // Evaluate prefix expression
    cout << "Prefix evaluation result: " << evaluatePrefix(prefix) << endl;

    return 0;
}
