#include "functions.h"

void GetSequenceResult(string FilePath, string MatchInfo[], double MatchScore[], int LineSize)
{
	ifstream File;
	File.open(FilePath.c_str());
	
	char Temp;
	string TempInfo;
	string TempScore;
	
	int Step = 0;
	
    while(Step < LineSize)
    {
    	Temp = File.get();
		
		File >> TempInfo;
		File >> TempScore;
		
		MatchInfo[Step] = TempInfo;
		MatchScore[Step] = stod(TempScore);
    	
    	Temp = File.get();
    	
		Step++;
	}
	
    File.close();
}

void BubbleSort(string MatchInfo[], double MatchScore[], int MaxSize)
{
	string TempInfo;
	double TempScore = 0;
	
    for(int i = 0; i < MaxSize; i++)
    {
    	for(int j = MaxSize - 1; j > 0; j--)
    	{
        	if(MatchScore[j - 1] > MatchScore[j])
        	{
        		TempInfo = MatchInfo[j - 1];
          		TempScore = MatchScore[j - 1];
          		
          		MatchInfo[j - 1] = MatchInfo[j];
          		MatchScore[j - 1] = MatchScore[j];
          		
          		MatchInfo[j] = TempInfo;
          		MatchScore[j] = TempScore;
        	}
      	}
    }
}

void GetMax(string MatchInfo[], double MatchScore[], int MaxSize, int LineSize)
{
	string Max20Info[MaxSize];
	double Max20Score[MaxSize];
	
	for (int i = 0; i < MaxSize; i++)
	{
		Max20Score[i] = 0;
	}
	
	for(int i = 0; i < LineSize; i++)
	{
		if (MatchScore[i] > Max20Score[0])
		{
			Max20Info[0] = MatchInfo[i];
			Max20Score[0] = MatchScore[i];
			
			BubbleSort(Max20Info, Max20Score, MaxSize);
		}
	}
	
	for(int i = 0; i < MaxSize; i++)
	{
		cout << i + 1 << "# " << Max20Info[MaxSize - i - 1] << " --> " << Max20Score[MaxSize - i - 1] << endl;
	}
}

