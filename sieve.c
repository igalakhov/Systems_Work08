#include "sieve.h"

int sieve(int n){
  unsigned int upper_bound = (int) n * log(n) + n*log(log(n));
  unsigned int num_slots = ((int) (upper_bound + 1)>>1) - 1;
  unsigned int upper_slot = ((int) (sqrt(upper_bound) + 2)>>1) - 1;

  char * sv = calloc((int) upper_bound/2, sizeof(short));
  char * sv_end = sv + num_slots - 1;

  char * i_p = sv - 1;
  char * j_p;
  int i_val = -1;
  while(upper_slot--){
    i_val++;
    i_p++;
    if(*i_p)
      continue;
    j_p = i_p;
    while(j_p < sv_end){
      j_p += 2*i_val + 3;
      if(!*j_p){
        *j_p = 1;
      }
    }
  }
  i_p = sv - 1;
  unsigned int i = -1;
  unsigned int c = 1;
  while(num_slots--){
    i++;
    i_p++;
    if(!*i_p)
      c += 1;
    if(c == n){
      free(sv);
      return 2*i + 3;
    }
  }
  return -1;
}
