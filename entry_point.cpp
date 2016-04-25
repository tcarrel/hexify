#include<cstring>
#include<iostream>
#include<fstream>

#include"file_reader.h"


int main(int argc, char* argv[])
{
    if( argc != 3 && argc != 2 )
    {
        std::cerr
            << "Usage:\n" 
            << "\t" << argv[0]
            << " <input filename> <<optional> output filename>\n"
            << "\n"
            << "\tIf output filename is ommitted, will print to stdout "
            << "instead.\n" << std::endl;
        return 1;
    }

    File file(argv[1]);

    if( argc == 3 )
    {
        if( strcmp( argv[1], argv[2] ) )
        {

            std::ofstream out;

            out.open(argv[2]);

            if( !out.good() )
                return 1;


            file.output(out);

            out.close();

            return 0;
        }
        else
            std::cerr
                << "-------------------------------------------"
                << "---------------------------------------"
                << "\nInput and output files cannot be the same.  "
                << "Data will be output to stdout instead.\n"
                << "-------------------------------------------"
                << "---------------------------------------\n"
                << std::endl;
    }

    file.output(std::cout);
    std::cout << "\n" << std::endl;

    return 0;
}
