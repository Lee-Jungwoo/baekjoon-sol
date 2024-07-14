#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    int idx = 0;


    int *arr = (int *)malloc(n * sizeof(int));
    int *result = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        int size = (n - i);
        idx += k-1;
        while(idx >= size){
            idx = idx % size;
        }

        result[i] = arr[idx];
        arr[idx] = 0;

        for(int j = idx+1; j<n;j++){
            int tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
        }

        // printf("\niter %d : ", i+1);
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%d ",arr[i]);
        // }

        

    }
    printf("<");
    for (int i = 0; i < n; i++)
    {
        
        printf("%d", result[i]);
        if(i != n-1){
            printf(", ");
        }else {
            printf(">");
        }
    }
    

    // 1 2 3 4 5 6 7
    // 1 2 4 5 6 7 0
    // 1 2 4 5 7 0 0
    //...
}