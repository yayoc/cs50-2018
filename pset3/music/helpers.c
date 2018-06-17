// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>


#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[0] == '1')
    {
        if (fraction[2] == '1')
        {
            return 1;
        }
        else if (fraction[2] == '2')
        {
            return 4;
        }
        else if (fraction[2] == '4')
        {
            return 2;
        }
        else if (fraction[2] == '8')
        {
            return 1;
        }

    }
    else if (fraction[0] == '3' && fraction[2] == '8')
    {
        return 3; 
    }
    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Convert ASCHII to int
    int octave = note[strlen(note) - 1] - 48;

    double freq;
    switch (note[0])
    {
        case 'C':
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D':
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E':
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F':
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G':
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default :
            return 0;
    }
    
    if (octave > 4) 
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2;
        }

    } 
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2;
        }
    }

    if (note[1] == '#')
    {
        freq *= pow(2.0, (1.0 / 12.0));
    } 
    else if (note[1] == 'b')
    {
        freq /= pow(2.0, (1.0 / 12.0));
    }

    int ret = round(freq);
    return ret;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s, "\0", 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}
