/*最大子段和问题：
找出给定数列的连续子列
使得该子列的和在所有这样的连续子列中和最大
输出最大的求和结果
直接法：循环遍历子段*/
#include<stdio.h>

#define N 9

int l[N]={2,-3,1,5,-1,3,-2,-3,3};

int main()
{
    int max=0,sum,start,end;
    for (int i=0;i<N;i++)//遍历每个连续子段
    {
        sum=0;
        for (int j=i;j<N;j++)
        {
            sum+=l[j];
            if (sum>max)
            {
                max=sum;
                start=i;
                end=j;
            }
        }
    }
    printf("Max sum:%d\nStart:%d\nEnd:%d",max,start,end);
}

/*时间复杂度分析：
二重循环，最内层执行次数为N+(N-1)+...+1=N(N+1)/2
故时间复杂度为O(N^2)*/