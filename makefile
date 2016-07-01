# Makefile to build the Vector sample using g++ with C++11 features
# Auther : Wen-Kai, Chang
#
CC=g++
DEBUGFLAGS=-g -std=c++11
RELEASEFLAGS=-std=c++11
SRCDIR=Vector/
DEBUGDIR=./Debug/
RELEASEDIR=./Release/
DEBUGOBJS=$(DEBUGDIR)DblVector.o $(DEBUGDIR)VectorUtility.o $(DEBUGDIR)ListContainer.o $(DEBUGDIR)main.o
RELEASEOBJS=$(RELEASEDIR)DblVector.o $(RELEASEDIR)VectorUtility.o $(RELEASEDIR)ListContainer.o $(RELEASEDIR)main.o
OUTPUT=vector.out
MKDIR_P=mkdir -p

all : debug release

#####################
# Debug build
#####################

debug : debug_dir $(DEBUGDIR)$(OUTPUT)

debug_dir : $(DEBUGDIR)
	
$(DEBUGDIR) : 
	$(MKDIR_P) $(DEBUGDIR)

$(DEBUGDIR)$(OUTPUT) : $(DEBUGOBJS)
	$(CC) $(DEBUGFLAGS) $(DEBUGOBJS) -o $(DEBUGDIR)$(OUTPUT)

$(DEBUGDIR)ListContainer.o : $(SRCDIR)Container.h $(SRCDIR)ListContainer.h $(SRCDIR)Listcontainer.cpp
	$(CC) $(DEBUGFLAGS) -c $(SRCDIR)ListContainer.cpp -o $(DEBUGDIR)ListContainer.o

$(DEBUGDIR)DblVector.o : $(SRCDIR)DblVector.h $(SRCDIR)DblVector.cpp 
	$(CC) $(DEBUGFLAGS) -c $(SRCDIR)DblVector.cpp -o $(DEBUGDIR)DblVector.o

$(DEBUGDIR)VectorUtility.o : $(SRCDIR)DblVector.h $(SRCDIR)VectorUtility.cpp
	$(CC) $(DEBUGFLAGS) -c $(SRCDIR)VectorUtility.cpp -o $(DEBUGDIR)VectorUtility.o

$(DEBUGDIR)main.o : $(SRCDIR)Container.h $(SRCDIR)ListContainer.h $(SRCDIR)VecContainer.h $(SRCDIR)DblVector.h $(SRCDIR)main.cpp $(SRCDIR)TplVector.h
	$(CC) $(DEBUGFLAGS) -c $(SRCDIR)main.cpp -o $(DEBUGDIR)main.o

cleandebug :
	rm -rf $(DEBUGDIR)


#####################
# Release build
#####################

release : release_dir $(RELEASEDIR)$(OUTPUT)

release_dir : $(RELEASEDIR)

$(RELEASEDIR) : 
	$(MKDIR_P) $(RELEASEDIR)

$(RELEASEDIR)$(OUTPUT) : $(RELEASEOBJS)
	$(CC) $(RELEASEFLAGS) $(RELEASEOBJS) -o $(RELEASEDIR)$(OUTPUT)

$(RELEASEDIR)ListContainer.o : $(SRCDIR)Container.h $(SRCDIR)ListContainer.h $(SRCDIR)Listcontainer.cpp
	$(CC) $(RELEASEFLAGS) -c $(SRCDIR)ListContainer.cpp -o $(RELEASEDIR)ListContainer.o

$(RELEASEDIR)DblVector.o : $(SRCDIR)DblVector.h $(SRCDIR)DblVector.cpp 
	$(CC) $(RELEASEFLAGS) -c $(SRCDIR)DblVector.cpp -o $(RELEASEDIR)DblVector.o

$(RELEASEDIR)VectorUtility.o : $(SRCDIR)DblVector.h $(SRCDIR)VectorUtility.cpp
	$(CC) $(RELEASEFLAGS) -c $(SRCDIR)VectorUtility.cpp -o $(RELEASEDIR)VectorUtility.o

$(RELEASEDIR)main.o : $(SRCDIR)Container.h $(SRCDIR)ListContainer.h $(SRCDIR)VecContainer.h $(SRCDIR)DblVector.h $(SRCDIR)main.cpp $(SRCDIR)TplVector.h
	$(CC) $(RELEASEFLAGS) -c $(SRCDIR)main.cpp -o $(RELEASEDIR)main.o

cleanrelease :
	rm -rf $(RELEASEDIR)

clean : cleandebug cleanrelease
