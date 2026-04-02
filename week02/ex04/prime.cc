#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int length = 1000;
    bool is_prime;
    std::vector<int> arr={2};
    std::cout<<arr[0];
    int cnt = 0;
    for (int num = 3; num < length; num += 2) {
        is_prime = true;
        for (int primecount=0; arr[primecount] <= std::sqrt(num); ++primecount) {
            if (num % arr[primecount] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            if(cnt%5 == 0){
                std::cout << '\n';
            }
            cnt++;
            std::cout << num << " ";
            arr.push_back(num);
            
        }
    }
    std::cout << "\n";
}
