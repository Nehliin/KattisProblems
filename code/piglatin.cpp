#include <stdio.h>
#include <stdlib.h>
inline void fastRead_word(char str[30000]){
    register char c = 0;
    register int i = 0;
    register int j = 0;
    char temp[150];
    while (c != '\n'){
        c = getchar_unlocked();
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
            while(c != '\n'){
                if(c == EOF){
                    exit(0);
                }
                if(c == ' '){
                    break;
                }
                str[i] = c;
                c = getchar_unlocked();
                ++i;
            }
            str[i] = 'y';
            str[++i] = 'a';
            str[++i] = 'y';
            if(c == ' '){
                str[++i] = ' ';
            }
            ++i;
        }else{
            temp[0] = c;
            ++j;
            c = getchar_unlocked();
            while(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y' && c != '\n'){
                if(c == EOF){
                    exit(0);
                }
                if(c == ' '){
                    break;
                }
                temp[j] = c;
                c = getchar_unlocked();
                ++j;
            }
            while(c != '\n'){
                if(c == EOF){
                    exit(0);
                }
                if(c == ' '){
                    break;
                }
                str[i] = c;
                c = getchar_unlocked();
                ++i;
            }
            for(int k = i; k < (i+j); ++k){
                str[k] = temp[k-i];
            }
            str[i+j] = 'a';
            str[i+j+1] = 'y';
            if(c == ' '){
                str[i+j+2] = ' ';
                i = i+j+3;
            }else{
                i = i+j+2;
            }
        }
        j=0;
    }
    str[i]= '\0';
}

int main(){
    char answer[30000];
    while(true){
        fastRead_word(answer);
        printf("%s\n", answer);
    }
}
