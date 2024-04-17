#include<unistd.h>
#include<dirent.h>
#include<sys/wait.h>

int dir_exists(char* path) {
	DIR* dir = opendir(path);
	if(dir) {
		closedir(dir);
		return 1;
	}

	return 0;
}

int file_exists(char* path) {
	if(access(path, F_OK) == 0) {
		return 1;
	} else {
		return 0;
	}
}

