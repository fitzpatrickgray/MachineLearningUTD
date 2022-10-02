#include "PCH.h"
#include "ReadCSV.h"

using namespace std;

int main(void)
{
    ReadCSV titanic = ReadCSV("titanic_project.csv");
    titanic.printData();
    return 1;
}