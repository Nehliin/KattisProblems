#include<stdio.h>
#include<iostream>
#include<unordered_map>
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for(; ((c<48 || c>57)); c = getchar_unlocked());
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
}

inline void fastRead_string(char str[15])
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i++;
    }
    str[i] = '\0';
}

int main(){
  int results;
  int maxPairs = 0;
  std::unordered_map<std::string,int> map1;
  std::unordered_map<std::string,int> map2;
  fastRead_int(results);
  for(int i=0;i<results;i++){
      char line[15];
      fastRead_string(line);
      map1[line]++;
  }

  for(int i=0;i<results;i++){
      char line[15];
      fastRead_string(line);
      map2[line]++;
  }
  for( const auto& n : map1 ){
      if(map2.find(n.first) != map2.end()){
        if(n.second <= map2[n.first]){
          maxPairs += n.second;
        }else{
          maxPairs += map2[n.first];
        }
      }
  }
  printf("%d", maxPairs);
  return 0;
}
