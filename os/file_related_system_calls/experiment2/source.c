#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
  int number1, number2, sum;
  int output_fds = open("./output.txt", O_WRONLY | O_CREAT);
  int input_fds = open("./input.txt", O_RDONLY | O_CREAT);
  dup2(output_fds, STDOUT_FILENO);
  dup2(input_fds, STDIN_FILENO);
  
  if (output_fds < 0 || input_fds < 0)
  {  
     printf("file open error \n");
     exit(EXIT_FAILURE);
  } 
  scanf("%d %d", &number1, &number2);
  sum = number1 + number2;
  

  printf("%d + %d = %d\n", number1, number2, sum);
  return EXIT_SUCCESS;
}
