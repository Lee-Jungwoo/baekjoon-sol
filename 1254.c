#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char * c = (char*)malloc(100*sizeof(char));

    scanf("%s",c);

    int l = strlen(c);

    while(1){
        int idx;
        if(l % 2 == 0){
            idx = l / 2 - 1;
            

        }else {

        }
    }

    

}