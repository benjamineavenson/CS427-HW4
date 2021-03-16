#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define false 0;
#define true 1;
#define prime 1;
#define composite 0;

long long int modExp(long long int, long long int, long long int);
int millerRabinCheck(long long int, long long int, long long int, long long int);

int main(int argc, char** argv){
  long long int n;
  long long int a;
  long long int s;
  _Bool setN;
  _Bool setA;
  _Bool setS;

  for(int i = 1; i < argc; i++) {
    if(strcmp(argv[i], "-n") == 0) {
      if(i + 1 >= argc || argv[i + 1][0] == '-') {
        printf("Flag -n is missing an argument. Terminating...\n");
        exit(-1);
      }   
      n = atoi(argv[++i]);
      setN = true;
      if(n == 0){
        printf("-n cannot be 0. Terminating...\n");
        exit(-1);
      }
    } else if(strcmp(argv[i], "-a") == 0) {
      if(i + 1 >= argc || argv[i + 1][0] == '-') {
        printf("Flag -a is missing an argument. Terminating...\n");
        exit(-1);
      }   
      a = atoi(argv[++i]);
      setA = true;
      if(a == 0){
        printf("-a cannot be 0. Terminating...\n");
        exit(-1);
      }
    } else if(strcmp (argv[i], "-s") == 0) {
      if(i + 1 >= argc || argv[i + 1][0] == '-') {
        printf("Flag -s is missing an argument. Terminating...\n");
        exit(-1);
      }   
      s = atoi(argv[++i]);
      setS = true;
    } else {
      printf("Unrecognized argument: %s. Terminating...\n", argv[i]);
      exit(-1);
    }  
  }

  if(!setN){
    printf("Program was not supplied a value for -n. Terminating...\n");
    exit(-1);
  }
  if(setA && setS){
    printf("Program was supplied values for both -a and -s. Terminating...\n");
    exit(-1);
  }
  if(!setA && !setS){
    printf("Program was neither supplied a value for -a or -s. Terminating...\n");
    exit(-1);
  }

  int k = 0;
  int q = n-1;

  while(q%2 == 0){
    k++;
    q = q/2;
  }

  if(setA){
    if(a <= 1 || a >= (n-1)){
      printf("a must be greater than 1 and less than n-1. Terminating...\n");
      exit(-1);
    }
    millerRabinCheck(n, k, q, a);
    exit(0);
  }

  if(setS){
    time_t t;
    srand((unsigned int)time(&t));
    for(int i = 0; i != s; i++){
      a = (rand()%(n-2)) + 1;
      millerRabinCheck(n, k, q, a);
    }
    exit(0);
  }
    
} 


int millerRabinCheck(long long int n, long long int k, long long int q, long long int a){
  printf("Checking %lli against %lli...\n", n, a);
  if(modExp(a, q, n) == 1){
    printf("%lli may be prime.\n", n);
    return prime;
  }
  for(int i = 0; i < k; i++){
    if(modExp(a, pow(2, i)*q, n) == (n-1)){
      printf("%lli may be prime.\n", n);
      return prime;
    }
  }
  printf("%lli is composite.\n", n);
  return composite;
}
  
