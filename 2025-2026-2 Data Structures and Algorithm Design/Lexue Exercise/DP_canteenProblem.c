// 阿邱最近开了家餐厅。阿邱想了解某一时段至少有多少不同人出入餐厅。阿邱就雇佣了一个人，呆在餐厅门口，有人进入餐厅，他就在纸上记下+，有人出餐厅，他就在纸上记下-。

// 假设同一时间没有两个人同时进入或出餐厅；也假设最初的时候餐厅中有足够多的人。问，这段时间里，至少有多少人出入餐厅。（不同人出入的顺序是随意的，一个人可以反复出入。）

// Input

// 第一行是一个正整数m，表示有m组测试数据。（m<=100）

// 每组测试数据是一个由字符'+'和'-'组成的字符串。字符一个接一个，之间没有其他的分隔符，字符串的长度<=200。

// Output

// 对于每一组测试数据输出一行，最少数量的人。


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int ct=1;ct<=n;ct++)
    {
        int in[200]={0},out[200]={0},min[200]={0};
        char str[200];
        scanf("%s",&str);
        int len=strlen(str);
        for (int i=1;i<=len;i++)
        {
            if (str[i-1]=='+')
            {
                if (out[i-1]==0)
                {
                    in[i]=in[i-1]+1;
                    out[i]=out[i-1];
                    min[i]=min[i-1]+1;
                }
                else
                {
                    in[i]=in[i-1]+1;
                    out[i]=out[i-1]-1;
                    min[i]=min[i-1];
                }
                
            }
            else if (str[i-1]=='-')
            {
                if (in[i-1]==0)
                {
                    out[i]=out[i-1]+1;
                    min[i]=min[i-1]+1;
                    in[i]=in[i-1];
                }
                else
                {
                    in[i]=in[i-1]-1;
                    out[i]=out[i-1]+1;
                    min[i]=min[i-1];
                }
            }
        }
        printf("%d\n",min[len]);
    }
}
