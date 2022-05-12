#ifndef __class2_h__  
#define __class2_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STstudent
{
	int num;
	int rank;
	int score;
}STstudent;

#define MAX_STUDENTS  (100)
#define LEN_CLASS_NAME  (32)

typedef struct STclass
{
	char name[LEN_CLASS_NAME];
	int count;
	STstudent students[MAX_STUDENTS];
}STclass;

int readScore(char* _class_name, STclass *_class, int* _score, int _count);
int sortScore(STclass *_class);
int printScore(int _rank, STclass *_class);

#endif /* __class2_h__ */
