/*分治法求集合的最大最小元素*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double * maxmin(double * A,int m)
{
    double * ans=(double*)malloc(2*sizeof(double));
    if (m==1)
    {
        ans=(double*)malloc(2*sizeof(double));
        if (A[0]>A[1])
        {
            ans[0]=A[0];
            ans[1]=A[1];
        }
        else
        {
            ans[1]=A[0];
            ans[0]=A[1];
        }
        return ans;
    }
    else
    {
        double * A1=(double*)malloc(pow(2,m-1)*sizeof(double));
        double * A2=(double*)malloc(pow(2,m-1)*sizeof(double));
        for (int i=0;i<=pow(2,m-1)-1;i++)
        {
            A1[i]=A[i];
            A2[i]=A[i+(int)pow(2,m-1)];
        }
        ans=maxmin(A1,m-1);
        double * ans1=maxmin(A2,m-1);
        if (ans1[0]>ans[0])
        {
            ans[0]=ans1[0];
        }
        if (ans1[1]<ans[1])
        {
            ans[1]=ans1[1];
        }
        return ans;
    }
}

int main()
{
    double B[8]={3,1.2,5.4,6.4,8.1,3.5,4.6,4.54};
    double * A=B;
    double * ans=maxmin(A,3);
    printf("max:%f,min:%f. \n",ans[0],ans[1]);
}
