/*
  AlgorithM:
    -> no overwriting
    -> no even numbers
    -> binary operations
    -> calloc instead of malloc
    -> bit arrays
    less than 0.125 seconds!!!
*/

// size of an individual element in an array (for easy changing)
#define ARR_UNIT_SIZE 64

// thanks stackoverflow
#define SetBit(A,k)     ( A[(k/ARR_UNIT_SIZE)] |= (1 << (k%ARR_UNIT_SIZE)) )
#define ClearBit(A,k)   ( A[(k/ARR_UNIT_SIZE)] &= ~(1 << (k%ARR_UNIT_SIZE)) )
#define TestBit(A,k)    ( A[(k/ARR_UNIT_SIZE)] & (1 << (k%ARR_UNIT_SIZE)) )

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void print_bits(unsigned int x)
{
    int i;
    for(i=8*sizeof(x)-1; i>=0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

int sieve(int n){
  unsigned int upper_bound = (int) n * log(n) + n*log(log(n));

  unsigned int num_slots = ((int) (upper_bound + 1)/2) - 1;
  unsigned int upper_slot = ((int) (sqrt(upper_bound) + 2)/2) - 1;

  unsigned int  arr_size = ((int) num_slots/ARR_UNIT_SIZE) + 1;

  unsigned long * sv = calloc(arr_size, ARR_UNIT_SIZE/8);

  int i, j;
  for(i = 0; i <= upper_slot; i++){
    if(TestBit(sv, i))
      continue;
    //printf("\nCHECKING SLOT %d:\n", i);
    for(j = i + 2*i + 3; j < num_slots; j += 2*i + 3){
      //printf("J value: %d,", j);
      SetBit(sv, j);
    }
  }

  int c = 1;
  i = 0;
  while(num_slots--){
    printf("%d ", c);
    if(!TestBit(sv, i))
      c++;
    if(c == n){
      free(sv);
      return 2*i + 3;
    }
    i++;
  }

  return sizeof(long);
}

int main(){
  int target = 1000000;

  printf("\n%dth prime is: %d\n\n", target, sieve(target));
}
