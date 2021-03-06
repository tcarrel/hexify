

#include"file_reader.h"

File::File(char* filename)
{
    fstream file;
    file.open(filename, fstream::in | fstream::binary);

    is_good = file.good();
    if( !is_good )
        return;

    uint8_t byte;
    for( file >> byte; !(file >> byte).eof(); data_.push_back(byte) )
    { /*empty*/ }
}

void File::output(ostream& out)
{
    for( unsigned i = 1; i <= data_.size(); i++ )
    {
        if( (i % 20) == 1 )
        {
            out
                << "0x"
                << setw(8) << setfill('0') << setbase(16) << i - 1 << "  :  ";
        }
        out << setw(2) << setfill('0') << setbase(16) << (short)data_[i - 1];
        if( !(i % 20) )
            out << endl;
        else
        {
            if( !(i % 4) )
                out << "  ";
            else
                out << " ";
        }
    }
    out << "\033[1;31m" << "EOF" << "\033[0m\n";
}

bool File::good()
{
    return is_good;
}
