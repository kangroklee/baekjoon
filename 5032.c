#include <stdio.h>

int main(void)
{
    int e, f, c;
    int oldbottles;
    int newbottles=0;

    scanf("%d %d %d", &e, &f, &c);
    oldbottles = e+f;
    while(oldbottles >= c)
    {
        newbottles += oldbottles/c;
        oldbottles = oldbottles/c + oldbottles%c;
    }
    printf("%d", newbottles);
    return 0;
}