#include <stdio.h>
#include "header.h"

#define ROWS 250
#define LINE 256
#define WORD 30

int main(int argc, char *argv[])
{
	char buffer[(ROWS * LINE) + WORD + 10] = {0};
	fread(buffer, (ROWS * LINE) + WORD + 10, 1, stdin);
	// printf("Read: %s\n", buffer);
	char word[WORD] = {'\0'};
	int len = getword(buffer);
	int i = 0;
	for (; i < len; i++)
	{
		*(word + i) = *(buffer + i);
	}
	// printf("word: %s\n", word);
	char c = *(buffer + (++i));
	// printf("c: %c\n", c);
	i = i + 5;
	char *text = (buffer+i);


	if (c == 'a') {
		print_lines(word,text);
	} else {
		print_similar_words(word,text);
	}


	return 0;
}