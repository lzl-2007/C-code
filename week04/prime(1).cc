#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int l = 1000;
    bool is_prime;
    int* primes = new int[l];
    int cnt = 0;
    int b = 5;
    primes[cnt++] = 2;
    for (int no = 3; no < l; no += 2) {
        is_prime = true;
        for (int primecount=0; primes[primecount] <= std::sqrt(no); ++primecount) {
            if (no % primes[primecount] == 0) {
                is_prime = false;
                break;
            } else if (primes[primecount] * primes[primecount] > no) {
                std::cout << no << "\n";
                break;
            }
        }
        if (is_prime) {
            if(cnt%b == 0){
                std::cout << '\n';
            }
            std::cout << no << " ";
            primes[cnt++] = no;
        }
    }
    std::cout << "\n";
    delete primes;
}
