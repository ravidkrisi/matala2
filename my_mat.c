#include <stdio.h>
#include "my_mat.h"

int copyMatrix(int mat[10][10], int copyMat[10][10])
    {
        //copy matrix for the shortestPath func and fill the zeros with INF
        int i,j;
        
        for(i=0;i<10;i++){
            for(j=i;j<10;j++){
                if(mat[i][j]==0)
                {
                     copyMat[i][j]=INF;
                     copyMat[j][i]=INF;
                }
                else
                {
                copyMat[i][j]=mat[i][j];
                copyMat[j][i]=mat[i][j];
                }
            }
        }
        for(i=0;i<10;i++){
            copyMat[i][i]=0;
        }
        return 0;
    }
    
    int createMat(int mat[10][10])
    {
        //create matrix 10*10 
    int i,j,x;
    
    for(i=0;i<10;i++)
    {
        for(j=i;j<10;j++)
        {
            printf("enter the weight of string[%d,%d]\n",i,j);
            scanf("%d",&x);
            mat[i][j]=x;
            mat[j][i]=x;
        }
    }
    return 0;
    }
      
    int shortestPath(int x, int y, int mat[10][10])
    {
        
        //create a matrix with data of the shortest path between every index
        int copyMat[10][10];
        copyMatrix(mat,copyMat);
        int i,j,k;
        
            for(k=0;k<10;k++){
            for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    if(copyMat[i][j] > copyMat[i][k] + copyMat[k][j])
                    {
                        copyMat[i][j] = copyMat[i][k] + copyMat[k][j];
                    }
                }
            }
        }
        
        return copyMat[x][y];
    }