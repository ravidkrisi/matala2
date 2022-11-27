    
#include <stdio.h>
#include "my_mat.h"

int main()
{
    char userInput='z';
    int mat[10][10];
    int i,j;
    
    while(userInput!='D')
    {
        printf("enter the action you want to do");
        scanf("%c", &userInput);
        
        if(userInput=='A')
        {
            //create the matrix
           createMat(mat);
        }
        else if(userInput=='B')
        {
            //ask the user for i,j input and check wheather there is a path between them
           printf("enter the i and j you want to check if there is Path Exist");
           scanf("%d%d",&i,&j);
           int isExist=shortestPath(i,j,mat);
           if(isExist!=INF&&isExist!=0)
           {
               printf("TRUE");
           }
           else
           {
               printf("FALSE");
           }
        }
        else if(userInput=='C')
        {
            //ask the user for i,j input and return the shortest path between then else return -1
            printf("enter the i and j you want to check the shortest path between them");
            scanf("%d%d",&i,&j);
            int isExist=shortestPath(i,j,mat);
            if(isExist!=INF&&isExist!=0)
           {
               printf("%d",isExist);
           }
           else
           {
               printf("-1");
           }
        }
    }
    return 0;
}
    