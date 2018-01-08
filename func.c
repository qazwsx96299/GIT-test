#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//for printing array(m by n)
void printf_2D_array(int m,int n,int a[m][n]){
    int i,j;

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}


//make the array(m by n) clear
void clear_2D_array(int m,int n,int a[m][n]){
    int i,j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            a[i][j]=0;
        }
    }
}

//take rand
void rand_2D_array(int m,int n,int a[m][n]){
    int i,j;
    srand(time(NULL));      //reset the rand func
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            a[i][j]=(rand() % 3) +1;
        }
    }
}

//check if there are more than 3(include) same elements together
//the eliminated elements will be 1
//else 0
void eliminate(int m,int n,int a[m][n],int b[m][n]){
    int i,j;

    for(i=0; i<m; i++){
        for(j=0; j<n-2; j++){   //avoid over the array
            if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]){
                    b[i][j]=1;
                    b[i][j+1]=1;
                    b[i][j+2]=1;
                }
        }
    }
    for(i=0; i<m-2; i++){   //avoid over the array
        for(j=0; j<n; j++){
            if(a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j]){
                    b[i][j]=1;
                    b[i+1][j]=1;
                    b[i+2][j]=1;
                }
        }
    }
}


int determinant(int m,int n,int a[m][n],int k){
    int det,c,s=1,b[m][n],i,j,x,y;          //x y are b's m n(i j)
    if(k==1){
        return(a[0][0]);
    }
    else {
        det=0;
        for(c=0; c<=(k-1); c++){
            x=0,y=0;                    //set array-b start from [0][0]
           for(i=0;i<k;i++){
                for(j=0;j<k;j++){       //scan origin array a from (0,0) to (i,j)
                    b[i][j]=0;          //reset array b
                    if(i!=0&&j!=c){     //avoid taking the first row
                        b[x][y]=a[i][j];
                        if(y<(k-2)){    //because arrayB's order is arrayA's minus 1
                                        //and i,j is from 0 to k-1 =>x,y is from 0 to k-2.
                                        //But when the y==(k-2) the pointer must turn to the next row,so y
                                        //should be reseted to 0 ; x should +1
                            y++;
                        }
                        else{
                            y=0;
                            x++;
                        }
                    }
                }
           }
           det=det+s*(a[0][c]*determinant(m,n,b,(k-1)));    //recursive function ;the initial value of det is 0
           s=-1*s;                                          //+ - + - + -........
        }
    }
    return (det);
}

