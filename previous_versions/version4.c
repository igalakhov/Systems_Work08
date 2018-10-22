/*
  Basic algorithm with:
    -> no overwriting
    -> no even numbers
    -> binary operations
    -> calloc instead of malloc

    0.1425 seconds!!!
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int sieve(int n){
  /*
    0 -> prime
    1 -> composite
  */

  int upper_bound = (int) n * log(n) + n*log(log(n));

  int num_slots = ((int) (upper_bound + 1)/2) - 1;
  int upper_slot = ((int) (sqrt(upper_bound) + 2)/2) - 1;

  char * sv = calloc((int) upper_bound/2, sizeof(short));

  int i, j;
  for(i = 0; i <= upper_slot; i++){
    if(sv[i])
      continue;
    //printf("\nCHECKING SLOT %d:\n", i);
    for(j = i + 2*i + 3; j < num_slots; j += 2*i + 3){
      sv[j] = 1;
      //printf("J value: %d,", j);
    }
  }

  // int c = 1;
  // for(i = 0; i < num_slots; i++){
  //   if(sv[i])
  //     j = 1;
  //     //printf("%d is composite\n", i*2 + 3);
  //   else{
  //     c++;
  //     //printf("%dth rpime: %d\n", c, i*2 + 3);
  //   }
  // }

  int c = 1;
  for(i = 0; i < num_slots; i++){
    if(!sv[i])
      c += 1;
    if(c == n){
      free(sv);
      return 2*i + 3;
    }
  }

  return -1;
}

int main(){
  int target = 999999;

  printf("\n%dth prime is: %d\n\n", target, sieve(target));
}
