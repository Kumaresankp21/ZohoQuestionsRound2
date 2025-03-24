print the following code
*
 *
* *
 * *
* * *
 * * *
* * * *
 * * * *
* * * * *
 * * * * *
* * * * *
 * * * *
* * * *
 * * *
* * *
 * *
* *
 *
*

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int n=10;
    for(int row=1;row<=2*n-1;row++){
        int rowChange = row>n?(2*n-row):row;
        int starspace = row%2==0?0:1;
        for(int col=1;col<=rowChange;col++){
            if(starspace ==1){
                cout<<"*";
                starspace = !starspace;
            }
            else if(starspace ==0){
                cout<<" ";
                starspace = !starspace;
            }
        }
        cout<<endl;
    }
} 
