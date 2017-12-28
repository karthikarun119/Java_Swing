#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int keyword_library(char temp[]);
 
int main()
{
      char ch, var[40], op[] = ")(=+-*/(",pa[]="{}";
      FILE *fp;
      int count, x = 0,i;
      fp = fopen("program.txt","r");
      if(fp == NULL)
      {
            printf("The file could not be opened.\n");
            exit(0);
      }
      while((ch = fgetc(fp)) != EOF)
      {
            count = 0;
        	for(i=0;i<8;i++){
                  	if(ch==op[i])
                  	{
                  	      printf("\nOperator:\t%c", ch);
                  	}
                  }
			for(i=0;i<2;i++){
                  	if(ch==pa[i])
                  	{
                  	      printf("\nParanthesis:\t%c", ch);
                  	}
                  }		
	//count = count + 1;
            
            if(isalnum(ch))
            {
                  var[x++] = ch;
            }
            else if((ch == '\n' || ch == ' ')  && (x != 0))
            {
                  var[x] = '\0';
                  x = 0;
                  if(keyword(var) == 1)
                  {
                        printf("\nKeyword:\t%s", var);
                  }
                  else 
                  {
                        printf("\nIdentifier:\t%s",var);
			
                  }
            }
      }
      fclose(fp);

      return 0;
}
 
int keyword(char temp[])
{
      int count = 0, flag = 0;
      char keywords[7][12] = {"continue", "int","float","void","main","long","double"};
      while(count <= 7)
      {
            if(strcmp(keywords[count], temp) == 0)
            {
                  flag = 1;
                  break;
            }
            count = count + 1;
      }
      return (flag);
}
