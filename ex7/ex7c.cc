#include <iostream>
#include <cstring>


using std::cin;
using std::cout;

const int MAX_STRS = 10;
const int MAX_STR_LEN = 100;

void readPasswords(int numberOfPasswords, char inp_passwd[][MAX_STR_LEN]);
void readMandatory(int numberOfMandatory, char mandatory[][MAX_STR_LEN]);
bool hasMandatoryCharacter(const char* password, const char* mandatoryGroup);
void validateAndPrintPasswords(int numberOfPasswords, int numberOfMandatory,
                                char inp_passwd[][MAX_STR_LEN], char mandatory[][MAX_STR_LEN], char out_passwd[][MAX_STR_LEN]);

int main()
{
    int numberOfPasswords, numberOfMandatory;

    char inp_passwd[MAX_STRS][MAX_STR_LEN];
    char mandatory[MAX_STRS][MAX_STR_LEN];
    char out_passwd[MAX_STRS][MAX_STR_LEN];

    cin >> numberOfPasswords;
    cin.ignore();

    readPasswords(numberOfPasswords, inp_passwd);

    cin >> numberOfMandatory;
    cin.ignore();

    readMandatory(numberOfMandatory, mandatory);

    validateAndPrintPasswords(numberOfPasswords, numberOfMandatory, inp_passwd, mandatory, out_passwd);

    return 0;
}

void readPasswords(int numberOfPasswords, char inp_passwd[][MAX_STR_LEN])
{
    for (int i = 0; i < numberOfPasswords; i++)
    {
        cin.getline(inp_passwd[i], MAX_STR_LEN);
    }
}

void readMandatory(int numberOfMandatory, char mandatory[][MAX_STR_LEN])
{
    for (int i = 0; i < numberOfMandatory; i++)
    {
        cin.getline(mandatory[i], MAX_STR_LEN);
    }
}

bool hasMandatoryCharacter(const char* password, const char* mandatoryGroup)
{
    for (int i = 0; password[i] != '\0'; ++i)
    {
        for (int j = 0; mandatoryGroup[j] != '\0'; ++j)
        {
            if (password[i] == mandatoryGroup[j])
            {
                return true;
            }
        }
    }
    return false;
}

void validateAndPrintPasswords(int numberOfPasswords, int numberOfMandatory,
                                char inp_passwd[][MAX_STR_LEN], char mandatory[][MAX_STR_LEN], char out_passwd[][MAX_STR_LEN])
{
    for (int i = 0; i < numberOfPasswords; i++)
    {
        bool isValid = true;

        for (int j = 0; j < numberOfMandatory; j++)
        {
            if (!hasMandatoryCharacter(inp_passwd[i], mandatory[j]))
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            strcpy(out_passwd[i], inp_passwd[i]);
        }
        else
        {
            out_passwd[i][0] = '\0';
        }
    }

    for (int i = 0; i < numberOfPasswords; i++)
    {
        if (out_passwd[i][0] != '\0')
        {
            cout << out_passwd[i] << "\n";
        }
    }
}
