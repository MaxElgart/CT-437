#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::string key;
    std::string plain;
    
    std::cout << "Please input your key: ";
    std::cin >> key;
    
    std::cout << "Please input string to be encoded: ";
    std::cin >> plain;
    
    std::map<char, int>valid_characters;
    
    for (int i = 32; i <= 90; i++)
    {
        if ((i > 32 && i <= 48) || (i > 57 && i <= 64))
        {
            continue;
        }
        valid_characters.insert(std::pair<char,int>(char(i), 0));
    }
    
    std::vector<std::vector<char> > cipher_table(5, std::vector<char>(5, '#'));
    
    int k = 0;
    //Sets up the cipher table with the key
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            while(valid_characters[key[k]] == 1 && k < key.size())
            {
                k++;
            }
            if (k < key.size())
            {
                cipher_table[i][j] = key[k];
                valid_characters[key[k]] = 1;
            }
            else
            {
                break;
            }
        }
        if(k >= key.size())
        {
            break;
        }
    }
    

    
    // Check cipher table to see if it is right, comment out
    for(int i = 0; i <= 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << cipher_table[i][j] << std::endl;
        }
    }
    
    for (auto it : valid_characters)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
    
    return 0;
}
