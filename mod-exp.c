#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define false 0;
#define true 1;

long long int modExp(long long int, long long int, long long int);

int main(int argc, char** argv){
  long long int a;
  long long int b;
  long long int n;
  _Bool setA = false;
  _Bool setB = false;
  _Bool setN = false;  


  for(int i = 1; i < argc; i++) {
    if(strcmp(argv[i], "-a") == 0) {
      if(i + 1 >= argc || argv[i + 1][0] == '-') {
        printf("Flag -a is missing an argument. Terminating...\n");
        exit(-1);
      }
      a = atoi(argv[++i]);
      setA = true;
    } else if(strcmp(argv[i], "-b") == 0) {
      if(i + 1 >= argc || argv[i + 1][0] == '-') {
        printf("Flag -b is missing an argument. Terminating...\n");
        exit(-1);
      }
      b = atoi(argv[++i]);
      setB = true;
    } else if(strcmp (argv[i], "-n") == 0) {
      if(i + 1 >= argc || argv[i + 1][0] == '-') {
        printf("Flag -n is missing an argument. Terminating...\n");
        exit(-1);
      }
      n = atoi(argv[++i]);
      setN = true;
      if(n == 0) {
        printf("n cannot be 0. Terminating...\n");
        exit(-1);
      }
    } else {
      printf("Unrecognized argument: %s. Terminating...\n", argv[i]);
      exit(-1);
    }
  }

  if(!(setA && setB && setN)){
    printf("Not all arguments were supplied. Terminating...\n");
    exit(-1);
  }

  printf("%lli\n", modExp(a, b, n));
}
