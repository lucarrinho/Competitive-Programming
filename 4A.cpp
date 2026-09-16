#include <iostream>

void solve(int num){
    if (num % 2 == 0 && num > 2) {
        std::cout << "YES" << std::endl;
    } else {
    std::cout << "NO" << std::endl;
    }
}

int main(){
    int num;
    std::cin >> num;
    solve(num);
    return 0; 
}