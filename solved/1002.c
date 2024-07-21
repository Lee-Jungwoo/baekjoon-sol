#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t;
    int x1, y1, r1, x2, y2, r2;

    scanf("%d", &t);
    

    

    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        float x = sqrt(powl(x1-x2,2) + powl(y1-y2,2)); // 중심 사이 거리
        int l = abs(r1 - r2); // 반지름 차이
        if (r1 == r2 && x1 == x2 && y1 == y2)
        {
            printf("-1");
        }else if (x < l)
        {
            printf("0");
        }else if (x == l){
            printf("1");
        }else if(x > l && x < r1 + r2){
            printf("2");
        }else if(x == r1 + r2){
            printf("1");
        }else if(x > r1 + r2){
            printf("0");
        }
    



        printf("\n");
    }
}