
#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

class File
{
    public:
        File(char*);

        bool good(void);
        void output(ostream&);
    private:
        vector<uint8_t> data_;
        bool is_good;
};
#endif
