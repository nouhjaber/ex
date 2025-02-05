#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

long long maxNum = 0;  
bool used[10] = { false }; 
int num[9];

bool divisibleBy11();
void findLargestNumber(int index);


int main()
{
    findLargestNumber(0);
    cout << "SUCCESS: " << maxNum << endl;
    return EXIT_SUCCESS;
}

bool divisibleBy11()
{
    int oddSum = 0,
        evenSum = 0;

    for (int i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            oddSum = oddSum + num[i];
        }
        else
        {
            evenSum = evenSum + num[i];
        }

    }
    if ((oddSum - evenSum) % 11 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void findLargestNumber(int index)
{
    if (index == 9)
    {
        if (divisibleBy11())
        {
            long long number = 0;
            for (int i = 0; i < 9; i++) number = number * 10 + num[i];
            if (number > maxNum) maxNum = number;
        }
        return;
    }

    for (int digit = 9; digit > 0; digit--)
    {
        if (!used[digit])
        {
            used[digit] = true;
            num[index] = digit;
            findLargestNumber(index + 1);
            used[digit] = false;
        }
    }
}
