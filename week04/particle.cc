#include<iostream>
struct ParticleA{
    float x,y,z;
    char padding[52];
    float vx,vy,vz;
};
struct ParticleB{
    float x,y,z;
    float vx,vy,vz;
    char padding[40];
};
#include<chrono>
#include<stdio.h>
#include<vector>
void measure(std::vector<ParticleA> &t){
    //create 1000000 particles
    auto start=std::chrono::high_resolution_clock::now();
    for (int i=0;i<1000000;i++){
        t[i].x+=t[i].vx;
        t[i].y+=t[i].vy;
        t[i].z+=t[i].vz;
    }
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli>diff=end-start;
    printf(" ParticleA took:%.2fms\n",diff.count());//不好意思，真的编译不了print
}
void measure(std::vector<ParticleB> &t){
    //create1000000particles
    auto start=std::chrono::high_resolution_clock::now();
    for (int i=0;i<1000000;i++){
        t[i].x+=t[i].vx;
        t[i].y+=t[i].vy;
        t[i].z+=t[i].vz;
    }
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli>diff=end-start;
    printf(" ParticleB took:%.2fms\n",diff.count());
}
int main(){
    std::vector<ParticleA> a(1000000);
    std::vector<ParticleB> b(1000000);
    for (int i=0;i<1000000;i++){
        a[i].x=0,a[i].y=0,a[i].z=0;
        a[i].vx=1,a[i].vy=1,a[i].vz=1;
        b[i].x=0,b[i].y=0,b[i].z=0;
        b[i].vx=1,b[i].vy=1,b[i].vz=1;
    }
    measure(a);
    measure(b);
    return 0;

}