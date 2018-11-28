#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int main()
{

    FILE *p;
    int word_count=0,temp=0,number=1,i,num,j,k=0,m,n,value=0,set=0;

    printf("\tENTER THE NUMBER OF WORD YOU WANT::::");
    scanf("%d",&word_count);
    printf("\tPassword is::::\n");
    char *word[word_count+2],password[100],ch,str[10];
    srand(time(0));//use current time as seed
    p=fopen("dice.txt","r");

    for(i=1;i<=word_count;i++)
    {
        number=0;
        for(j=1;j<6;j++)
        {
                temp=rand();
                temp=temp%10;
                if(temp>6)
                {
                    temp=temp-3;

                }
                else if(temp==0)
                    temp=1;
                number=number*10+temp;
        }
        //printf("%d\n",number);
        m=0;
        value=0;
        temp=0;
        set=0;
        rewind(p);
        while((ch=fgetc(p))!=EOF)
        {
            if(ch>=48&&ch<=57&&set==0)
            {
                temp=ch-48;
                value=value*10+temp;
            }
            else if(ch=='\t')
            {
                set=1;
            }
            else if(ch!='\n')
            {
                str[m]=ch;
                m++;

            }
            else if(ch=='\n')
            {
                set=0;
                //printf("%d %s\n",value,str);
                str[m]='\0';
               
                m=0;
                
                if(value==number)
                {
                   printf("%s",str);
                    break;

                }
                m=0;value=0;temp=0;
            }
        }

        //printf("%d\n",number);
    }
   
}
