#include "ReadCSV.h"

ReadCSV::ReadCSV(string file)
{
    string heading;
    inFS.open("titanic_project.csv");

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
            spline.push_back(atof(inS.substr(start, i).c_str()));
            start = i + 1;
        }
    }
    return spline;
}

void ReadCSV::printData()
{
    // for(list<vector<double> >::iterator l = listofvectors.begin(); l != listofvectors.end(); ++l)
    // {
    //     for(vector<double>::iterator v = l->begin(); v != l->end(); v++)
    //     {

    //     }
    // }
}