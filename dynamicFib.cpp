//Memoized solution
#include<iostream>

using namespace std;

int fib(int n, int mem[]){
    int result=0;
    if(mem[n]!=0){
        return mem[n];
    }
    if(n==1 || n==2){
        result=1;
    }
    else{
        result=fib(n-1,mem)+fib(n-2,mem);
    }

    mem[n]=result;

    return result;
}

int main(){

    int a;
    /*cout << "which fib do you wanna find" << endl;
    cin>> a;*/

    a=33;

    int mem[a+1];
    int i;
    for(i=0;i<a+1;i++){
        mem[i]=0;
    }
    int ans;
    ans=fib(a, mem);

    cout << ans << endl;


}
