// Mario more

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
        int spaces = 0;
        int hashes = 0;
        while (spaces < (height - i - 1)) 
        {
            printf(" ");
            spaces += 1;
        }
        // Print Hashes
        while (hashes < (i + 1)) 
        {
            printf("#");
            hashes += 1;
        }
        // Print Gap
        printf("  ");
        // Print Hashes
        while (0 < hashes)
        {
            printf("#");
            hashes -= 1;
        }
        // Print New Line
        printf("\n");
    }
}


