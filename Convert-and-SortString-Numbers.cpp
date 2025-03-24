// 2. {"1","15","4","6","23","19","3"} sort this without using the atoi or stoi or built in function.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int cvtstr(string character){
    int num = 0;

// this is similar to the thing that we do in the palindrome also to get the number.
    for(char digit : character){
        num = num*10 + digit-'0';
    }
    return num;
}

int main() {
    string value[] = {"1","15","4","6","23","19","3"};
// length() is only avaialbe for the string and the container for the arrays you will have to use the sizeof operator.
    int n = sizeof(value)/sizeof(value[0]);
    vector<int> result;
    for(int i=0;i<n;i++){
        result.push_back(cvtstr(value[i]));
    }
    
    sort(result.begin(),result.end());
    
    for(int num:result){
        cout<<num<<endl;
    }
} 
