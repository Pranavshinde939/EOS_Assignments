#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    int signal_number, process_id;
    printf("Enter signal number: ");
    scanf("%d", &signal_number);
    printf("Enter process ID: ");
    scanf("%d", &process_id);
    int result = kill(process_id, signal_number);
    if(result==0)
	{
        printf("Signal %d sent to process %d.\n", signal_number, process_id);
    }
	else
	{
        perror("Failed to send signal");
		_exit(1);
    }
	return 0;
}
