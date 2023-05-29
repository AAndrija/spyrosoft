
main:
	g++ -o main.bin main.cpp ABC.cpp  

clean:
	rm -f ./main.bin

run: main
	./main.bin

format:
	clang-format -i main.cpp ABC.cpp ABC.h