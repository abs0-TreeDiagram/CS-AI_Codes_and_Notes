#include<stdio.h>
#include<math.h>

//测试用例

#define N 10

double A[N]={3,-8,5,-3,6,4,8,-4,4,3};

/* 

#define N 4

double A[4] = {-1, -2, -3, -4};



#define N 5

double A[5] = {1, 2, 3, 4, 5};


#define N 9

double A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};


#define N 1

double A[1] = {5};


#define N 1

double A[1] = {-5}; 


#define N 5

double A[5] = {0, -1, 2, -3, 5};


#define N 5

double A[5] = {2, -1, 2, -1, 2};


#define N 6

double A[6] = {-1, -2, 3, -10, 4, 5};*/


double maxsubsum(double * start,int len)
{
    if (len==1)
    {
        return fmax(*start,0);
    }
    else
    {
        double override=0,temp=0;
        for (int i=len/2-1;i>=0;i--)
        {
            temp+=*(start+i);
            if (temp > override)
            {
                override=temp;
            }
        }
        temp=override;
        for (int i=len/2;i<len;i++)
        {
            temp+=*(start+i);
            if (temp > override)
            {
                override=temp;
            }
        }
        return (fmax(maxsubsum(start,len/2),fmax(override,fmax(maxsubsum(start+len/2,len-len/2),0))));
    }
}

int main()
{
    printf("%f",maxsubsum(&A[0],N));
}
