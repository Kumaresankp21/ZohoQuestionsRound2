// 3. print the following pattern
12345
23451
34512
45123
51234


int main() {
    int n=5;
    for(int row=1;row<=n;row++){
        int num = row;
        for(int col=1;col<=n;col++){
            num = num>n?num%n:num;
            cout<<num<<"";
            num++;
        }
        cout<<endl;
    }
}
