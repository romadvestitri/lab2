#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[]){

	if (argc != 2) {
		fputs("incorrect number of parameters!\n Must be one parameter - name of file",stderr);
	}
	else {
		FILE *f;
		if ((f = fopen(argv[1], "w")) == NULL) {
			fputs("Cannot to open/create file", stderr);
		}
		else {
			char symbol = 0;
			while (symbol != 6){
				if ((symbol = getc(stdin)) == EOF) {
					fputs("Cannot to read symbol", stderr);
				}
				else if (symbol != 6){
					fputc(symbol,f);
				}
			}
			if (fclose(f)){
				fputs("Cannot to close file", stderr);
			}
		}
	}

}
