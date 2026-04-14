#include<iostream>

class Tracer{
private:
    int id_;
public:
    Tracer(int id):id_(id){
        
        if (id<0){
            throw std::invalid_argument("必须是正值");
        }
        std::cout<<"构造"<<id_<<std::endl;
    }
    ~Tracer(){
        std::cout<<"析构"<<id_<<std::endl;
    }
};

class Composer{
public:
    Tracer a;
    Tracer b;
    Composer(int x,int y):a(Tracer(x)),b(Tracer(y)){
    };
};
extern Tracer tracer1=Tracer(1);  //创建全局对象
int main(){
    
    Tracer *tracer4=new Tracer(4);//创建堆上对象
    static Tracer tracer2=Tracer(2);   //创建静态局部对象
    Tracer tracer3=Tracer(3);   //创建栈上对象
    delete tracer4;
    /*输出:
    构造1
    构造4
    构造2
    构造3
    析构4
    析构3
    析构2
    析构1         创建顺序与构造的顺序相关，但析构顺序按照堆（记得delete的情况下）-栈-静态和全局顺序进行
    */
    Composer composer1=Composer(5,6);
    /*输出：
    构造5
    构造6       构造顺序与类中排布顺序相同
    析构6
    析构5       析构顺序与构造顺序相反
    */

    try{
        Tracer tracer7=Tracer(-2);   //故意构造错误
    }
    catch(std::invalid_argument e){
        std::cout<<e.what()<<std::endl;//直接被捕获，无法正常创建
    }

    
    try{
        Composer composer2=Composer(8,-8);   //故意构造错误
    }
    catch(std::invalid_argument e){
        std::cout<<e.what()<<std::endl;
    }
    /*输出：
    构造8
    析构8
    必须是正值            composer2的第一个tracer成功创建，第二个抛出异常被捕获，构造失败并栈展开，沿途的第一个Tracer也立即被析构
    */

    return 0;
    
}