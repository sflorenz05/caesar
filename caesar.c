#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
    int k = 0;   //System key
    string pt;   //Plaintext String
    string ct;   //Ciphertext String
    string cmp1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";   //String reference to compare capitols letters
    string cmp2 = "abcdefghijklmnopqrstuvwxyz";   //String reference to compare lowes case letters
    int n = 0;   //number of Alphabetic method
    int j = 0;
    int m = 0;

    if (argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
    }
    else
    {
        k = atoi(argv[1]);
        pt = get_string("plaintext: ");
        ct = pt;
        for (int i = 0; pt[i] != '\0'; i++)
        {
            if (pt [i] >= 65 && pt [i] <= 90)
            {
                for (j = 0; cmp1 [j] != pt [i]; j++) { }
                n = ((j + k) % 26);
                ct [i] = cmp1 [n];
            }

            if (pt [i] >= 97 && pt [i] <= 122)
            {
                for (m = 0; cmp2 [m] != pt [i]; m++) { }
                n = ((m + k) % 26);
                ct [i] = cmp2 [n];
            }
        }
        printf("ciphertext: %s\n", ct);
    }
}