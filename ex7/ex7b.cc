//-------------- include section --------------
#include <iostream>
#include <cctype>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::swap;

const int MAX_SIZE = 1000;

// this function Generation a random n
int generationN();

// this function Generation a random character
char generateRandomChar(int n);

// this function does the encryption for the string 
void encryption(char input[], int length);

// this function does the decryption for the string 
void decryption(char input[], int length);

// using a to string to make an integer to string 
void customToString(int num, char &str);

// using a to string to make a string to integer 
int customStoi(char str);



//-------------- main --------------
int main()
{
    char input[MAX_SIZE];
    int choice;

    cin >> choice;
    cin.ignore();

    cin.getline(input, MAX_SIZE);

    int length = 0;
    while (input[length] != '\0')
    {
        ++length;
    }

    choice == 1 ? encryption(input, length) : decryption(input, length);

    return EXIT_SUCCESS;
}

int generationN()
{
    srand(17);
    return rand() % 3 + 2;
}

char generateRandomChar(int n)
{
    srand(17);
    return 'a' + rand() % n;
}

void customToString(int num, char &str)
{
    if (num == 0)
    {
        str = '0';
    }
    else
    {
        str = '0' + num;  
    }
}

int customStoi(char str)
{
    return str - '0';
}

void encryption(char input[], int length)
{
    int n = generationN();

    char character = generateRandomChar(n);

    int reverseIndex = 0;

    for (int i = 0; i < length; ++i)
    {
        if (islower(input[i]))
        {
            input[i] = (input[i] - 'a' + n) % 26 + 'a';
        }
        else if (isupper(input[i]))
        {
            input[i] = (input[i] - 'A' + n) % 26 + 'A';
        }
    }

    cout << input << "\n";

    for (int i = 0; i < length; i += n)
    {
        int groupLength = (i + n <= length) ? n : length - i;
        for (int j = 0; j < groupLength / 2; ++j)
        {
            swap(input[i + j], input[i + groupLength - 1 - j]);
        }
    }

    cout << input << "\n";

    for (int i = n; i < length; i += n + 1)
    {
        for (int j = length; j > i; --j)
        {
            input[j] = input[j - 1];
        }
        input[i] = character;
        length++; 
    }

    char nChar;
    customToString(n, nChar);

    cout << input << nChar << "\n";
}


void decryption(char input[], int length)
{
    int n;

    char nChar = input[length - 1];

    n = customStoi(nChar);  

    input[length - 1] = '\0'; 

    int newIndex = 0;
    for (int i = 0; i < length - 1; i++) 
    {
        if ((i + 1) % (n + 1) != 0) 
        {
            input[newIndex++] = input[i];
        }
    }
    input[newIndex] = '\0';
    cout << input << "\n";

    for (int i = 0; i < newIndex; i += n)
    {
        int groupLength = (newIndex - i < n) ? newIndex - i : n;
        
        for (int j = 0; j < groupLength / 2; ++j)
        {
            swap(input[i + j], input[i + groupLength - 1 - j]);
        }
    }

    cout << input << "\n";

    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (islower(input[i]))
        {
            input[i] = (input[i] - 'a' - n + 26) % 26 + 'a';
        }
        else if (isupper(input[i]))
        {
            input[i] = (input[i] - 'A' - n + 26) % 26 + 'A';
        }
    }

    cout << input << "\n";
}
