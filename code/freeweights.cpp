#include <stdio.h>
#include <cmath>

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    for(; ((c<48 || c>57)); c = getchar_unlocked());
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
}

int main(){
    int n;
    int *row1;
    int *row2;
    fastRead_int(n);
    row1 = new int[n];
    row2 = new int[n];
    int firstIndex, secondIndex = 0;
    int firstMove, secondMove = 0;
    int neut = 1;
    bool foundPair = false;
    fastRead_int(row1[0]);
    int firstHeavy = row1[0];
    for(int i = 1; i < n; ++i){
        fastRead_int(row1[i]);
        if(row1[i] == row1[i-1]){
            if(firstHeavy == row1[i]){
                firstHeavy = 0;
            }
            row1[i] = -row1[i];
            row1[i-1] = -row1[i];
            continue;
        }
        if(row1[i] > firstHeavy){
            firstHeavy = row1[i];
            firstIndex = i;
        }else{
            if(row1[i] == firstHeavy){
                foundPair = true;
            }else{
                if(row1[i] > firstMove && !foundPair){
                    firstMove = row1[i];
                }
            }
        }
    }
    foundPair = false;
    fastRead_int(row2[0]);
    int secondHeavy = row2[0];
    for(int i = 1; i < n; ++i){
        fastRead_int(row2[i]);
        if(row2[i] == row2[i-1]){
            if(secondHeavy == row2[i]){
                secondHeavy = 0;
            }
            row2[i] = -row2[i];
            row2[i-1] = -row2[i];

            continue;
        }
        if(row2[i] > secondHeavy){
            secondHeavy = row2[i];
            secondIndex = i;
        }else{
            if(row2[i] == secondHeavy){
                foundPair = true;
            }else{
                if(row2[i] > secondMove && !foundPair){
                    secondMove = row2[i];
                }
            }
        }
    }
    if(secondHeavy == firstHeavy){
        printf("%d",firstHeavy);
        return 0;
    }
    if(firstHeavy > secondHeavy){
        printf("%d",firstMove);
        return 0;
    }else{
        printf("%d",secondMove);
        return 0;
    }

}
