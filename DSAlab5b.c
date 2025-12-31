/*b. Solving Tower of Hanoi problem with n disks*/
#include <stdio.h>

void towers(int n, char source, char temp, char dest)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    towers(n - 1, source, dest, temp);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    towers(n - 1, temp, source, dest);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    towers(n, 'A', 'B', 'C');
    return 0;
}
