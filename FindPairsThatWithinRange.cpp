// we need to find number of pairs(i,j) (i and j can overlap) such that number converted to a string then added(string concontenation) then if the resultant number lies between
// x and y  then it is a valid pair. find all such pairs.

// n=5,x=20,y=50,arr=[2,5,7,6,3]
// output
// 22
// 25
// 27
// 26
// 23
// 32
// 35
// 37
// 36
// 33
#include <iostream>
#include <map>
#include <vector>
#include <string>
// #include <pair>
#include <algorithm>
using namespace std;

string evaluate(string str1,int x,int y){
    string x1 = to_string(x);
    string y1 = to_string(y);
    if(str1>x1 and str1<y1) return str1;
    return "-1";
}

int main() {
   int n = 5;
   int x = 20;
   int y = 50;
   vector<int> array = {2,5,7,6,3};
   
   for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
           string str1 = to_string(array[i])+to_string(array[j]);
           string str2 = to_string(array[j])+to_string(array[i]);
           
           if(str1==str2){
               string result1 = evaluate(str1,x,y);
               if(result1!="-1") cout<<str1<<endl;
           }
           else{
           string result1 = evaluate(str1,x,y);
           string result2 = evaluate(str2,x,y);
           if(result1!="-1") cout<<str1<<endl;
           if(result2!="-1") cout<<str2<<endl;
           }
       }
   }
}
