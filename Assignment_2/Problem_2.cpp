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
    
    
    // Creates random binary strings with a coin flip for each bit
     std::vector<std::bitset<32> > binary_strings;
     std::bitset<32> b;
     for(int i = 0; i < 5; i++)
     {
        for (int j = 0; j < 32; j++)
        {
            b[j] = std::rand() % 2;
        }
        binary_strings.push_back(b);
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
    std::vector<int> b_xor;
    b_xor.reserve(5);
    //Preprocess 1st iteration so that we can do runs and everything in the same loop
    b_xor[0] = binary_strings[0][15] ^ binary_strings[0][28] ^ binary_strings[0][3];
    b_xor[1] = binary_strings[1][30] ^ binary_strings[1][16] ^ binary_strings[1][5];
    b_xor[2] = binary_strings[2][12] ^ binary_strings[2][17] ^ binary_strings[2][2];
    b_xor[3] = binary_strings[3][31] ^ binary_strings[3][23] ^ binary_strings[3][8];
    b_xor[4] = binary_strings[4][7] ^ binary_strings[4][1] ^ binary_strings[4][10];
    
    //Preprocess 1st iteration so that we can do runs and everything in the same loop
    ans[ans.size() - 1] = b_xor[0] ^ b_xor[1] ^ b_xor[2] ^ b_xor[3] ^ b_xor[4];
    
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
    for (int i = 0; i < 5; i++)
    {
        binary_strings[i] <<= 1;
        binary_strings[i][0] = b_xor[i];
    }
    
    for (int i = ans.size() - 2; i >= 0; i--)
    {
        b_xor[0] = binary_strings[0][15] ^ binary_strings[0][28] ^ binary_strings[0][3];
        b_xor[1] = binary_strings[1][30] ^ binary_strings[1][16] ^ binary_strings[1][5];
        b_xor[2] = binary_strings[2][12] ^ binary_strings[2][17] ^ binary_strings[2][2];
        b_xor[3] = binary_strings[3][31] ^ binary_strings[3][23] ^ binary_strings[3][8];
        b_xor[4] = binary_strings[4][7] ^ binary_strings[4][1] ^ binary_strings[4][10];
        
        ans[i] = b_xor[0] ^ b_xor[1] ^ b_xor[2] ^ b_xor[3] ^ b_xor[4];
        
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
        for (int i = 0; i < 5; i++)
        {
            binary_strings[i] <<= 1;
            binary_strings[i][0] = b_xor[i];
        }
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
