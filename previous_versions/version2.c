/*
  Basic algorithm with:
    -> no overwriting
    -> mark all twos in the beginning

  avg time: around 0.265 seconds
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int sieve(int n){
  int upper_bound = (int) n * log(n) + n*log(log(n));
  printf("DEAD %d\n", upper_bound);
  short * sv;
  sv = malloc(upper_bound * sizeof(short));
  memset(sv, 0, sizeof(short) * upper_bound);

  int i, j;

  int up = (int) sqrt(upper_bound);

  int counter = 1;
  for(i = 3; i < upper_bound; i += 2){
    if(sv[i])
      continue;
    sv[i] = 0;
    counter++;
    if(!(counter ^ n))
      return i;

    if(i < up + 1){
      for(j = 2*i; j < upper_bound; j += i){
        if(!sv[j]){
          sv[j] = 1;
        }
      }
    }
  }

  free(sv);
  return upper_bound;
}

int main(){
  int target = 1000000;

  printf("\n%dth prime is: %d\n\n", target, sieve(target));
}
