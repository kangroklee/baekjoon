#include <stdio.h>
#include <stdlib.h>

#define SQUARE(X) ((X)*(X))

typedef struct pos
{
    int x;
    int y;
    int r;
} POS;

int distance(POS p1, POS p2) //ditch sqrt()
{
    int dsq;
    dsq = SQUARE(p1.x-p2.x)+SQUARE(p1.y-p2.y);
    return dsq;
}

int calc(void)
{
    POS c1, c2;
    scanf("%d %d %d %d %d %d", &c1.x, &c1.y, &c1.r, &c2.x, &c2.y, &c2.r);
    int d = distance(c1, c2);
    if(d==0)
    {
        if(c1.r==c2.r)
            return -1;
        else 
            return 0;
    }
    else 
    {
        if(SQUARE(c1.r-c2.r)<d && d<SQUARE(c1.r+c2.r))
            return 2;
        if(d==SQUARE(c1.r+c2.r) || d==SQUARE(c1.r-c2.r))
            return 1;
        else
            return 0;
    }
}

int main(void)
{
    int num;
    scanf("%d", &num);
    int * result = (int *)malloc(sizeof(int)*num);
    if (result == NULL) {
        fprintf(stderr, "Fatal: failed to allocate.\n");
        return -1;
    }
    for(int i=0;i<num;i++)
    {
        result[i] = calc();
    }   
    for(int i=0;i<num;i++)
    {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}