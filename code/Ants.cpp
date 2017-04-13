#include<stdio.h>
#include<vector>
#include<cstdio>

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for(; ((c<48 || c>57)); c = getchar_unlocked());
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
}

int main(){

  int cases;
  int lenght;
  int numberOfants;
  fastRead_int(cases);

  for(int i=0;i<cases;i++){
      fastRead_int(lenght);
      fastRead_int(numberOfants);
      int earliest = 0;
      std::vector<int> ant(2); // 0 min 1 max
      int last = 0;
      for(int i=0;i<numberOfants;i++){
        fastRead_int(ant[0]);
        ant[1] = lenght-ant[0];
        if(ant[0]>ant[1]){
            int temp = ant[0];
            ant[0] = ant[1];
            ant[1] = temp;
        }
        if(ant[1] > last){
            last = ant[1];
        }
        if(ant[0] > earliest){
           earliest = ant[0];
        }
      }
      printf("%d ", earliest);
      printf("%d\n", last);
    }
  return 0;
}
