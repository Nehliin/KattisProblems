#include <stdio.h>
#include <iostream>
#include <cmath>

inline void fastRead_int(int &x) {
    register int c = getchar();
    x = 0;
    for(; ((c<48 || c>57)); c = getchar());
    for(; c>47 && c<58 ; c = getchar()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
}

int main(){
    int n;
    int *row1;
    int *row2;
    int *middle;
    fastRead_int(n);
    row1 = new int[n];
    row2 = new int[n];
    int heaviest = 0;
    int start = 0;
    int end = -1;
    bool separated = false;
    bool first = true;
    fastRead_int(row1[0]);
    for(int i = 1; i < n; ++i){
        fastRead_int(row1[i]);
        if(row1[i] == row1[i-1]){
            row1[i] = -row1[i];
            row1[i-1] = -row1[i];
            continue;
        }
        if(row1[i-1] > heaviest){
            heaviest = row1[i-1];
            start = i-1;
        }else{
            if(row1[i-1] == heaviest){
                end = i-1;
            }
        }

    }
    fastRead_int(row2[0]);
    //std::cout << row2[0] << std::endl;
    for(int i = 1; i < n; ++i){
        fastRead_int(row2[i]);
        //std::cout << row2[i] << std::endl;
        if(row2[i] == row2[i-1]){
            row2[i] = -row2[i];
            row2[i-1] = -row2[i-1];
            continue;
        }
        if(row2[i-1] > heaviest){
            if(end == -1){
                separated = true;
            }
            heaviest = row2[i-1];
            start = i-1;
            first = false;
        }else{
            if(row2[i-1] == heaviest && !separated){
                end = i-1;
            }
        }
    }
    int max = 0;
    if(separated){
        printf("%d",heaviest);
        return 0;
    }
    std::cout << first << std::endl;
    std::cout << start << std::endl;
    std::cout << end << std::endl;
    if(first){
        for(int i = start; i < end; ++i){
            if(std::abs(row1[i]) > max){
                max = std::abs(row1[i]);
            }
        }
    }else{
        for(int i = start; i < end; ++i){
            if(std::abs(row2[i]) > max){
                max = std::abs(row2[i]);
            }
        }
    }
    printf("%d",max);
    return 0;
}
