#include "class2.h"


int readScore(char* _class_name, STclass *_class, int* _score, int _count)
{
	if ( _class_name == NULL || _class == NULL || _score == NULL)
	{
		return -1;
	}
	memset(_class, 0, sizeof(STclass));
	strncpy(_class->name, _class_name, LEN_CLASS_NAME);

	int count = 0;
	for (int i = 0; i < _count; i++, count++)
	{
		_class->students[count].num = i + 1;				//번호 i+1 1부터 시작 
		_class->students[count].score = _score[i]; 		
			//i번째에 스코어 save
	}	
	_class->count = count;

	return count;
}

int sortScore(STclass *_class)
{
	if (_class == NULL) 
	{
		return -1;
	}

	int temp = 0;
	int count = 0;
	for (int i = 0; i < _class->count; i++)
	{
		for (int j = i; j < _class->count; j++)
		{
			if (_class->students[i].score < _class->students[j].score) 
			{
				temp = _class->students[i].score;
				_class->students[i].score = _class->students[j].score; 
				_class->students[j].score = temp;
				count++;
			}
		}
	}
	for (int i = 0; i < _class->count; ++i)
	{
		_class->students[i].rank = i + 1;
	}
	return count;
}

int printScore(int _rank, STclass *_class)
{
	if (_class == NULL)
	{
		return -1;
	}
	for (int i = 0; i < _class->count; i++)
	{
		if ( _rank == _class->students[i].rank )
			printf("[Class:%s], [Rank:%d], [Score:%d]\n",
					_class->name, _class->students[i].rank, _class->students[i].score);
		return 0;
	}
	printf("[EMPTY RANK :: %d]\n", _rank);
	return -1;
}



int main( int argc, char* argv[] )
{
	int scoreA[] = {10, 11, 12, 13, 14, 15, 16, 17, 18};
	int scoreB[] = {11, 21, 31, 41, 51, 61, 71};
	STclass myclass[2];

	int countA = sizeof(scoreA)/sizeof(int);
	int countB = sizeof(scoreB)/sizeof(int);

	readScore((char*)"CLASS_A", &myclass[0], scoreA, countA);

	readScore((char*)"CLASS_B", &myclass[1], scoreB, countB);


	sortScore(&myclass[0]);

	sortScore(&myclass[1]);


	printScore(1, &myclass[0]);
	printScore(1, &myclass[1]);


	return 0;
}