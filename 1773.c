#include <stdio.h>
#include <stdlib.h>

int findfunc(int i1, int i2, int n) //n is n
{
    int k;
    int lcm;
    int count=0;
    /*LCM 먼저 구하기*/
    lcm = i1 > i2 ? i1 : i2;
    while(1)
    {
        if(lcm%i1==0 && lcm%i2==0)
            break;
        lcm++;
    }
    /*(lcm x j)가 n보단 작게*/
    k = n / lcm;
    return k;
}

int main(void)
{
    int c, n; //
    int fire=0; //하나가 개별적으로 몇번 터지나
    int gong=0; //공배수 개수
    scanf("%d %d", &c, &n);
    int * arr = (int *)malloc(sizeof(int)*c); //arr stores T_i
    for(int i=0;i<c;i++)
    {
        scanf("%d", arr+i);
    }
    for(int i=0; i<c; i++)
    {
        for(int j=i+1; j<c; j++)
        {
            gong += findfunc(arr[i], arr[j], n);
        }
    }
    for(int i=0; i<c; i++)
    {
        fire += n/arr[i];
    }

    printf("%d", fire-gong);
    free(arr);
    return 0;
}
