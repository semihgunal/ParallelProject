#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GetSequences(string ReadFilePath, string Sequences[], int SequenceSize);
double NeedlemanWunsch(string FirstSequance, string SecondSequance);
void WriteSequenceScore(string WriteFilePath, int FirstSequenceNumber, int SecondSequenceNumber, double MatchScore);

