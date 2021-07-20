#include <cstdio>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool isNumber(char c) {
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') return true;
    else return false;
}

int main() {
    stack <int> num;
    stack <char> op;
    string infix;
    cin >> infix;

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') continue;
        else if (isNumber(infix[i])) num.push((infix[i]) - '0');
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') op.push(infix[i]);
        else {
            int result, n1, n2;
            char oper;
            n1 = num.top();
            num.pop();
            n2 = num.top();
            num.pop();
            oper = op.top();
            op.pop();

            if (oper == '+') result = n1+n2;
            else if (oper == '-') result = n1-n2;
            else if (oper == '*') result = n1*n2;
            else result = result = n1/n2;
            
            num.push(result);
        }
    }
    
    cout << "result: " << num.top() << "\n";
    return 0;
}