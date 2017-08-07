#include <stdio.h>
#include<unordered_map>


inline void fastRead_int(int &x) {
    register int c = getchar();
    x = 0;
    for(; ((c<48 || c>57)); c = getchar());
    for(; c>47 && c<58 ; c = getchar()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
}

inline void fastRead_word(char str[200]){
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar();

    while (c != '\n') {
        if(c == ' '){
            break;
        }
        str[i] = c;
        c = getchar();
        i++;
    }
    str[i] = '\0';
}


int main(){
    int m;
    int n;
    int *results;
    std::unordered_map<std::string, int> dictionary;
    fastRead_int(m);
    fastRead_int(n);
    results = new int[n+1];
    char wordTemp[200];
    int valueTemp;
    for(int i = 0; i < m; ++i){
        fastRead_word(wordTemp);
        fastRead_int(valueTemp);
        dictionary.insert({wordTemp, valueTemp});
    }
    int descriptions = 0;
    results[descriptions] = 0;
    while(descriptions < n){
        fastRead_word(wordTemp);
        auto search = dictionary.find(wordTemp);
        if(search != dictionary.end()){
            results[descriptions] += search->second;
        }else{
            if(wordTemp[0] == '.'){
                printf("%d\n",results[descriptions]);
                ++descriptions;
                results[descriptions] = 0;
            }
        }
    }
}
