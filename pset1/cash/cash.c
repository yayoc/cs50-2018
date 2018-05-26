// Calculate the minimum number of coins required to given a user change.
#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    // asks the user how much change is owed
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    int cent = roundf(n * 100);
    int count = 0;

    // split with quarter
    int quarter = 25;
    if (cent % quarter >= 0) 
    {
        count += cent / quarter;
        cent = cent % quarter;
        printf("cent is %i\n", cent);
    }

    // split with dime
    int dime = 10;
    if (cent % dime >= 0) 
    {
        count += cent / dime;
        cent = cent % dime;
    }

    // split with nickel
    int nickel = 5;
    if (cent % nickel >= 0) 
    {
        count += cent / nickel;
        cent = cent % nickel;
    }

    // split with penny
    int penny = 1;
    count += cent / penny;
    printf("%i\n", count);
}


