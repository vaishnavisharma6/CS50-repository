#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{ int key;
    string s= get_string("plain text:\n");             //prompt user for pliantext
   even:                                       
    key = get_int("enter key:\n");
   
   if(isalpha(key) || key ==' ')                                          //prompt user for key
   {
       printf("usage: ./caesar key \n");              
       goto even;                                //prompt user again for key 
   } 
   else{
       printf("success\n");
   }
   int c= strlen(s);                         //find length of plaintext
      for(int i=0;i<c;i++)
     {  if(  isupper(s[i]) )                 //condition for uppercase letters
     {
        if ( ('Z'- (int)s[i] )>=key)        //process for changing letters in plaintext
        {
            s[i]=s[i]+ key;
        }
         else
         {
             s[i]= 'A'+((key-('Z'-s[i]))-1);      //change each letter according to difference
         }
     }
          if( islower(s[i]))          //condition for lowercase letters
                          {
                              if(  ('z'-(int)s[i]) >=key )      //process for changing letters in plaintext
                                  {
                                     s[i] =s[i] + key;        //change each letter
                                  }
                              else{
                                  s[i]='a'+((key -('z'-s[i]))-1);     //change each lowercase letter
                                  }
                          }
     }
   
 printf("ciphertext:%s", s);     //print ciphertext after all processes
 printf("\n");                 // change line
}       
