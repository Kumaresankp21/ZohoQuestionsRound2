//1. "6789 +*-"; evaluate this string wihtout using the stoi or the atoi without any built in function.
//the opeartor precendence is not required. (6+7*8-9)

//code:
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluate(int x,int y,char op){
    switch(op){
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '/':
            return x/y;
        case '*':
            return x*y;
    }
    return 0;
}

int main() {
    string value = "6789 +*-";
    int n = value.length();
    int op = -1;
    int i=0;

//first finding the operator location because there is a space betweent he numbers and the operators
    while(i<n){
        if(value[i]==' '){
            op = i+1;
            break;
        }
        i++;
    }
  
    stack<int> result;

//storing the first element to the stack so that we can retrieve it later
    result.push(value[0]-'0'); // to get the actual number from the char '1' substract the '0' so that we get 1.
    
    for(int i=1;i<op-1;i++){

// if the operator position goes beyond the length of the string then just break.
        if(op>=n){
            break;
        }
        int top = result.top();
        result.pop();
        int res = evaluate(top,value[i]-'0',value[op]);
        result.push(res);
        op++;
    }
    cout << "Result: " << result.top() << endl;
    return 0;
} 
