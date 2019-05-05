#include "functions.h"

#define SEQUENCE_SIZE 100

#define READ_FILE_PATH "Sequences/5K_Sequence.fasta"
#define WRITE_FILE_PATH "Sequences/5K_Sequence.yasta"

int main()
{
	string Sequences[SEQUENCE_SIZE];
	
	GetSequences(READ_FILE_PATH, Sequences, SEQUENCE_SIZE);
	
	for (int i = 0; i < SEQUENCE_SIZE; i++)
	{
		for (int j = i + 1; j < SEQUENCE_SIZE; j++)
		{
			WriteSequenceScore(WRITE_FILE_PATH, i, j, NeedlemanWunsch(Sequences[i], Sequences[j]));
		}
	}
	
	system("pause");
}

