#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>

float algorithm(float x,char op,float y);
float algorithm2(float x,char op2,float y);
char createnumberop();
void test1(int n);

main()
{
    int chooce,n;
    system("color fc");
        printf("欢迎来到四则运算练习题\n");
        printf("（按回车键开始做题）\n");



           getchar();

        printf("\n请输入四则运算的数目：");
        while(1)
            {
            scanf("%d",&n);
            if(n<=0)
                printf("【数目有误，请重新输入!】\n");
            else
                break;
        }

            test1(n);


}

//第一个运算符计算
float algorithm(float x,char op,float y)
{
    float result;
    switch(op)
    {
    case'+':result = x + y;break;
    case'-':result = x - y;break;
    case'*':result = x * y;break;
    case'/':result = x / y;break;
    }
    return result;
}
//第二个运算符计算
float algorithm2(float x,char op2,float y)
{
    float result;
    switch(op2)
    {
    case'+':result = x + y;break;
    case'-':result = x - y;break;
    case'*':result = x * y;break;
    case'/':result = x / y;break;
    }
    return result;
}

//随机产生运算符
char mark()
{
    int op;
    op=rand() % 4+1;
    switch(op)
    {
    case 1:return'+';
    case 2:return'-';
    case 3:return'*';
    case 4:return'/';
    }
    return 0;
}

//100以内四则运算
void test1(int n)
{
    int i,rightnum=0,wrongnum=0;//rightnumber正确的个数,wrongnumber错误的个数
    float a,b,c,answer,result;
    char op,op2;//运算符
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        a=(float)(rand() % 100+1);//获取随机数
        b=(float)(rand() % 100+1);
        c=(float)(rand() % 100+1);
        op=mark();//获取随机运算符
        op2=mark();
        if((op=='+' || op=='-') && (op2=='*' || op2=='/')){
        result=algorithm(a,op,algorithm2(b,op2,c));
        }
        else{
        result=algorithm2(algorithm(a,op,b),op2,c);//根据运算符优先级得出结果
    }
        if(result< 0)//如果结果为非正数，则重新获取题目
        {
            i--;
            continue;
        }
        else{
            printf("%.f %c %.f %c %.f = ",a,op,b,op2,c);
            scanf("%f",&answer);

                if((int)(100.0*answer+0.5)/100.0==(int)(100.0*result+0.5)/100.0 && result>=0)//四舍五入精确到小数点后两位
                {
                    printf("【回答正确!】\n\n");
                    rightnum++;
                }
                else
                {
                    printf("【回答错误!答案是：%.2f】\n\n",(int)(100.0*result+0.5)/100.0);
                    wrongnum++;
                }
        }
    }
    printf("你总共答对了%d题，准确率为%.2f％!\n",n,rightnum,(float)rightnum/(float)n*100);
    system("pause");
    system("CLS");
    printf("\n\n");
}
