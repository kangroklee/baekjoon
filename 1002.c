#include <stdio.h>
#include <stdlib.h>

#define SQUARE(X) ((X)*(X))

typedef struct pos
{
    int x;
    int y;
    int r;
} POS;

/* 소수의 배신
double distance(POS p1, POS p2)
{
    double d;
    d = (double)sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
    return d;
}
*/

int distance(POS p1, POS p2) //ditch sqrt()
{
    int dsq;
    dsq = SQUARE(p1.x-p2.x)+SQUARE(p1.y-p2.y);
    return dsq;
}

void calc(int * result, int iter)
{
    POS c1, c2;
    scanf("%d %d %d %d %d %d", &c1.x, &c1.y, &c1.r, &c2.x, &c2.y, &c2.r);
    if(distance(c1, c2)==0 && c1.r==c2.r)
        result[iter] = -1;
    else if(distance(c1, c2)==SQUARE(c1.r+c2.r))
        result[iter] = 1;
    else if(distance(c1, c2)<SQUARE(c1.r+c2.r))
        result[iter] = 2;
    else 
        result[iter] = 0;
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
        calc(result, i);
    }   
    for(int i=0;i<num;i++)
    {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}