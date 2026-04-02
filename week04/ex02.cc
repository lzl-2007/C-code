#include<iostream>

//数组取数
int max(int x,int y){
    return x>y?x:y;
}
int N;
int arr[10][10]={0};
int f[10][10][10][10];
int calculate(int x1,int x2,int y1,int y2){
    int M=0;
    if (f[x1][x2][y1][y2]!=-1)return f[x1][x2][y1][y2];
    if (x1==N&&x2==N&&y1==N&&y2==N)
        return 0;
    if (x1<N&&x2<N){
        M=max(M,calculate(x1+1,x2+1,y1,y2)+arr[x1+1][y1]+arr[x2+1][y2]-arr[x1+1][y1]*(x1==x2 && y1==y2));
    }
    if (y1<N && x2<N){
        M=max(M,calculate(x1,x2+1,y1+1,y2)+arr[x1][y1+1]+arr[x2+1][y2]-arr[x1][y1+1]*(x1==x2+1 && y1+1==y2));
    }
    if (y2<N && x1<N){
        M=max(M,calculate(x1+1,x2,y1,y2+1)+arr[x1+1][y1]+arr[x2][y2+1]-arr[x1+1][y1]*(x1+1==x2 && y1==y2+1));
    }
    if (y2<N && y2<N){
        M=max(M,calculate(x1,x2,y1+1,y2+1)+arr[x1][y1+1]+arr[x2][y2+1]-arr[x1][y1+1]*(x1==x2 && y1==y2));
    }
    f[x1][x2][y1][y2]=M;
    return M;
}
int main(){
    std::cin>>N;
    for (int i=0;i<N+1;i++){
        for (int j=0;j<N+1;j++){
            for (int k=0;k<N+1;k++){
                for (int l=0;l<N+1;l++)f[i][j][k][l]=-1;
            }
        }
    }
    while (1){
        int a1,a2,a3;
        std::cin>>a1>>a2>>a3;
        if (a1==a2 && a2==a3 && a1==0)break;
        arr[a1][a2]=a3;
    }
    int maxnum=calculate(1,1,1,1);
    std::cout<<maxnum+arr[1][1];
    return 0;
}
