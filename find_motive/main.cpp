#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    string file_path = argv[1];
    string motive = argv[2];
    int nb = 0;
    string word;
    fstream file;
    file.open(file_path);
    if (!file)
    {
        cerr << "The file " << file_path << " could not be opened.\n";
        return 1;
    }
    while (file >> word)
    {
        if (word.find(argv[2]) != std::string::npos)
            nb += 1;
    }
    cout << "The file " << file_path << " contains " << nb << " words containing the motive " << motive << "\n";
    file.close();
    return 0;
}
