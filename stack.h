#ifndef __STACK__H
#define __STACK__H

//#include "ghiseu.h"



class Stack {
	public:
		// vectorul de stocare
		int *stackArray;

		// pozitia in vector a varfului stivei, greutatea pe masura ce se adauga pachete
		int topLevel, weight;

		int WINDOW_ID, WEIGHT_MIN, WEIGHT_MAX, Q, K;


		// constructor
		Stack() {
			
			topLevel = -1;
			weight = 0;
			
		
		}

		// destructor
		~Stack() {
			topLevel = 0;
		}

		// operator de adaugare
		void push(int x) {				

			topLevel++;
			weight = weight + x;
			stackArray[topLevel] = x;
			
				
		}

		// operatorul de stergere
		int pop() {
			{

				int x = stackArray[topLevel];
				weight = weight - x;
				topLevel--;

				return x;}

			}

		// operatorul de consultare
		int peek() {
			
			return stackArray[topLevel];
			

		}

		// operatorul de verificare dimensiune
		int isEmpty() {
			
			if(topLevel == -1)
				return 1;
			else
				return 0;
		}

		int isFull(int g){
			if(topLevel == Q || weight + g >= K)
				return 1;
			else
				return 0;

			}

		
			

		
};

#endif // __STACK__H
