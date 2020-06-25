#include <stdio.h>
#include <signal.h>
#include <windows.h>

void sigHand(int sigVal);

int main(void) {
	signal(SIGINT, sigHand);

	while (1) {
		printf("I N F I N I T Y !\n");
		Sleep(1);
	}
}

void sigHand(int sigVal) {

	printf("Caught signal %d\n", sigVal);

	exit(sigVal);
}