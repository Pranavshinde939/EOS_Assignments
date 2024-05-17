#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	int ret, err, s, fd;
	char buf[16];
	printf("parent started!\n");

	ret = fork();
	if(ret == 0){
		// input redirection
		fd = open("in.txt", O_RDONLY);
		if(fd<0){
			perror("open() failed");
			_exit(1);
		}

		// read data from file
		printf("contents: \n");
		while((read(fd, buf, sizeof(buf)))!=0){
			printf("%s", buf);
		}
		close(fd);

		err = execlp("wc", "wc", "/home/pranav/Desktop/sunbeam/Embedded_OS/Day11_Lab", "in.txt", NULL);
		//printf("cmd> %s		length: %d\n", buf, strlen(buf));

		//printf("cmd> %s		length: %ld\n", buf, strlen(buf));
		//char *args[] = {"wc", NULL};
		//err = execlp("wc", "wc", NULL);
		//err = execv("/home/pranav/Desktop/sunbeam/Embedded_OS/Day11_Lab", args);
		if(err<0){
			perror("exec() failed");
			_exit(1);
		}
	}
	else{
		waitpid(-1, &s, 0);
	}
	printf("parent completed!\n");
	return 0;
}
