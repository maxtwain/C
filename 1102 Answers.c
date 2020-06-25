#include <stdio.h>

/*

True or False

A) Function fscanf cannot be used to read data from the standard input.
FALSE.  fscanf(stdin, "%dformat", variable) may be used.

B) You must explicitly use fopen to open the standard input, standar output and standard error streams.
FALSE.  stdin, stdout, stderr are automatically opened.

C) A program must explicitly call the function fclose to close a file.
FALSE. Though it is good practice.

D) If the file position pointer points to a location in a sequential file other than the beginning of the file, the file must be closed and reopened to read from the beginning of the file.
FALSE.  fseek(*ptr, offset, SEEK_SET) may be used.

E) Function fprintf can write to the standard output.
TRUE.  fprintf(stdout, "%dformat", variable).

F) Data in sequential access files is always updated without overwriting other data.
FALSE.  

G) It's not necessary to search through all the records in a random access file to find a specific record.
TRUE.

H) Records in random access files are not of uniform length.
FALSE.

I) Function fseek may seek only relative to the beginning of a file.
FALSE.  SEEK_SET, SEEK_CUR, SEEK_END may be used to search from the beginning, current position, or the end of the file.

*/
int main(void) {

}