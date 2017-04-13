#include <stdio.h>
#include <vector>
#include <algorithm>
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for(; ((c<48 || c>57)); c = getchar_unlocked());
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
}

int main(){
    int m1,m2,k,n = -1;
    std::vector<double> wins;
    std::vector<double> losses;
    char c;
    int games;
    while(true){
        fastRead_int(n);
        if(n == 0){
            break;
        }
        fastRead_int(k);
        wins.resize(n+1);
        std::fill (wins.begin(),wins.end(),0);
        losses.resize(n+1);
        std::fill (losses.begin(),losses.end(),0);
        games = (k*n*(n-1)/2);
        for(int i=0;i<games;++i){
            fastRead_int(m1);
            c = getchar_unlocked();
            if(c == 114){//r
                fastRead_int(m2);
                c = getchar_unlocked();
                if(c == 114){
                    continue;
                }else{
                    if(c == 112){//p
                        ++wins[m2];
                        ++losses[m1];
                    }else{
                        ++wins[m1];
                        ++losses[m2];
                    }
                }
            }else if(c == 115){//s
                fastRead_int(m2);
                c = getchar_unlocked();
                if(c == 115){
                    continue;
                }else{
                    if(c == 114){//r
                        ++wins[m2];
                        ++losses[m1];
                    }else{
                        ++wins[m1];
                        ++losses[m2];
                    }
                }
            }else if(c == 112){//p
                fastRead_int(m2);
                c = getchar_unlocked();
                if(c == 112){
                    continue;
                }else{
                    if(c == 115){//s
                        ++wins[m2];
                        ++losses[m1];
                    }else{
                        ++wins[m1];
                        ++losses[m2];
                    }
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            if((wins[i]+losses[i]) != 0){
                printf("%.3f\n",double(wins[i]/(wins[i]+losses[i])));
            }else{
                printf("-\n");
            }
        }
        printf("\n");
    }
}

