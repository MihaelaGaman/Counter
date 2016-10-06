# Data-Structures

For this assignment I have used 2 headers ghiseu.h and stack.h. 
	These were then included into the third one: tema1.cpp.

	Each counter (ghișeu) has a stack of packets. I implemented the
	facilities offered by a stack into the stack.h file. So there I have:
		-> push / pop operations
		-> peek - take the value of the element at the top of the stack
		-> functions to check whether the stack is empty / full 
	
	Whitin the ghiseu.h file there is a structure that keeps information about
	a person sitting at queue in front of the window of some counter.
	This information consists of:
		-> PERSONAL_ID
		-> PACKAGE_WEIGHT

	Here I have also implemented a class for a counter with:
		-> a double linked list acting like a queue

	Another part of this file consists of functions called during parsing
	the input file (with the commands):
		-> open_window
		-> add_person
		-> process
		-> print functions
		-> flushing

	I have chosen the implementation of the queue using a double linked list
	for 2 reasons:
		1) the maximum number of persons standing at the queue was unknown
	so a dynamically alocated list seemed the right thing to do
		2) there are links between the elements of a list so you don't have
	to remove an element to find out its value.

	In tema1.cpp file I have the main function having as argument the name of
	the input file. I open the input file. Read the first string using fgets.
	Convert it into number.
	Then consider array ok full with 0 initially.
	When I do open counters I set the element at that position in the ok array
	to be 1.

	In this main file I do the parsing too using the helper functions I have
implemented into the ghiseu.h file.
