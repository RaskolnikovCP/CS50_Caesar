#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

string cypher(string s, int k);

int main(int argc, string argv[])
{

    //printf("%s\n%s\n", argv[0], argv[1]);

    bool isNumber;

    string s1;

    int key;

    //printf("%i\n", argc);

    if (argc != 2)
    {

        printf("Usage: ./caesar key\n");

        return 1;
    }

    else
    {

        if (strncmp(argv[0], "./caesar", strlen(argv[0])) == 0)
        {

            //printf("%c\n%i\n", argv[0][3], argv[0][3]);

            for (int i = 0; i < strlen(argv[1]); i++)
            {

                if (isspace(argv[1][i]) || isalpha(argv[1][i]))
                {

                    isNumber = false;

                    printf("Usage: ./caesar key\n");

                    return 1;

                }
                else
                {

                    isNumber = true;

                }

                //printf ("Given input is a number\n");

            }

            if (isNumber)
            {

                s1 = get_string("plaintext: ");

                key = atoi(argv[1]);

                printf("ciphertext: %s\n", cypher(s1, key));

            }

        }

    }

}

string cypher(string s, int k)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                s[i] = ((((s[i] - 65) + k) % 26) + 65);
            }
            else if (islower(s[i]))
            {
                s[i] = ((((s[i] - 97) + k) % 26) + 97);
            }
        }
    }

    return s;
}
