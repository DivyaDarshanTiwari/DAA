#include <stdio.h>
#include <string.h>

int main()
{
    char t[100];  // Text
    char p[100];  // Pattern

    printf("Enter the text: ");
    scanf("%s", t);

    printf("Enter the pattern: ");
    scanf("%s", p);

    int n = strlen(t);
    int m = strlen(p);
    int max = n - m + 1;

    int f = 0;  // Variable to track if a match is f

    for (int i = 1; i <= max && !f; i++)
    {
        int c = 0;
        for (int j = 0; j < m && c == 0; j++)
        {
            if (p[j] != t[j + i - 1])
            {
                c = 1;
            }
        }
        if (c == 0)
        {
            printf("The first occurrence is at %d", i);
            f = 1;  // Set the f flag to exit the loop
        }
    }

    if (!f)
    {
        printf("Pattern not found.\n");
    }

    return 0;
}
