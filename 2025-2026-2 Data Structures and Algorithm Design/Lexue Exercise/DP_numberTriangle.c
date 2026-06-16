
// 问题描述: 给定一个有n行数字组成的数字三角形. 试设计一个算法, 计算出从三角形的顶至底的一条路径, 使该路径经过的数字和最大.

// 算法设计: 对于给定的n行数字组成的三角形, 计算从三角形顶至底的路径经过的数字和的最大值.

// 数据输入: 第1行数字三角形的行数n, 1<=n<=100. 接下来n行是数字三角形各行中的数字. 所有数字在0~99之间.

// 结果输出: 第1行中的数是计算出的最大值.

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int ** l=(int **)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
    {
        l[i]=(int *)malloc((i+1)*sizeof(int));
        for (int j=0;j<=i;j++)
        {
            scanf("%d",&l[i][j]);
        }
    }
    int ** sol=(int **)malloc(n*sizeof(int *));
    for (int i=0;i<n;i++)
    {
        sol[i]=(int *)malloc((i+1)*sizeof(int));
    }
    sol[0][0]=l[0][0];
    for (int i=1;i<n;i++)
    {
        sol[i][0]=sol[i-1][0]+l[i][0];
        sol[i][i]=sol[i-1][i-1]+l[i][i];
    }
    for (int i=2;i<n;i++)
    {
        for (int j=1;j<=i-1;j++)
        {
            if (sol[i-1][j-1]<sol[i-1][j])
            {
                sol[i][j]=sol[i-1][j]+l[i][j];
            }
            else
            {
                sol[i][j]=sol[i-1][j-1]+l[i][j];
            }
        }
    }
    int max=sol[n-1][0];
    for (int i=1;i<n;i++)
    {
        if (sol[n-1][i]>max)
        {
            max=sol[n-1][i];
        }
    }
    printf("%d\n",max);
}
