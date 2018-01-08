#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define hahaha
void printf_2D_array(int m,int n,int a[m][n]);
void clear_2D_array(int m,int n,int a[m][n]);
void rand_2D_array(int m,int n,int a[m][n]);
void eliminate(int m,int n,int a[m][n],int b[m][n]);
int determinant(int m,int n,int a[m][n],int k);
int main(int argc,char *argv[])     //please give the argu in cmd while processing this promgram
{
    int m,n;
    int d,k;

    m = atoi(argv[1]);  //get the user define
    n = atoi(argv[2]);
    k=n;
    printf("GITHUB");
    printf("%d,%d\n",m,n);     //show the order
    int array1[m][n];
    int array2[m][n];

    //reset array
    clear_2D_array(m,n,array1);
    clear_2D_array(m,n,array2);

    //take random value
    rand_2D_array(m,n,array1);

    //print the origin matrix after taking random value of each elements
    printf_2D_array(m,n,array1);

    //count the det by recursive way if the matrix is square
    if(m==n){
        d=determinant(m,n,array1,k);
        printf("the det value is %d",d);
    }
    else{
        printf("only square matrix exist determinant(m=n)");
        printf("if you want to display the det please make m,n the same order");
    }

    //eliminate the num if there are more than 3 together
    eliminate(m,n,array1,array2);
    printf("\n\n\n");

    //show the matrix after eliminated
    printf_2D_array(m,n,array2);
    return 0;
}
