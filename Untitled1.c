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
        printf("��ӭ��������������ϰ��\n");
        printf("�����س�����ʼ���⣩\n");



           getchar();

        printf("\n�����������������Ŀ��");
        while(1)
            {
            scanf("%d",&n);
            if(n<=0)
                printf("����Ŀ��������������!��\n");
            else
                break;
        }

            test1(n);


}

//��һ�����������
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
//�ڶ������������
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

//������������
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

//100������������
void test1(int n)
{
    int i,rightnum=0,wrongnum=0;//rightnumber��ȷ�ĸ���,wrongnumber����ĸ���
    float a,b,c,answer,result;
    char op,op2;//�����
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        a=(float)(rand() % 100+1);//��ȡ�����
        b=(float)(rand() % 100+1);
        c=(float)(rand() % 100+1);
        op=mark();//��ȡ��������
        op2=mark();
        if((op=='+' || op=='-') && (op2=='*' || op2=='/')){
        result=algorithm(a,op,algorithm2(b,op2,c));
        }
        else{
        result=algorithm2(algorithm(a,op,b),op2,c);//������������ȼ��ó����
    }
        if(result< 0)//������Ϊ�������������»�ȡ��Ŀ
        {
            i--;
            continue;
        }
        else{
            printf("%.f %c %.f %c %.f = ",a,op,b,op2,c);
            scanf("%f",&answer);

                if((int)(100.0*answer+0.5)/100.0==(int)(100.0*result+0.5)/100.0 && result>=0)//�������뾫ȷ��С�������λ
                {
                    printf("���ش���ȷ!��\n\n");
                    rightnum++;
                }
                else
                {
                    printf("���ش����!���ǣ�%.2f��\n\n",(int)(100.0*result+0.5)/100.0);
                    wrongnum++;
                }
        }
    }
    printf("���ܹ������%d�⣬׼ȷ��Ϊ%.2f��!\n",n,rightnum,(float)rightnum/(float)n*100);
    system("pause");
    system("CLS");
    printf("\n\n");
}
