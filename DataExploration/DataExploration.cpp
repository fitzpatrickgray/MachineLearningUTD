#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void print_stats(vector<double> vec);
double covar(vector<double> vecX, vector<double> vecY);
double cor(vector<double> vecX, vector<double> vecY);

class Range
{
    public:
    double min = 0;
    double max = 0;
};

int main()
{
    ifstream inFS;
    string line;
    string rm_in, medv_in;
    const int MAX_LEN = 1000;
    vector<double> rm(MAX_LEN);
    vector<double> medv(MAX_LEN);

    // credit to cpluplus.com for setting up idx, second parameter of stof
    string::size_type sz;
    //
    cout << "Opening file Boston.csv" << endl;

    inFS.open("Boston.csv");
    if(!inFS.is_open())
    {
        cout << "Could not open file Boston.csv" << endl;
        return 1;
    }

    cout << "Reading line 1" << endl;
    getline(inFS, line);

    cout << "heading: " << line << endl;

    int numObservations = 0;
    while(inFS.good())
    {
        getline(inFS, rm_in, ',');
        getline(inFS, medv_in, '\n');
        rm.at(numObservations) = stof(rm_in, &sz);
        medv.at(numObservations) = stof(medv_in, &sz);

        numObservations++;
    }

    rm.resize(numObservations);
    medv.resize(numObservations);

    cout << "new length " << rm.size() << endl;

    cout << "Closing file Boston.csv." << endl;
    inFS.close();

    cout << "Number of records: " << numObservations << endl;

    cout << "\nStats for rm" << endl;
    print_stats(rm);

    cout << "\nStats for medv" << endl;
    print_stats(medv);

    cout << "\n Covariance = " << covar(rm, medv) << endl;

    cout << "\n Correlation = " << cor(rm, medv) << endl;

    cout << "\nProgram terminated.";
    
    return 0;
}

double sum(vector<double> vec)
{
    double sum = 0;

    for(int i = 0; i < vec.size(); i++)
    {
        sum += vec.at(i);
    }

    return sum;
}

double mean(vector<double> vec)
{
    return sum(vec) / vec.size();
}

double median(vector<double> vec)
{
    sort(vec.begin(), vec.end());
    return vec.at( floor((vec.size()/2.0)) );
}

Range range(vector<double> vec)
{
    Range r;
    r.min = vec.at(0);
    r.max = vec.at(0);
    double temp = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        temp = vec.at(i);
        if(temp > r.max)
        {
            r.max = temp;
        }
        else if(temp < r.min)
        {
            r.min = temp;
        }
    }

    return r;
}

void print_stats(vector<double> vec)
{
    cout << "\n Sum: " << sum(vec);
    cout << "\n Mean: " << mean(vec);
    cout << "\n Median: " << median(vec);

    Range r = range(vec);
    cout << "\n Range: " << r.min << ", " << r.max << endl;


}

double stdDev(vector<double> vec)
{
    double mew = mean(vec);
    double sum = 0;
    double stddev = 0;

    for(int i = 0; i < vec.size(); i++)
    {
        sum += pow( (vec.at(i) - mew) , 2);
    }

    stddev = sqrt( sum / (double)(vec.size()) );

    return stddev;
}

double covar(vector<double> vecX, vector<double> vecY)
{
    int size = 0;
    if(vecX.size() < vecY.size())
        size = vecX.size();
    else
        size = vecY.size();

    double mewX = mean(vecX);
    double mewY = mean(vecY);
    double sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += (vecX.at(i) - mewX) * (vecY.at(i) - mewY);
    }

    return (sum / (double)(size - 1));
}

double cor(vector<double> vecX, vector<double> vecY)
{
    return ( covar(vecX, vecY) / (stdDev(vecX) * stdDev(vecY)) );
}