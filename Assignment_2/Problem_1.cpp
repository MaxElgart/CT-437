#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::bitset<32> b1;
    std::bitset<32> b2;
    int iterations = 0;
    std::cout << "Enter a 32-bit Binary Number: ";
    std::cin >> b1;
    std::cout << "Enter another 32-bit Binary Number: ";
    std::cin >> b2;
    std::cout << "How many iterations? ";
    std::cin >> iterations;
    
    std::vector<int> ans(iterations);
    
    int clocking_1 = 0;
    int clocking_2 = 0;
    int b1_xor = 0;
    int b2_xor = 0;
    
    //indexing starts at the back so b1[0] for b1 = 11110 returns 0
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        //We will have xor operand for b1 be b1[15] xor b1[28] xor b1[3]
        b1_xor = b1[15] ^ b1[28] ^ b1[3];
        //We will have xor operand for b2 be b2[30] xor b2[16] xor b2[5]
        b2_xor = b2[30] ^ b2[16] ^ b2[5];
        
        ans[i] = b1_xor ^ b2_xor;
        
        b1 <<= 1;
        b1[0] = b1_xor;
        
        b2 <<= 1;
        b2[0] = b2_xor;
    }
    
    
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i];
    }
    
    std::cout << std::endl;
    
    return 0;
}
