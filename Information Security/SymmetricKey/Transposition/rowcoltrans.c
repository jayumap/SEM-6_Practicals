#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
            char k[20]={'\0'},pt[30]={'\0'},key[30]={'\0'},mat[10][10]={'\0'},ct[30]={'\0'};
            int i=0,j=0,no[10]={0},ctr,z,c=0,a=0;
            //clrscr();
            printf("Enter the plaintext:\n");
            gets(pt);
            printf("Enter the key:\n");
            gets(k);
            strcpy(key,k);
            strcat(k,pt);
            strcpy(pt,k);
            printf("Enter the ordering starting from 0 to the (keylength-1):\n");

            for(i=0;i<strlen(key);i++)
            {

                        scanf("%d",&no[i]);
            }
            j=0;
            ctr=j;
            printf("The matrix is:\n");
            for(i=0;i<strlen(pt);i++)
            {
                        for(j=j;ctr<strlen(key);j++)
                        {
                                    if(pt[j]!='\0')
                                    {
                                                mat[i][ctr]=pt[j];
                                                printf("%c",mat[i][ctr]);
                                                ctr++;
                                    }
                                    else
                                    {
                                                goto out;
                                    }
                        }
                        ctr=0;
                        if(i==0) printf("\n");
                        printf("\n");
            }
            out:
            printf("\n\nThe Encrypted  text is:\n");
            for(i=0;i<strlen(key);i++)
            {
                        for(j=0;j<strlen(key);j++)
                        {
                                    if(no[i]==j)
                                    {
                                           for(z=1;z<10;z++)
                                           {
                                                            if(isalpha(mat[z][j]))
                                                            {
                                                            printf("%c",mat[z][j]);
                                                            ct[a]=mat[z][j];
                                                            a++;
                                                            }

                                           }
                                    }
                        }
            }
            printf("\n\nDecrypted Ciphertext is:\n");

            for(a=0;a<30;a++)
            {
            if(isalpha(ct[a]) || isspace(ct[a]))
            c++;
            }

            for(i=1;i<c;i++)
            {
                        for(j=0;j<strlen(key);j++)
                        {
                                    if(isalpha(mat[i][j]))
                                    printf("%c",mat[i][j]);
                                    else
                                    goto ext;
                        }
            }
            ext:

            getch();
}