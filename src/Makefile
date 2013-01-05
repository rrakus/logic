CXX=g++

OBJS=main.o Bigpin.o Bigpinset.o TerminalIO.o Game.o Overview.o Smallpin.o Smallpinset.o
OUTPUT=logic

%.o: %.cpp
	$(CXX) -c -g $< -o $@

all: $(OBJS)
	$(CXX) $? -g -o $(OUTPUT)

clean:
	rm $(OBJS)
