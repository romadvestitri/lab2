#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

char *file;
int NumDir = 0, NumFiles = 0;
char* concat(char *s1, char *s2) {

        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);                      

        char *result = malloc(len1 + len2 + 1);

        if (!result) {
            return NULL;
        }

        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 + 1);    

        return result;
}

int FindFile(char *directory){
	
	
	if (directory[strlen(directory)-1] != '/') {
			directory = concat(directory, "/");
	}

	DIR *dir;
	dir = opendir(directory);
	if (dir == NULL) {
		printf("cannot to open %s\n", directory);
	}
	else{
		for (struct dirent *dir_info = readdir(dir); dir_info != NULL; dir_info = readdir(dir)){
			if ((dir_info -> d_type == DT_DIR) && (strcmp(dir_info->d_name, ".") != 0 && strcmp(dir_info->d_name, "..") != 0)){
				char *dirpath = concat(directory, dir_info->d_name);
				FindFile(dirpath);
				NumDir += 1;
			}
			else if (dir_info -> d_type == DT_REG) {
				NumFiles += 1;
				if (strcmp(dir_info -> d_name, file) == 0) {
					char *path = concat(directory, dir_info -> d_name);
					printf("%s\n", path);
					struct stat fileInfo;
					stat(path, &fileInfo);
					printf("Size:  %ld bytes\n", fileInfo.st_size);
					struct tm *timeInfo;
					timeInfo = localtime(&fileInfo.st_mtime);
					printf("Last time of modification: %s", asctime(timeInfo));

					printf("Acess rights: %o\n", fileInfo.st_mode);

					printf("Inode number: %lu\n\n", fileInfo.st_ino);
				}
			}
		}
		closedir(dir);
	}
	
	
	return 0;
}

int main(int argc, char**argv)
{	
	file = argv[2];
	FindFile(argv[1]);

	return 0;
}
