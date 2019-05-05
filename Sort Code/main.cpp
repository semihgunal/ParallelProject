#include "functions.h"

#define LINE_SIZE 12497500
#define FILE_PATH "Sequences/5K_Sequence.yasta"
/*
#define LINE_SIZE 49995000
#define FILE_PATH "Sequences/10K_Sequence.yasta"
*/
/*
#define LINE_SIZE 112492500
#define FILE_PATH "Sequences/15K_Sequence.yasta"
*/

#define MAX_SIZE 100

int main(void)
{
	double * MatchScore = new double[LINE_SIZE];
	string * MatchInfo = new string [LINE_SIZE];
	
	for(int i = 0; i < LINE_SIZE; i++)
	{
		MatchScore[i] = 0;
	}
	
	GetSequenceResult(FILE_PATH, MatchInfo, MatchScore, LINE_SIZE);
	
	GetMax(MatchInfo, MatchScore, MAX_SIZE, LINE_SIZE);
	
	system("pause");
}

