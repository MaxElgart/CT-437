#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::bitset<32> b1;
    std::bitset<32> b2;
    std::bitset<32> b3;
    std::bitset<32> b4;
    std::bitset<32> b5;
    int iterations = 0;
    std::cout << "How many iterations? ";
    std::cin >> iterations;
    
    std::vector<int> ans(iterations);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Creates random binary strings with a coin flip for each bit for 5 binary strings
    for (int j = 0; j < 32; j++)
    {
        b1[j] = std::rand() % 2;
    }
    
    for (int j = 0; j < 32; j++)
    {
        b2[j] = std::rand() % 2;
    }
    
    for (int j = 0; j < 32; j++)
    {
        b3[j] = std::rand() % 2;
    }
    
    for (int j = 0; j < 32; j++)
    {
        b4[j] = std::rand() % 2;
    }
    
    for (int j = 0; j < 32; j++)
    {
        b5[j] = std::rand() % 2;
    }
    
    int ones_count = 0;
    int zeros_count = 0;
    int prev = 0;
    int curr_run = 1;
    int biggest_run_1 = 0;
    int biggest_run_0 = 0;
    int run_4 = 0;
    int run_5 = 0;
    int run_6 = 0;
    
    //Preprocess 1st iteration so that we can do runs and everything in the same loop
    int b1_xor = b1[15] ^ b1[28] ^ b1[3];
    int b2_xor = b2[30] ^ b2[16] ^ b2[5];
    int b3_xor = b2[12] ^ b2[17] ^ b2[2];
    int b4_xor = b2[31] ^ b2[23] ^ b2[8];
    int b5_xor = b2[7] ^ b2[1] ^ b2[10];
    
    //Preprocess 1st iteration so that we can do runs and everything in the same loop
    ans[ans.size() - 1] = b1_xor ^ b2_xor ^ b3_xor ^ b4_xor ^ b5_xor;
    
    //Preprocess 1st iteration so that we can do runs and everything in the same loop
    if (ans[ans.size() - 1] == 1)
    {
        ones_count += 1;
    }
    else
    {
        zeros_count += 1;
    }
    
    //Preprocess 1st iteration so that we can do runs and everything in the same loop
    b1 <<= 1;
    b1[0] = b1_xor;
    
    b2 <<= 1;
    b2[0] = b2_xor;
    
    b3 <<= 1;
    b3[0] = b3_xor;
    
    b4 <<= 1;
    b4[0] = b4_xor;
    
    b5 <<= 1;
    b5[0] = b5_xor;
    
    //indexing starts at the back so b1[0] for b1 = 11110 returns 0
    for (int i = ans.size() - 2; i >= 0; i--)
    {
        int b1_xor = b1[15] ^ b1[28] ^ b1[3];
        int b2_xor = b2[30] ^ b2[16] ^ b2[5];
        int b3_xor = b2[12] ^ b2[17] ^ b2[2];
        int b4_xor = b2[31] ^ b2[23] ^ b2[8];
        int b5_xor = b2[7] ^ b2[1] ^ b2[10];
        
        ans[i] = b1_xor ^ b2_xor ^ b3_xor ^ b4_xor ^ b5_xor;
        
        // This counts 1's and 0's for test 1
        if (ans[i] == 1)
        {
            ones_count += 1;
        }
        else
        {
            zeros_count += 1;
        }
        
        //This counts the runs for test 2 and 3
        if (ans[i] == ans[i + 1])
        {
            curr_run += 1;
        }
        else
        {
            //Checks to see if this is the biggest run of 1's or 0's so far
            if (ans[i + 1] == 1 && curr_run > biggest_run_1)
            {
                biggest_run_1 = curr_run;
            }
            else if(ans[i + 1] == 0 && curr_run > biggest_run_0)
            {
                biggest_run_0 = curr_run;
            }
            
            //Checks to see if the run was length 4, 5, 6
            if (curr_run == 4)
            {
                run_4 += 1;
            }
            else if(curr_run == 5)
            {
                run_5 += 1;
            }
            else if(curr_run == 6)
            {
                run_6 += 1;
            }
            
            //resets run
            curr_run = 1;
        }
        
        //Pushes all of the binary strings 1 to the left and sets the last index to the xor statement
        b1 <<= 1;
        b1[0] = b1_xor;
        
        b2 <<= 1;
        b2[0] = b2_xor;
        
        b3 <<= 1;
        b3[0] = b3_xor;
        
        b4 <<= 1;
        b4[0] = b4_xor;
        
        b5 <<= 1;
        b5[0] = b5_xor;
    }
    
    //Checks to see if the run never ended from the last iteration and sees if its the biggest
    if (ans[0] == 1 && curr_run > biggest_run_1)
    {
        biggest_run_1 = curr_run;
    }
    else if(ans[0] == 0 && curr_run > biggest_run_0)
    {
        biggest_run_0 = curr_run;
    }
    
    //Test 1
    std::cout << "Number of 0's: " << zeros_count << std::endl << "Number of 1's: " << ones_count << std::endl;
    
    //Test 2
    std::cout << "Longest run of 0's: " << biggest_run_0 << std::endl << "Longest run of 1's: " << biggest_run_1 << std::endl;
    
    //Test 3
    std::cout << "Number of 4 runs: " << run_4 << std::endl << "Number of 5 runs: " << run_5 << std::endl << "Number of 6 runs: " << run_6 << std::endl;
    
    return 0;
}
