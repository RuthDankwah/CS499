#create the dependency lines
HEAADERS = autocomplete.h term.h SortingList.h
OBJECTS = autocomplete.o term.o SortingList.o PA3.o

#creae the default target
EXEC = CS216PA3
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

#create a target called clean to clean up the mess
clean:
	rm -i *.o $(EXEC)
