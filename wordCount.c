/* Ester Aguilera */
#include<stdio.h>
#define IN  1  /*inside a word*/
#define OUT 0  /*outside a word*/
int main()
{
  int char_, newLine, newWord, newChar, totalWords, totalChars, state; 
  int tempW, tempC, line_mostWords, line_mostChars;
  tempW = tempC = 0; /*Used to store lines with most chars and words*/
  state = OUT; /* Program begins outside of word initially */
  newLine = newWord = newChar = 0; /* Initialize all other variables to 0 */
  totalWords = totalChars = 0; /* Counters for totals */
  line_mostWords = line_mostChars = 0;
  
  /*Enter loop which reads & counts each new char until EOF is read*/
  while ((char_ = getchar()) != EOF)
  {
    if(newChar == 0)
    {
      ++newLine;
      if(newLine < 10)
	printf(" %d: ", newLine);
      else
	printf("%d: ", newLine);
    }

    /*Checks for new lines first*/
    if(char_ == '\n')
    {
      if ( newChar >= tempC )
      {
       	tempC = newChar;
        line_mostChars = newLine;
      }
      if( newWord >= tempW )
      {
	tempW = newWord;
	line_mostWords = newLine;
      } 
      totalWords+=newWord;
      totalChars+=newChar;
      printf("[%d, %d]\n", newWord, newChar);
      newWord = newChar = 0; /* reset counters */
    }
    else /*Counts characters after checking for new lines*/
    {
      ++newChar;
      printf("%c",char_);
    }

    /*Checks if inside of outside a word*/
    if (char_ == ' ' || char_ == '\n' || char_ == '\t')
      state = OUT;
    else if (state == OUT) 
    {
      state = IN;
      ++newWord;
    }    

  }
  printf("\n%d lines, %d words, %d characters\n", newLine, totalWords, totalChars);
  printf("Line %d has the most words with %d\n", line_mostWords, tempW);
  printf("Line %d has the most characters with %d\n", line_mostChars, tempC);
  return 0;
}
