#include <stdio.h>

#define ROWS 250
#define LINE 256
#define WORD 30

// isort part

int shift_element(int *arr, int i)
{
    for (; i > 0; i--)
    {
        *(arr + i + 1) = *(arr + i);
    }
    return 0;
}

int insertion_sort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && *(arr + j) > key)
        {
            // *(arr + j + 1) = *(arr + j);
            j--;
        }
        shift_element(arr + j, (i - j - 1));
        *(arr + j + 1) = key;
    }
    return 0;
}

int print_array(int *arr, int len)
{
    printf("%d", *(arr));

    for (int i = 1; i < len; i++)
    {
        printf(",%d", *(arr + i));
    }
    printf("\n");

    return 0;
}

// txtfind part

int get_line(char s[])
{
    int i = 0;
    while (*(s + i) != '\n' && *(s + i) != '\0' && *(s + i) != '\r')
    {
        i++;
    }
    return i;
}

int getword(char w[])
{
    int i = 1;
    while (*(w + i) != '\n' && *(w + i) != '\t' && *(w + i) != ' ' && *(w + i) != '\r' && *(w + i) != '\0')
    {
        i++;
    }
    return i;
}

int substring(char *str1, char *str2)
{
    for (int i = 0; *(str1 + i) != '\0'; i++)
    {
        int j = i;
        while (*(str1 + j) == *(str2 + j - i))
        {
            // printf("c1 : %c\n", *(str1 + j));
            // printf("c2 : %c\n", *(str2 + j - i));
            if (*(str2 + j - i + 1) == '\0')
                return 1;
            j++;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n)
{
    for (int i = 0; *(s + i) != '\0'; i++)
    {
        int k = n, indexS = i, indexT = 0;
        while (k >= 0)
        {
            while (*(s + indexS) == *(t + indexT))
            {
                if (k == 0 && *(s + indexS) == '\0')
                    return 1;
                if (*(s + indexS) == '\0')
                    break;
                indexS++;
                indexT++;
            }
            if (*(s + indexS) == '\0')
                break;
            indexS++;
            k--;
        }
    }
    return 0;
}

void print_lines(char *str, char *text)
{
    int i = 0;
    int len = get_line((text + i));
    while ((len < LINE) && (text[i] != '\0'))
    {
        char line[LINE] = {'\0'};
        for (int j = 0; j < len && j < LINE; j++)
        {
            *(line + j) = *(text + i);
            i++;
        }
        i++;
        if (substring(line, str))
        {
            printf("%s\n", line);
        }

        len = get_line(text + i);
    }
}

void print_similar_words(char *str, char *text)
{
    int i = 0;
    int len = getword((text + i));
    while ((len < LINE) && (text[i] != '\0'))
    {
        while (text[i] == ' ' || text[i] == '\n')
            i++;
        char word[WORD] = {0};
        len = getword(text + i);
        for (int j = 0; j < len && j < WORD; i++)
        {
            word[j] = text[i];
            j++;
        }
        if (similar(word, str, 1) || similar(word, str, 0))
        {
            printf("%s\n", word);
        }
    }
}