#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main(){
	char CurrentDir[PATH_MAX];
	DIR *dir;
	struct dirent *dstruct;
	if (getcwd(CurrentDir, PATH_MAX) == NULL){
		fputs("Cannot to get name of current directory", stderr);
	}
	else{	
		printf("Current directory is %s\n", CurrentDir);
		if ((dir = opendir (CurrentDir)) == NULL) {
			fputs("Cannot open stream of current catalog\n",stderr);
		}
		else{
			while ((dstruct = readdir(dir)) != NULL){
				printf("%s\n", dstruct -> d_name);
			}
			if (closedir(dir) == -1) {
				fputs("Cannot close stream of current catalog\n",stderr);	
			}
		}
	}
	putc('\n',stdout);
	char RootDir[]="/";
	puts("Root directory:\n");

	if ((dir = opendir (RootDir)) == NULL) {
		fputs("Cannot open stream of current catalog\n",stderr);
	}
	else{
		while ((dstruct = readdir(dir)) != NULL){
			printf("%s\n", dstruct -> d_name);
		}
		if (closedir(dir) == -1) {
			fputs("Cannot close stream of current catalog\n",stderr);
		}
	}
}
