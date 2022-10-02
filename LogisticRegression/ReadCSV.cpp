#include "ReadCSV.h"


ReadCSV::ReadCSV(string file)
{
    string heading;
    inFS.open(file);

    if(!inFS.is_open())
    {
        cout << "Could not open file " << file << endl;
    }

    getline(inFS, heading);
    cout << "Heading: " << heading << endl;
}

void ReadCSV::grabData()
{
    while(inFS.good())
    {
        getline(inFS, line, '\n');
        listofvectors.push_back(splitData(line, ","));
    }
}

vector<double> ReadCSV::splitData(string inS, string delimeter)
{
    vector<double> spline;
    int start = 0;
    for(int i = start; i < inS.length(); i++)
    {
        if(inS.substr(i, 1).compare(delimeter) == 0)
        {
            spline.push_back(stof(inS.substr(start, i)));
            start = i + 1;
        }
    }
    return spline;
}

void ReadCSV::printData()
{
    list<vector<double>>::iterator iterL;
    for(iterL = listofvectors.begin(); iterL != listofvectors.end(); ++iterL)
    {

        vector<double>::iterator iterV;
        for(iterV = (*iterL).begin(); iterV != (*iterL).end(); ++iterV)
        {
            cout << *iterV;
        }
        cout << endl;
    }
}