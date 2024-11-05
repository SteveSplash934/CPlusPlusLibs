#include "../src/filelib.hpp"

using namespace std;

int main(void)
{
    FileHandler filehandler;
    try
    {
        filehandler.open("hey.txt", ios::in);
        // vector<string> filelines = filehandler.readlines();
        for (string line : filehandler.readlines())
        {
            cout << line << endl;
        }
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    filehandler.close();
    return 0;
}