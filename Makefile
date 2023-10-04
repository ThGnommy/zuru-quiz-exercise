build:
	g++ -Wall -std=c++17 -fsanitize=address -o main *.cpp;

run:
	./main edit

clean:
	rm main
