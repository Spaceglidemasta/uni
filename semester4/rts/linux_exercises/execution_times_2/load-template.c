#include<stdio.h> 			// printf
#include<time.h> 			// timespec, clock_gettime, CLOCK_PROCESS_CPUTIME_ID ...
#include<stdlib.h> 			// atoi, atol
#include<unistd.h> 			// getpid
#include<sys/resource.h> 	// setPriority, PRIO_PROCESS
}

/*
 This program generates a specified amount of load on the CPU depending on the arguments it was given.
 arguments:
	$label = a label for this process. Used to differenciate between different processes' outputs.
	$num_slices = the number of slices before the process ends
	$prio = the Unix-priority for the Job 0..19
	$load = (optional) the size of a single slice. Replaces hardcoded value.
*/
int main(int argc, char *args[]){
	// first let's make sure, the number of arguments is acceptable.
	// your program should be called with four arguments.
	// Let's check the number of arguments. 
	if ( _ ){
       	printf("usage: %s $LABEL, $NUM_SLICES, $PRIO, $LOAD", argv[0])
		return -1 ;
	}
	
	// use variables to store the arguments and make the code readable. 
	// Hint: int atoi(char *) https://linux.die.net/man/3/atoi
	// Hint: int atol(char *) https://linux.die.net/man/3/atol
	char *programName 	= _ ;
	char *label 		= _ ;
	int  num_slices 	= _ ;
	int  prio 			= _ ;
	long load 			= _ ; // for large numbers long must be used instead of int
	
	
	// Set the priority of this process to what was given as argument. 
	if (setpriority (PRIO_PROCESS, getpid(), prio ) == -1) {
        perror ("Error when using setpriority()");
    }
	
	
	/*
	Loop example: num_slices = 2, load = 3
	
	>-time-->
	
	|<--iter-->|<--iter-->|<--iter-->|<--iter-->|<--iter-->|<--iter-->|
	|<------------slice------------->|<------------slice------------->|
	|<----------------------------program---------------------------->|
	*/
	
	// get the zero time point
	struct timespec tP0;
	clock_gettime(CLOCK_REALTIME, &tP0);
	// Now print the output as requested in the exercise.
	printf("%s %s %3d %10ld 9ld\n", 
		_ , 
		_ ,
		0,
		tP0.tv_sec,
		tP0.tv_nsec,
		);

	// create variable for the Completion Time
		_ _ tPC;	

	// (outer)loop for slices
	for (int slice = 1; slice <= _ ; slice++){
		// (inner)loop for iterations of single slice. This (inner)loop will take one second each time to process.
		long dummy
		for (int iteration = 0; iteration < _ ; iteration++){
			dummy = dummy + 1;  // just to calculate someting and generate load
		}
		// get the Completion Time
		clock_gettime(CLOCK_REALTIME, &tPC);
		// Now print the output as requested in the exercise.
		printf("%s %s %4d %10ld 9ld\n", 
			_ , 
			_ ,
			_ ,
			tPC.tv_sec,
			tPC.tv_nsec
			);
	}
	
	return 0;
}