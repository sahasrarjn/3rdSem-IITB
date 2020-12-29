#include <iostream>
#include <bitset>
using namespace std;

int main(){
    
    std::string s = std::bitset< 8 >( 12345 ).to_string(); // string conversion

    std::cout << std::bitset< 8 >( 54321 ) << ' '; // direct output

    std::bitset< 8 > input;
    std::cin >> input;
    unsigned long ul = input.to_ulong();
    std::cout << ul << std::endl;
}