/*
 *
 * Implement the Vigenere cipher.
 *
 * c(i)=[p(i)+k(j)]%26
 * 
 * p[]={Hello Wordl}
 * k[]={KEYWORD}
 *
 * [[H+K}[e+E][l+Y][l+W][o+O] [W+R][o+D][r+K][l+E][d+Y]]
 *
 */
#include<stdio.h>
#include<string.h>

int
main(int argc, char *argv[]) {

  if(argc!=2){
    printf("\n One and only one argument needed.\n EXITING...");
    return 1;
  }
  char *key=argv[1]; //Keyword

  char ch[]={"Meet me at the park at eleven am"}; //Plaintext.
   
  int keylen,chlen;
  keylen=strlen(key);
  chlen=strlen(ch);
  
  printf("\n");
  for(int i=0;i<chlen;i++)
    printf("%c",ch[i]);

  printf("\n\n");
  for(int i=0,x=0;i<chlen;i++) {
    
    int ch_ascii=(int)ch[i]; //Get ASCII code of character.

    if(((ch_ascii>=65)&&(ch_ascii<=90))||((ch_ascii>=97)&&(ch_ascii<=122))) {
      int j=((x++)%keylen);

      int key_ascii=(int)key[j]; //Get ASCII code of the keyword character.
      int key_index;
      if((key_ascii>=65)&&(key_ascii<=90)) //For upper case characters.
	key_index=((key_ascii%65)%26);

      if((key_ascii>=97)&&(key_ascii<=122)) //For lower case characters.
	key_index=((key_ascii%97)%26);

      if((ch_ascii>=97)&&(ch_ascii<=122)) //For lower case letter.
	printf("%c",(char)((((ch_ascii+key_index)%97)%26)+97));

      else //For upper case letter
	printf("%c",(char)((((ch_ascii+key_index)%65)%26)+65));
    }
    else 
      printf("\n");
  }
  return 0;
}
