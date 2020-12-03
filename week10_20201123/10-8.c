#include "./ch10.h"

int main() {
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("fork failed\n");
		exit(-1);
	}
	else if (pid == 0) {
		exit(0);
	}
	else {
		sleep(200);
		wait(NULL);
	}

	return 0;
}
