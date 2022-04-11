#include "stdio.h"
#include <string.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	if (argc != 3){
		fputs("Incorrect number of parameters. Must be 2 parameters. The first - name of first file, the second - name of second file\n", stderr);
	}
	else{
		FILE *f1, *f2;
		if ( ((f1 = fopen(argv[1], "r")) == NULL) || ((f2 = fopen(argv[2], "w")) == NULL)){
			fputs("Cannot to open file", stderr);
		}
		else {
			char symbol;
			while ( (symbol = getc(f1)) != EOF) {
				fputc(symbol, f2);
			}
			struct stat buf1;
			if (stat(argv[1], &buf1) == -1){
				fputs("Unable to fill stat structure\n",stderr);
			}
			else{
				chmod(argv[2], buf1.st_mode);
			}
		}
		if (fclose(f1) || fclose(f2)) {
					fputs("Cannot close files\n",stderr);
		}

	}
	return 0;
}
