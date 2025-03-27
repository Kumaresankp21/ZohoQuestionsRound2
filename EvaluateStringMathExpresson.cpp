// evaluate the math expression inside the string "13-5/8" with the operator precedence;
// Expression: "3+5*2-8/4"
// Read 3 → Push to values: [3]

// Read + → Push to ops: [+]

// Read 5 → Push to values: [3, 5]

// Read * → Push to ops: [+, *]

// Read 2 → Push to values: [3, 5, 2]

// Process * (since * is higher precedence than +) →
// 5 * 2 = 10, so values = [3, 10]

// Read - → Push to ops: [+, -]

// Read 8 → Push to values: [3, 10, 8]

// Read / → Push to ops: [+, -, /]

// Read 4 → Push to values: [3, 10, 8, 4]

// Process / (since / is higher precedence than -) →
// 8 / 4 = 2, so values = [3, 10, 2]

// Process - (since only + is left) →
// 10 - 2 = 8, so values = [3, 8]

// Process + →
// 3 + 8 = 11

  
#include <iostream>
#include <stack>
using namespace std;

int calculate(int a,int b, char op){
    if (op == '+') return a + b;
    if (op == '-') return b - a;
    if (op == '*') return a * b;
    if (op == '/') return b / a;  // Assumes b != 0
    return 0;
}

int evaluate_expression(string expr){
    int n = expr.length();
    stack<int> values;
    stack<int> ops;
    for(int i=0;i<n;i++){
        if(isdigit(expr[i])){
            int num = 0;
            while(i<n and isdigit(expr[i])){
                num = num*10 + expr[i]-'0';
                i++;
            }
            i--;
            values.push(num);
        }
        else if(expr[i]=='+' or expr[i]=='-' or expr[i]=='*' or expr[i]=='/'){
    // if it is * or / evaluate the values first and update it
            while(!ops.empty() and ops.top() == '*' or ops.top()=='/'){
                int x = values.top();values.pop();
                int y = values.top();values.pop();
                char op = ops.top();ops.pop();
                values.push(calculate(x,y,op));
            }
            ops.push(expr[i]);
        }
    }
    
    while(!ops.empty()){
        int x = values.top();values.pop();
        int y = values.top();values.pop();
        char op = ops.top();ops.pop();
        values.push(calculate(x,y,op));
    }
    
    return values.top();
}

int main() {
    string expression = "13-5/8";
    cout << "Result: " << evaluate_expression(expression) << endl;
    return 0;
}
