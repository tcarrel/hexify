#include<iostream>
#include<fstream>

#include"file_reader.h"


int main(int argc, char* argv[])
{
    if( argc != 3 && argc != 2 )
    {
        return 1;
    }

    File file(argv[1]);

    if( argc == 3 )
    {
    std::ofstream out;

    out.open(argv[2]);

    if( !out.good() )
        return 1;

    file.output(out);

    out.close();

    return 0;
    }

    file.output(std::cout);
    std::cout << "\n" << std::endl;

    return 0;
}
