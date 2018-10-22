/*
  Basic algorithm with no improvements

  avg time: around 0.340 seconds
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

  int i, j;

  int up = (int) sqrt(upper_bound);

  for(i = 2; i < up + 1; i++){
    if(sv[i])
      continue;
    sv[i] = 0;

    for(j = 2*i; j < upper_bound; j += i){
      sv[j] = 1;
    }
  }

  int counter = 0;
  for(i = 2; i < upper_bound; i++){
    if (!sv[i])
      counter++;
    if(counter == n)
      return i;
  }

  free(sv);
  return upper_bound;
}

int main(){
  int target = 1000000;

  printf("\n%dth prime is: %d\n\n", target, sieve(target));
}
