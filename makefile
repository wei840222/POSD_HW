hw7: struct.o list.o term.o utIterator.h iterator.h atom.h number.h variable.h
ifeq (${OS}, Windows_NT) 
	g++ -std=gnu++0x -c hw.cpp 
	g++ -o hw7 hw.o struct.o list.o term.o -lgtest 
else
	make utIterator.o
	g++ -o hw7 utIterator.o struct.o list.o term.o -lgtest -lpthread
	./hw7
	make clean
endif

#######UnitTest#######
allTestAndClean: utAtom utTerm utVariable utStruct utList utScanner utParser utIterator
	./utAtom && ./utTerm && ./utVariable && ./utStruct && ./utList && ./utScanner && ./utParser && ./utIterator
	make clean

utAtom: utAtom.o term.o
	g++ -o $@ $^ -lgtest -lpthread
utAtom.o: utAtom.h atom.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

utTerm: utTerm.o term.o
	g++ -o $@ $^ -lgtest -lpthread
utTerm.o: utTerm.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

utVariable: utVariable.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utVariable.o: utVariable.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

utStruct: utStruct.o term.o struct.o
	g++ -o $@ $^ -lgtest -lpthread
utStruct.o: utStruct.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

utList: utList.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utList.o: utList.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

utScanner: utScanner.o
	g++ -o $@ $^ -lgtest -lpthread
utScanner.o: utScanner.h scanner.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

utParser: utParser.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utParser.o: utParser.h parser.h scanner.h node.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

utIterator: utIterator.o term.o struct.o list.o
	g++ -o $@ $^ -lgtest -lpthread
utIterator.o: utIterator.h iterator.h atom.h number.h variable.h
	touch $*.cpp && echo "#include \"$*.h\"" > $*.cpp && cat utTemplate.h >> $*.cpp
	g++ -c $*.cpp

#####Object file#####
term.o: term.h
struct.o: struct.h
list.o: list.h 


clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o ut*[!.h] hw*[!.cpp]
endif