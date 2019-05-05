#include "functions.h"

#include <omp.h>

#define SEQUENCE_SIZE 5000
#define READ_FILE_PATH "Sequences/5K_Sequence.fasta"
#define WRITE_FILE_PATH "Sequences/5K_Sequence.yasta"
/*
#define SEQUENCE_SIZE 10000
#define READ_FILE_PATH "Sequences/10K_Sequence.fasta"
#define WRITE_FILE_PATH "Sequences/10K_Sequence.yasta"
*/
/*
#define SEQUENCE_SIZE 15000
#define READ_FILE_PATH "Sequences/15K_Sequence.fasta"
#define WRITE_FILE_PATH "Sequences/15K_Sequence.yasta"
*/

int main()
{
	string Sequences[SEQUENCE_SIZE];
	
	ifstream ReadFile;
	ReadFile.open(READ_FILE_PATH);
	
	string NowText;
    
	for (int i = 0; i < SEQUENCE_SIZE; i++)
	{
		ReadFile >> NowText;
		ReadFile >> NowText;
		
		Sequences[i] = NowText;
	}
	
	ReadFile.close();
	
	ofstream WriteFile;
	WriteFile.open(WRITE_FILE_PATH);
	
	double Results = 0;
	
	#pragma omp parallel firstprivate(Results) num_threads(8)
    {
		#pragma omp for schedule(dynamic)
		for (int i = 0; i < SEQUENCE_SIZE; i++)
		{
			for (int j = (i + 1); j < SEQUENCE_SIZE; j++)
			{
				Results =  NeedlemanWunsch(Sequences[i], Sequences[j]);
				
				#pragma omp critical
				{
					WriteFile << ">" << i << "-" << j << " " << Results << endl;
				}
			}
		}
	}
	
	WriteFile.close();
	
	system("pause");
}

