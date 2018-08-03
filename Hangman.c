#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,j,result=0,strike=8,k=0;
    char word[10],guess[10],a,end,let;
    printf("\nEnter the word Player1::");
    gets(word);
    system("clear");
    int len=strlen(word);
    printf("\nYour word is::");
    char new[len],unique[len],check[8];
    strcpy(unique,word);
    for(i=0;i<len;i++)
    {
       new[i]='_';
       printf("_ ");
    }
    a:
    printf("\nenter Y to guess word or N to guess letter::");
    char ch;
    scanf("%s",&ch);
    if(ch=='y' || ch=='Y')
    {
       printf("\nguess the word::");
       scanf("%s",&guess);
       if(strcmp(guess,unique)==0)
       {
          result=1;
          goto end;
       }
       else
       {
         result=0;
         printf("\nyour guess is wrong");
         strike--;
         printf("\nYou have %d strikes left",strike);
         if(strike==0)
           goto end;
         else
           goto a;
       }
    }
    else
    {
         printf("\nGuess the letter::");
         scanf("%s",&let);
         for(i=0;i<len;i++)
         {
            if(word[i]==let)
            {
               new[i]=let;
               word[i]=' ';
               printf("\nYour guess is correct");
               printf("\nYou have %d strikes left",strike);
               printf("\nYour word is:: %s",new);
               if(strcmp(new,unique)==0)
               {
                  result=1;
                  goto end;
               }
               else
                  goto a;
            }
         }
         for(j=0;j<8;j++)
         {
            if(check[j]==let)
            {
                printf("\nDon,t guess the same word again which you have already guessed");
                goto a;
            }
         }
         check[k++]=let;
         result=0;
         printf("\nyour guess is wrong");
         strike--;
         printf("\nYou have %d strikes left",strike);
         printf("\nYour word is:: %s",new);
         if(strike==0)
            goto end;
         else
            goto a;
    }
    end:
    if(result==1)
    {
        printf("\nCONGRATULATION!!!\nYou won the match\nThe word was :: %s",unique);
    }
    else
    {
        printf("\nSORRY!!!\nYou loose the match\nThe word was ::%s",unique);
    }
    return 0;
}
