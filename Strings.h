#ifndef Strings_H_
#define Strings_H_


void StringsGetStr (char* str, int size);
unsigned char StringsFindCommand (char *str, char command[]);
void StringsFindWords(char *str,char command[]);
void StringsCommand (char *str, char *position);
void StringsDynamicsGetStr (char **str, size_t n);









#endif 
