#include <iostream>

int main(void)
{
    int * a = new int[8];
    for (int i = 0; i < 8; i++)
    {
        std::cout << (a + i) << "  -  " <<*(a + i) << std::endl;
    }
}