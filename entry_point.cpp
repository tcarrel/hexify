#include<iostream>
#include<fstream>

#include"file_reader.h"

using namespace std;

int main(int argc, char* argv[])
{
    if( argc != 3 )
    {
        return 1;
    }

    File file(argv[1]);

    ofstream out;
    out.open(argv[2]);
    if( !out.good() )
        return 1;

    file.output(out);

    out.close();

    return 0;
}
