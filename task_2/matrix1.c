/* do not add other includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */
  unsigned int M = 1000;
  unsigned int N = 256*1024; 
  unsigned int i;
	
  /* declare variables; examples, adjust for task */
	double **a;
    double **b;
    double **c;
	double count = 0;
 
  
  /* parameter parsing task 1 */
  for(i=1; i<(unsigned)argc; i++) {
	  if (strcmp(argv[i], "--repetitions") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &M);
		  else
			  usage();
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &N);
		  else
			  usage();
	  } else usage();
  }

    
  /* allocate memory for arrays; examples, adjust for task */
	a = malloc(N * sizeof(double **));
    b = malloc(N * sizeof(double **));
    c = malloc(N * sizeof(double **));
	// Need to allocate space for each element in matrix
	for (i = 0; i < N; i++) {
        a[i] = malloc(N * sizeof(double));
        b[i] = malloc(N * sizeof(double));
        c[i] = malloc(N * sizeof(double));
    }
	 /* initialise arrray elements */
	// initialise to 2s
	for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = 2;
            b[i][j] = 2;
        }
    }
 
	 
  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
	for (int r = 0; r < M; r++) { // Repetitions
		for (int i = 0; i < N; i++) {
			for (int j; j < N; j++) {
				for (int k; k < N; k++) {
					// count = sum of a(i)(k)*b(k)(j)
					count += a[i][k] * b[k][j];
				}
				// tore Count and Reset
				c[i][j] = count;
				count = 0;
			}
		}
	}
	
	
  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("time: %6.2f secs\n",(t2 - t1));

  /* IMPORTANT: also print the result of the code, e.g. the sum, 
   * otherwise compiler might optimise away the code */
  
  /* free memory; examples, adjust for task */
  // Inverse of Allocation
    for (i = 0; i < N; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

  return 0;  
}
