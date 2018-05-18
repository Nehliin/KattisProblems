#include <stdio.h>
#include <stdlib.h>

int main(){
    char input[10000];
    register char c = getchar_unlocked();
    int i = 0;
    while(c != '.'){
        input[i++] = c;
        c = getchar_unlocked();
    }
    int depth = 0;
    int nodes[4000];
    int test[4000];
    for(int i = 0; i < 4000; i++){
        nodes[i] = 0;
        test[i]  = 0;
    }
    printf("%d\n", 0);
    for(int k = 1; k < i; k++){
        for(int j = k; j < i; j++){
            if(input[j] == '('){
                //test[depth] = nodes[depth];
                depth++;
            }else{
                if(input[j] == ')'){
                    depth--;
                    if(depth == 0){
                        test[k]++;
                    }
                    //nodes[depth]++;
                }
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%d\n", test[i]);
    }

}
