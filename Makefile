#
#   Thomas Russel Carrel
#
#   Makefile
#
#   Set the DEBUG variable on line 12 to something other than 0 (zero) to
#  to enable compilation of additional functions that may be useful during
#  development.
#   
#   All of these compile lines are set up to duplicate all output (errors) from
#  g++ and copy it into a file.
#

CXX = g++
DEBUG = 0
CXXFLAGS = -g -std=c++11 -Wall -W -pedantic -Werror #-D DEBUG
MAIN = hexify
GCCERREXT = gccerr
ERROR_COPY_DIR = Errors
COPYOUTPUT = 2>&1 | tee ./Errors/$<.$(GCCERREXT)

$(MAIN): .entry_point.o .file_reader.o $(ERROR_COPY_DIR)
	$(CXX) $(CXXFLAGS) .*.o -o $(MAIN) 2>&1 | tee ./Errors/$(MAIN).$(GCCERREXT)

.entry_point.o: entry_point.cpp file_reader.h $(ERROR_COPY_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(COPYOUTPUT)

.file_reader.o: file_reader.cpp file_reader.h $(ERROR_COPY_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(COPYOUTPUT)

$(ERROR_COPY_DIR):
	mkdir $(ERROR_COPY_DIR)

clean:
	rm -f .*.o $(MAIN) ./Errors/*
	rm -rf $(ERROR_COPY_DIR)
