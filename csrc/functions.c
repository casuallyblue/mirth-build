#include<unistd.h>
#include<dirent.h>
#include<sys/wait.h>

int path_exists(char* path) {
	DIR* dir = opendir(path);
	if(dir) {
		closedir(dir);
		return 1;
	}

	return 0;
}

