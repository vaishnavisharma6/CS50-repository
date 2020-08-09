#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(void)
{  string key;int i,j;
    even:
     key = get_string("enter keyword:\n");
    string plaintext = get_string("enter plaintext:\n");
    int c = strlen(key);
    int d = strlen(plaintext);
    
    for( i=0;i<=c;i++)
    {
        if(key[i]==' ' || (key[i]<'A' && key[i]>'Z')||(key[i]<'a' && key[i]>'z') )
        {
            printf(" ./vigenere keyword");
            goto even;
        }
        
    }printf("success\n");
 
 for(i=0,j=0;j<=d;i++,j++)
 {   if(plaintext[j]==' ')
 {
     j++;
 }
     if(isupper(key[i]) && isupper(plaintext[j]))
     {
         if(('Z'-(int)plaintext[j])< ((int)key[i] -65))
            {
               plaintext[j] ='A'+((key[i]-65)- ('Z'-plaintext[j])-1 );
               
            }
         else
         {
             plaintext[j] = plaintext[j] + ((int)key[i] -65);
         }
     }
     if(islower(key[i]) && islower(plaintext[j]))
     {
         if(('z'-(int)plaintext[j])<((int)key[i]-97))
         {
             plaintext[j] = 'a'+((key[i]-97)-('z'-plaintext[j])-1);
         }
         else
         {
             plaintext[j] = plaintext[j] + ((int)key[i] -97);
         }
     } if(!(isalpha(plaintext[j])))
     {
        plaintext[j] = plaintext[j]; 
     }
     if(i==c && j<d)
     {
         i=0;
     }
 }
 printf("ciphertext:%s \n", plaintext);
    
    
    
    
    
}
  
