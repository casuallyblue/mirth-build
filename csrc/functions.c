#include<unistd.h>
#include<dirent.h>
#include<sys/wait.h>

int dir_exists(char* path) {
	DIR* dir = opendir(path);
	return dir ? (closedir(dir), 1) : 0;
}

int file_exists(char* path) {
	return access(path, F_OK) == 0 ? 1 : 0;
}

