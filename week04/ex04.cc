#include<iostream>
#include<cmath>
int N=0,M=0;
int arr[80][80]={0};
int max(int a,int b){
    return a>b?a:b;
}
int calculate(int m,int n,int codeing){
    int Max=0;
    if (m==1){
        for (int i=0;i<n;i++){
            Max+=pow(2,M)*arr[i][codeing];
        }
    }
    else{
        for (int i=0;i<int(pow(2,N));i++){
            int tem=0;
            int code=0;
            for (int j=0;j<N;j++){
                if (i%(int(pow(2,j)))==0){
                    tem+=arr[j][code]*pow(2,M-m+1);
                    code++;
                }
                else {
                    tem+=arr[j][code+m-1]*pow(2,M-m+1);
                }
                tem+=calculate(m-1,n,code);
                
            }
            if (tem>Max){
                Max=tem;
            }
        }
    }
    return Max;
}
int main(){
    std::cin>>N>>M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            std::cin>>arr[i][j];
        }
    }
    int y=calculate(M,N,0);
    std::cout<<y;
    return 0;
}