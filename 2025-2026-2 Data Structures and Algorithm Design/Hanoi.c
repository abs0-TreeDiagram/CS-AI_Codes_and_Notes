#include<stdio.h>

//输入圆盘数n，展示将n个圆盘从第一根杆移动到第二根杆的过程
int list[3][100]={0};//声明全局列表：一行代表一杆

void step(int i,int j)
{
    //基元操作：将杆i的最上方圆盘移动到杆j
    int size,p;
    //寻找起始杆最上方圆盘
    for (p=0;list[i][p]!=0;p++);
    p--;
    size=list[i][p];//圆盘大小
    //执行移动
    list[i][p]=0;
    for (p=0;list[j][p]!=0;p++);//寻找终到杆最上方位置
    list[j][p]=size;
    //输出此步移动结果
    printf("\n\n");
    for (int m=0;m<3;m++)
    {
        printf("rod %d:",m);
        for (int n=0;list[m][n]!=0;n++)
        {
            printf("%4d",list[m][n]);
        }
        printf("\n");
    }
}

void move(int i,int j,int k,int n)
{
    //起始杆，中间杆，终到杆，圆盘数
    /*
    将n个顺序圆盘从i移动到k的过程：
    上面n-1个圆盘：i到j
    第n个圆盘：i到k
    上面n-1个圆盘：j到k

    若n=1，直接移动即可
    */
    if (n==1)
    {
        step(i,k);
    }
    else
    {
        move(i,k,j,n-1);
        step(i,k);
        move(j,i,k,n-1);
    }
}

int main()
{
    printf("圆盘数：");
    int n;
    scanf("%d",&n);

    //初始化数组：将圆盘放在第一个杆
    for (int i=n-1;i>=0;i--)
    {
        list[0][i]=n-i;
    }
    move(0,1,2,n);//从第一个杆移动到第三个杆
}
