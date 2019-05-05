#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void GetSequenceResult(string FilePath, string MatchInfo[], double MatchScore[], int LineSize);
void BubbleSort(string MatchInfo[], double MatchScore[], int MaxSize);
void GetMax(string MatchInfo[], double MatchScore[], int MaxSize, int LineSize);

