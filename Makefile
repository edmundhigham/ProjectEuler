# Makefile for Project Euler
# Edmund Higham, 2014

# C++ Compiler
CPP=g++

# C++ Optimisation Flags                                                                                                                                                                          
OPT_CPP = -O3

# C++ Standard                                                                                                                                                                                    
STD_CPP = -std=c++11

# C++ Flags
FLAGS_CPP = $(OPT_CPP) $(STD_CPP)

# RUST Compiler
RUSTC = rustc

question1: src/src_cpp/mult_3n5.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question2: src/src_cpp/fib_even.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question3: src/src_cpp/prime_factor.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question4: src/src_cpp/palindrome.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@
	
question5: src/src_cpp/even_divisible.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question6: src/src_cpp/sum_square_diff.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question7: src/src_cpp/nth_prime.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question8: src/src_cpp/largest_product.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question9: src/src_cpp/pythag_trip.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question10: src/src_cpp/sum_primes.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question11: src/src_cpp/grid_prod.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question12: src/src_cpp/divisible_triangular.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question13: src/src_cpp/10_most_signif.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question14: src/src_cpp/collatz_seq.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

question18: src/src_cpp/path_sum.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@
	
question24: src/src_cpp/lexiPermute.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@
	
question31: src/src_cpp/coin_sums.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@
	
question35: src/src_cpp/circular_primes.cpp
	mkdir -p bin/
	$(CPP) $(FLAGS_CPP) $^ $ -o bin/$@

clean:
	rm bin/*
