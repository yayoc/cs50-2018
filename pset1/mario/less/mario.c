// Mario less

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int max_height = 23;
    int height = get_int("Height: ");
    if (height < 0 || max_height < height)
    {
        do
        {
            height = get_int("Retry: ");
        } 
        while (height < 0 || max_height < height);
    }

    for (int i = 0; i < height; i++) 
    {
        // Print Spaces
        for (int s = 0; s < (height - i - 1); s++) 
        {
            printf(" ");
        }
        // Print Hashes
        for (int b = 0; b < (i + 2); b++) 
        {
            printf("#");
        }
        // Print New Line
        printf("\n");
    }
}

