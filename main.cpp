#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

// ---------- Utility Functions ----------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// ---------- Tokenization ----------
vector<char> tokenize(const string &expression) {
    vector<char> tokens;
    for (char c : expression) {
        if (c != ' ') tokens.push_back(c);
    }
    return tokens;
}

// ---------- Shunting Yard Algorithm ----------
queue<char> infixToPostfix(const vector<char> &tokens) {
    stack<char> opStack;
    queue<char> outputQueue;

    for (char token : tokens) {
        if (isdigit(token)) {
            outputQueue.push(token);
        }
        else if (isOperator(token)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(token)) {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
        else if (token == '(') {
            opStack.push(token);
        }
        else if (token == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); // remove '('
        }
    }

    while (!opStack.empty()) {
        outputQueue.push(opStack.top());
        opStack.pop();
    }

    return outputQueue;
}

// ---------- Postfix Evaluation ----------
int evaluatePostfix(queue<char> postfix) {
    stack<int> st;

    while (!postfix.empty()) {
        char token = postfix.front();
        postfix.pop();

        if (isdigit(token)) {
            st.push(token - '0'); // convert char to int
        } 
        else if (isOperator(token)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (token) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    return st.top();
}

// ---------- Main ----------
int main() {
    string expression;
    cout << "Enter an expression (e.g. 3+(2*4)-5): ";
    cin >> expression;

    vector<char> tokens = tokenize(expression);
    queue<char> postfix = infixToPostfix(tokens);
    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;
    return 0;
}