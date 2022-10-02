#include "PCH.h"

using namespace std;

class ReadCSV
{
    public:
        ReadCSV(string file);

        void grabData();
        vector<double> splitData(string inS, string delimeter);
        void printData();
    private:
        ifstream inFS;
        string line;
        list<vector<double>> listofvectors;
        vector<double> sampleV;
};