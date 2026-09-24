#include <iostream>
#include <string>

using namespace std;

class CharStack {
private:
    char arr[100];
    int topIndex;
public:
    CharStack()
    {
        topIndex = -1;
    }
    void push(char c)
    { 
        arr[++topIndex] = c;
    }
    void pop()
    {
        if(topIndex >= 0) topIndex--; 
    }
    char top()
    {
        return (topIndex >= 0) ? arr[topIndex] : '\0';
    }
    bool isEmpty()
    {
        return topIndex == -1;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    CharStack stack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char current = infix[i];

        if (current == ' ') continue;

        if(isalnum(current))
        {
            postfix += current;
        }
        else if (current == '(')
        {
            stack.push(current);
        }
        else if (current == ')')
        {
            while(!stack.isEmpty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            if(!stack.isEmpty() && stack.top() == '(')
            {
                stack.pop();
            }
        }
        else
        {
            while(!stack.isEmpty() && precedence(stack.top()) >= precedence(current))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(current);
        }
    }

    while(!stack.isEmpty())
    {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "--- Infix to Postfix Converter ---\n";
    cout << "Enter an infix expression (e.g., A+B*C or (3+4)*2): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    
    cout << "Original Infix:  " << infix << "\n";
    cout << "Converted Postfix: " << postfix << "\n";

    return 0;
}