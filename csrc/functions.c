#include<unistd.h>
#include<dirent.h>
#include<sys/wait.h>

void run_git(char* url, char* path) {
	DIR* dir = opendir(path);
	if(dir) {
		closedir(dir);
		return;
	}

	if(fork() == 0) {
	    char* args[] = { "git", "clone", url, path, 0 };
	    execvp("git", args);
	} else {
	    int pid;
	    wait(&pid);
	}
}
