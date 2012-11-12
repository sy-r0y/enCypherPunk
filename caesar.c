/*
 * Implement the Caesar's cipher.
 *
 *
 * ASCII -- (65,66,67.......90)  ||  (97,98,99...122)
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

int main(int argc, char *argv[]) {

  // Get the first command line argument argv[1]--it contains the Key.
  // Convert that argument, from string into an integer.

  int key=atoi(argv[1]);
  printf("\n\n");

  char ch[]="Be sure to drink your Ovaltine!";
  int len=strlen(ch);

  for(int i=0;i<len;i++) {
    printf("%c",ch[i]);
  }
  printf("\n\n");

  for(int i=0;i<len;i++) {
    if(((int)ch[i]>=65)&&((int)ch[i]<=90)) {
      printf("%c",(char)(((((int)ch[i]+key)%65)%26)+65));
    }
    else if(((int)ch[i]>=97)&&((int)ch[i]<=122)) {
      printf("%c",(char)(((((int)ch[i]+key)%97)%26)+97));
    }
    else  
      printf("%c",ch[i]);
  }
  return 0;
}
