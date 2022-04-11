#include "stdio.h"
#include <string.h>
#include <stdlib.h> 

int main(int argc, char const *argv[])
{
	if (argc != 3){
		fputs("Incorrect number of parameters. Must be 2 parameters. The first - name of file, the second - number of strings\n", stderr);
	}
	else{
		int N = atoi(argv[2]);
		if (N < 0) {
			fputs("Invalid parameter\nSecond parameter must be above zero\n",stderr);
			return -1;
		}
		else {
			FILE *f;
			if ((f = fopen(argv[1], "r")) == NULL) {
				fputs("Cannot to open file", stderr);
			}
			else {
				int i = 0;
				char symbol;
				while ((symbol = getc(f)) != EOF){
					if (N == 0){
						fputc(symbol, stdout);
					}
					else {
						if (i == N) {
							char key = getc(stdin);
							i = 0;
						}
						fputc(symbol, stdout);
						if (symbol == '\n') {
							i++;
						}
					}
				}
			}
			if (fclose(f)) {
				fputs("Cannot close file\n",stderr);
			}
		}
	}
	return 0;
}
