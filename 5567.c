#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findfriends(int rows, int * ptr, int * ptr2)
{
    int n1, n2;
    //int const d = rows;
    //int temparr[d*2] = {0}; 
    //int arr[rows*2];
    int *temparr = (int *)malloc(sizeof(int)*rows*2); 
    memset(temparr, 0, rows*2*sizeof(temparr[0]));
    /*direct friends of 1*/
    for(int i=0;i<rows;i++)
    {
        scanf("%d %d", &n1, &n2);
        /*temp add scanf values to main arr*/
        temparr[2*i] = n1;
        temparr[2*i+1] = n2;

        if(n1 != 1 && n2 != 1)
            continue;
        else if(n1 == 1)
            ptr[(n2-1)] = 1;
        else 
            ptr[(n1-1)] = 1;
    }
    /*friends of direct friends*/
    for(int i=0;i<rows;i++)
    {
        n1 = temparr[2*i];
        n2 = temparr[2*i+1];

        if(ptr[n1-1] == 1)
            ptr2[n2-1] = 2;
        if(ptr[n2-1] == 1)
            ptr2[n1-1] = 2;
    }
    free(temparr);
}

int main(void)
{
    int pplnum, rows;
    int invitee_count=0;
    scanf("%d", &pplnum);
    scanf("%d", &rows);
    int * arr = (int *)malloc(sizeof(int)*pplnum);
    int * arr2 = (int *)malloc(sizeof(int)*pplnum); //dupe of arr
    memset(arr, 0, pplnum*sizeof(arr[0]));
    memset(arr2, 0, pplnum*sizeof(arr2[0]));
    
    findfriends(rows, arr, arr2); 
    arr[0] = 0;
    arr2[0] = 0;
    for(int i=0;i<pplnum;i++)
    {
        if(arr[i]==1 || arr2[i]==2)
        {
            invitee_count++;
            //printf("DEBUG: #ppl: %d count: %d\n", i+1, invitee_count);
        }
            
    }
    
    printf("%d", invitee_count); 
    free(arr);
    free(arr2);
    return 0;
}