#include <iostream>
#include <fstream>
#include <cfloat>

void max_of_file(double* array,int size, double &max)
{
    max = DBL_MIN;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
}

int main()
{
    int  size;
    double max = 0;
    std::ifstream inputfile ("input.txt");
    inputfile >> size;
    double* array = new double[size];

    for(int i = 0; i < size; i++)
    {
        if(inputfile.peek() == EOF)
        {
            std::cout << "ERROR: not enough elements in file";
            return 1;
        }
        inputfile >> array[i];
    }
    max_of_file(array, size, max);
    std::cout << max;
    inputfile.close();
    return 0;
}