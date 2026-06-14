// 问题描述: 长江游艇俱乐部在长江上设置了n个游艇出租站1,2,…,n. 游客可在这些游艇出租站租用游艇, 并在下游的任何一个游艇出租站归还游艇. 游艇出租站i到出租站j之间的租金为r(i,j), 1<=i<j<=n. 试设计一个算法, 计算出从游艇出租站1到游艇出租站n所需的最少租金, 并分析算法的计算复杂性.

// 算法设计: 对于给定的游艇出租站i到游艇出租站j的租金r(i,j), 1<=i<j<=n. 计算出租站1到n所需的最少租金.

// 数据输入: 第1行有一个正整数n, n<=200, 表示有n个游艇出租站. 接下来n-1行是r(i,j), 1<=i<j<=n.

// 结果输出: 游艇出租站1到n最少租金.

#include<stdio.h>

double prices[1000][1000],minfee[1000][1000];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n-1;i++)
    {
        scanf("%lf",&prices[i][i+1]);
        for (int j=i+2;j<=n;j++)
        {
            scanf(" ",NULL);
            scanf("%lf",&prices[i][j]);
        }
    }
    minfee[1][2]=prices[1][2];
    double min;
    for (int i=3;i<=n;i++)
    {
        min=prices[1][i];
        for (int j=2;j<i;j++)
        {
            if (minfee[1][j]+prices[j][i]<min)
            {
                min=minfee[1][j]+prices[j][i];
            }
        }
        minfee[1][i]=min;
    }
    printf("%.0lf\n",minfee[1][n]);
}
