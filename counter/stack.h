#ifndef __STACK__H
#define __STACK__H

/* The stack of packets that each counter has */
class Stack {
	public:
		/* Store array */
		int *stackArray;

		/* The position of the top of the stack in the array, 
		   the weight while adding packets */
		int topLevel, weight;

		int WINDOW_ID, WEIGHT_MIN, WEIGHT_MAX, Q, K;

		/* constructor */
		Stack() {
			
			topLevel = -1;
			weight = 0;
		}

		/* destructor */
		~Stack() {
			topLevel = 0;
		}

		/* Use this to add packets from processed request */
		void push(int x) {				

			topLevel++;
			weight = weight + x;
			stackArray[topLevel] = x;
		}

		/* Remove packets from stack */
		int pop() {
			{

				int x = stackArray[topLevel];
				weight = weight - x;
				topLevel--;

				return x;}
			}

		/* Find out what packet is in the top of the stack */
		int peek() {
			
			return stackArray[topLevel];
		}

		/* Checks size of the stack and returns 1 if it is empty */
		int isEmpty() {
			
			if(topLevel == -1)
				return 1;
			else
				return 0;
		}

		/* Return 1 if the stack is full -> aka the weight available is
		   not enough to store the current packet */
		int isFull(int g){
			if(topLevel == Q || weight + g >= K)
				return 1;
			else
				return 0;

			}
};

#endif // __STACK__H
