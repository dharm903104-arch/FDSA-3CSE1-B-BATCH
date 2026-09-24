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
    
    void push(char c) { 
        arr[++topIndex] = c; 
    }
    
    char pop() { 
        if(topIndex >= 0)
        {
            return arr[topIndex--];
        }
        return '\0';
    }
    
    bool isEmpty() { 
        return topIndex == -1; 
    }
};

bool isMatchingPair(char opening, char closing) {
    if(opening == '(' && closing == ')') return true;
    if(opening == '{' && closing == '}') return true;
    if(opening == '[' && closing == ']') return true;
    return false;
}

int main() {
    CharStack stack;
    string expression;

    cout << "--- Code Editor Bracket Validator ---\n";
    cout << "Enter a string of brackets (e.g., {()[{}]} or press Enter for empty): ";
    
    getline(cin, expression);

    bool isValid = true;

    for(int i = 0; i < expression.length(); i++) {
        char current = expression[i];

        if(current == '(' || current == '{' || current == '[')
        {
            stack.push(current);
        }
        else if(current == ')' || current == '}' || current == ']')
        {

            if(stack.isEmpty())
            {
                isValid = false;
                break; 
            }
            
            char topBracket = stack.pop();
            if(!isMatchingPair(topBracket, current))
            {
                isValid = false;
                break;
            }
        }
    }

    if(!stack.isEmpty())
    {
        isValid = false;
    }

    if(isValid)
    {
        cout << "Output: Yes (Valid)\n";
    }
    else
    {
        cout << "Output: No (Invalid)\n";
    }

    return 0;
}