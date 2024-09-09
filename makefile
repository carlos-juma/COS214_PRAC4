# Build the main executable
main: *.o
	g++ -std=c++11 -o main *.o

# Compile all .cpp files into .o files
*.o: *.h *.cpp
	g++ -g -std=c++11 -c *.cpp

# Run the main executable
run:
	./main

# Clean up object files and executable
clean:
	rm *.o main

# Check for memory leaks using Valgrind
leak:
	valgrind --leak-check=full ./main

# Debug using GDB
debug:
	gdb ./main
