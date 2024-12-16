#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string filename = "example.txt";
    string content = "This is a sample text written to the file";
    string readContent;

    ofstream outFile(filename);
    if (!outFile)
    {
        cout << "Error:Could not create file" << endl;
        return 0;
    }
    outFile << content;
    outFile.close();

    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Error:Could not open file for reading" << endl;
        return 0;
    }
    cout << "Reading contents from file:" << endl;
    while (getline(inFile, readContent))
    {
        cout << readContent << endl;
    }
    inFile.close();
    return 0;
}