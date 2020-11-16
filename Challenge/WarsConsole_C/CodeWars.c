#include "CodeWars.h"

char* CodeWars_ReverseWords(const char* text)
{
    // <---- hajime!
    int sIndex = 0;
    int revIndex = 0;
    int length = strlen(text);
    char* reversed = malloc(sizeof(char) * length + 1);

    if (reversed)
    {
        for (int i = 0; i < length; i++)
        {
            if (((*(text + i)) == ' ') || i == length -1)
            {
                int eIndex = ((i == length -1) && ((*(text + i)) != ' ')) ? i : i - 1;

                while (eIndex >= sIndex)
                    reversed[revIndex++] = *(text + eIndex--);

                *(reversed + revIndex++) = ' ';
                sIndex = i + 1;
            }
        }

        *(reversed + length) = '\0';
        printf("Length of reversed: %d\n", strlen(reversed));
    }

    return reversed;
}

unsigned CodeWars_CountBits(unsigned value)
{
    int bits = 0;
    while (value > 0)
    {
        if (value & 1)
            bits++;
        value >>= 1;
    }

    return bits;
}

static void CodeWars_RomanNumerals_AddRomanCharacter(char* roman, int digit, int power)
{
	switch (power)
	{
		case 0:
			if (digit == 1)
				strncat(roman, "I", 1);
			else
				strncat(roman, "V", 1);
			break;
		case 1:
			if (digit == 1)
				strncat(roman, "X", 1);
			else
				strncat(roman, "L", 1);
			break;
		case 2:
			if (digit == 1)
				strncat(roman, "C", 1);
			else
				strncat(roman, "D", 1);
			break;
		case 3:
			if (digit == 1)
				strncat(roman, "M", 1);
			break;
	}
}

static void CodeWars_RomanNumerals_ConvertToRoman(char* roman, int power, int * number, int comparer, int margin, int a, int b)
{
    int comp = (int)(comparer * pow(10, power));
	margin *= (int)pow(10, power);
	while (*number >= comp)
	{
		if (*number >= (comp + margin))
		{
			CodeWars_RomanNumerals_AddRomanCharacter(roman, 1, power);
			CodeWars_RomanNumerals_AddRomanCharacter(roman, a, power+b);
			*number -= (comp + margin);
		}
		else
		{
			CodeWars_RomanNumerals_AddRomanCharacter(roman, comparer, power);
			*number -= comp;
		}
	}
}

char* CodeWars_RomanNumerals(int number)
{
    char* roman = calloc(100, sizeof(roman));
    int power = 3;

    while (number > 0)
    {
        CodeWars_RomanNumerals_ConvertToRoman(roman, power, &number, 5, 4, 1, 1);
        CodeWars_RomanNumerals_ConvertToRoman(roman, power, &number, 1, 3, 5, 0);
        power--;
    }

    return roman;
}

int CodeWars_DigitalRoot(int n)
{
    int sum = n;
    while (sum >= 10)
    {
        n = sum;
        sum = 0;
        while (n > 0)
        {
            int rest = n % 10;
            sum += rest;
            n /= 10;
        }
    }
    return sum;
}