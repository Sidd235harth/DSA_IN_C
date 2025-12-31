/*a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP).
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP
 if PAT exists in STR. Report suitable messages in case PAT does not exist in STR .
 Support the program with functions for each of the above operations. Don't use Built-in functions.*/
#include <stdio.h>

char STR[100], PAT[100], REP[100], ANS[100];
int s, p, r, a, flag = 0;

// Function declarations
void read();
void replace();
void display();

int main()
{
    read();
    replace();
    display();
    return 0;
}

void read()
{
    printf("Enter the MAIN string:\n");
    scanf(" %[^\n]", STR);

    printf("Enter the PATTERN string:\n");
    scanf("%s", PAT);

    printf("Enter the REPLACE string:\n");
    scanf("%s", REP);
}

void replace()
{
    s = p = a = 0;

    while (STR[s] != '\0')
    {
        if (STR[s] == PAT[p])
        {
            s++;
            p++;

            if (PAT[p] == '\0') // full pattern matched
            {
                flag = 1;
                for (r = 0; REP[r] != '\0'; r++, a++)
                    ANS[a] = REP[r];
                p = 0;
            }
        }
        else
        {
            ANS[a] = STR[s];
            s++;
            a++;
            p = 0;
        }
    }
}

void display()
{
    if (flag == 0)
        printf("\nPattern not found!!!\n");
    else
    {
        ANS[a] = '\0';
        printf("\nThe RESULTANT string is:\n%s\n", ANS);
    }
}
