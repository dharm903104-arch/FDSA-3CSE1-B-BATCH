#include <iostream>
#include <string>

using namespace std;

class IntStack {
private:
    int arr[100];
    int topIndex;
public:
    IntStack()
    {
        topIndex = -1;
    }
    
    void push(int val) { 
        arr[++topIndex] = val; 
    }
    
    int pop() { 
        if(topIndex >= 0)
        {
            return arr[topIndex--];
        }
        return -9999; 
    }
    
    bool hasAtLeastTwo() {
        return topIndex >= 1;
    }
    
    bool isEmpty() { 
        return topIndex == -1; 
    }
    
    int top() {
        return (topIndex >= 0) ? arr[topIndex] : -9999;
    }
};

int main() {
    IntStack stack;
    string postfix;

    cout << "--- Postfix Expression Evaluator ---\n";
    cout << "Enter a postfix expression (single-digit numbers, e.g., 53+82-*): ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++) {
        char current = postfix[i];

        if(current >= '0' && current <= '9')
        {
            stack.push(current - '0');
        }
        else if(current == '+' || current == '-' || current == '*' || current == '/')
        {
            if(!stack.hasAtLeastTwo())
            {
                cout << "Error: Malformed expression! Not enough operands for operator '" << current << "'.\n";
                return 1; 
            }

            int val2 = stack.pop(); 
            int val1 = stack.pop(); 
            int result = 0;

            switch(current)
            {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if(val2 == 0)
                    {
                        cout << "Error: Division by zero!\n";
                        return 1;
                    }
                    result = val1 / val2; 
                    break;
            }
            stack.push(result);
        }
    }

    int finalAnswer = stack.pop();
    
    if(!stack.isEmpty())
    {
        cout << "Error: Malformed expression! Too many operands left over.\n";
    }
    else
    {
        cout << "Final Evaluated Result: " << finalAnswer << "\n";
    }

    return 0;
}