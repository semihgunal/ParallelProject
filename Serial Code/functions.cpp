#include "functions.h"

#define GAP_POINT -1.832482334
#define MATCH_POINT 3.621354295
#define MISMATCH_POINT -2.451795405

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

void GetSequences(string ReadFilePath, string Sequences[], int SequenceSize)
{
	ifstream File;
	File.open(ReadFilePath.c_str());
	
	string TempSequence;
	
	int Step = 0;
	
    while(Step < SequenceSize)
    {
		File >> TempSequence;
    	File >> TempSequence;
    	
    	Sequences[Step] = TempSequence;
    	
		Step++;
	}
	
    File.close();
}

double NeedlemanWunsch(string FirstSequance, string SecondSequance)
{
	double TempMissmatchScore = 0;
	double TempGapLeftScore = 0;
	double TempGapUpScore = 0;
	
	int Matrix_X = FirstSequance.length() + 1;
	int Matrix_Y = SecondSequance.length() + 1;
	
	double FastaMatrix[Matrix_X][Matrix_Y];
	
	// First Value Set FastaMatrix
	for (int i = 0; i < Matrix_X; i++)
	{
		for (int j = 0; j < Matrix_Y; j++)
		{
			FastaMatrix[i][j] = 0;
		}
	}
	
	// Gap Score Set FastaMatrix_X
	for (int i = 0; i < Matrix_X ; i++)
	{
		FastaMatrix[i][0] = GAP_POINT * i;
	}
	
	// Gap Score Set FastaMatrix_Y
	for (int j = 0; j < Matrix_Y ; j++)
	{
		FastaMatrix[0][j] = GAP_POINT * j;
	}
	
	// Needleman-Wunsch Algorithm
	for (int i = 1; i < Matrix_X; i++)
	{
		for (int j = 1; j < Matrix_Y; j++)
		{
			if(FirstSequance[i - 1] == SecondSequance[j - 1])
			{
				FastaMatrix[i][j] = FastaMatrix[i - 1][j - 1] + MATCH_POINT;
			}
			else if (FirstSequance[i - 1] != SecondSequance[j - 1])
			{
				TempMissmatchScore = FastaMatrix[i - 1][j - 1] + MISMATCH_POINT;
				TempGapLeftScore = FastaMatrix[i][j - 1] + GAP_POINT;
				TempGapUpScore = FastaMatrix[i - 1][j] + GAP_POINT;
				
				FastaMatrix[i][j] = MAX(MAX(TempGapLeftScore, TempGapUpScore), TempMissmatchScore);
				
				/*
				if (TempMissmatchScore >= TempGapLeftScore && TempMissmatchScore >= TempGapUpScore)
				{
					FastaMatrix[i][j] = TempMissmatchScore;
				}
				else if(TempGapLeftScore >= TempMissmatchScore && TempGapLeftScore >= TempGapUpScore)
				{
					FastaMatrix[i][j] = TempGapLeftScore;
				}
				else
				{
					FastaMatrix[i][j] = TempGapUpScore;
				}
				*/
			}
		}
	}
	
	return FastaMatrix[FirstSequance.length()][SecondSequance.length()];
}

void WriteSequenceScore(string WriteFilePath, int FirstSequenceNumber, int SecondSequenceNumber, double MatchScore)
{
	ofstream File;
	File.open(WriteFilePath.c_str(), ios::app);
	
	File << ">" << FirstSequenceNumber << "-" << SecondSequenceNumber << " " << MatchScore << endl;
	
	File.close();
}

