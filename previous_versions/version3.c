/*
  Basic algorithm with:
    -> no overwriting
    -> mark all twos in the beginning
    -> pointer iterators instead of integer iterators

  avg time: around 0.4 seconds which means it's somehow slower
  but I think I know how to make this faster :)
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int sieve(int n){
  int upper_bound = (int) n * log(n) + n*log(log(n));
  short * sv;
  sv = malloc(upper_bound * sizeof(short));
  memset(sv, 0, sizeof(short) * upper_bound);

  short * i;
  int j;

  int up = (int) sqrt(upper_bound);

  int counter = 1;
  int real_i = 3;
  for(i = sv + 3; i < sv + upper_bound; i += 2){
    real_i += 2;
    if(*i)
      continue;
    *i = 0;
    counter++;
    if(!(counter ^ n))
      return (i - sv);

    if(*i < up + 1){
      for(j = 2*(*i); j < upper_bound; j += (i - sv)){
        if(!sv[j]){
          sv[j] = 1;
        }
      }
    }
  }

  free(sv);
  return 123;
}

int main(){
  int target = 1000000;

  printf("\n%dth prime is: %d\n\n", target, sieve(target));
}
