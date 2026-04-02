#include<iostream>
int main(){
	char a;
	std::cout<<"key in:";
	std::cin>>a;
	int b=static_cast<int>(a);
	std::cout<<b;
	return 0;
}
