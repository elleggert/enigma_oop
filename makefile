EXE=main.o enigma.o plugboard.o reflector.o helper.o rotor.o

enigma: $(EXE)
	g++ -Wall -g $(EXE) -o enigma

%.o: %.cpp helper.h
	g++ -Wall -g -c $<

main.o: enigma.h errors.h

enigma.o: enigma.h plugboard.h reflector.h rotor.h

clean:
	rm -f *.o enigma
