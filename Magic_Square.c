#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  15 /* maximum size of square*/

int main(void)
{/* construct a magic square, iteratively */
   int square[MAX_SIZE][MAX_SIZE];
   int i, j, row, column;   /* indexes*/
   int count;
   int size;

   printf("Enter the size of the square: ");
   scanf("%d", &size);
   /* check for input errors*/
   if (size < 1 || size > MAX_SIZE + 1) {
    fprintf(stderr, "Error!  Size is out of range\n");
    exit(EXIT_FAILURE);
   }
   if (! (size % 2)) {
    fprintf(stderr, "Error!  Size is out of range\n");
    exit(EXIT_FAILURE);
   }
   for (i = 0; i < size; i++)
      for (j = 0; j < size; j++)
        square[i][j] = 0;
   square[0] [ (size-1) / 2] = 1; /* middle of first row */
   /* i and j are current position */
   i = 0;
   j = (size -1) / 2;
   for (count = 2; count <= size * size; count++) {
      row = (i-1 < 0) ? (size -1) : (i - 1); /*up*/
      column = (j-1 < 0) ? (size - 1) : (j - 1); /*left*/
      if (square[row][column])  /*down*/
        i = (++i) % size;
      else {
        i = row;
        j = (j-1 < 0) ? (size -1) : --j;
      }
      square[i][j] = count;
   }
   /* output the magic square */
   printf("Magic Square of size %d : \n\\n", size);
   for (i = 0; i < size; i++) {
     for (j = 0; j < size; j++)
        printf("%5d", square[i] [j]);
     printf("\n");
   }
   printf("\n\n");
}
