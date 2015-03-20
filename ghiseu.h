	#include "stack.h"

	/* A person whose request was registered
	 has these characteristics */
	struct Person{
				int PERSONAL_ID;
				int PACKAGE_WEIGHT;
				struct Person *next;
				struct Person *prev;
				};


	class Window{
	public:
		/* The queue at the counter is represented as a linked list
		   because there are some links between the elements */
		struct Person *pFirst, *pLast; 

		class Stack s;

		/* Constructor for the Window class:
			When first opened the window of a counter starts with an 
			empty list of processed requests */
		Window(){

			pFirst = pLast = NULL;

		}	

		~Window(){

		}

		/* When opening a window -> initialize its attributes */
		void open_window(int w_id, int min, int max, int nmax, int gmax){
			
				s.WINDOW_ID = w_id;
				s.WEIGHT_MIN = min;
				s.WEIGHT_MAX = max;
				s.Q = nmax;
				s.K = gmax;
				s.stackArray = (int *) calloc (nmax, sizeof(int));

		}

		/* Add person to the queue */
		void add_person(int pers_id, int p_weight){
				
			struct Person *paux;

	        paux = new struct Person;
	        paux->PERSONAL_ID = pers_id;
			paux->PACKAGE_WEIGHT = p_weight;

	        paux->prev = pLast;
	        paux->next = NULL;

	        if (pLast != NULL) 
				pLast->next = paux;

	        pLast = paux;

	        if (pFirst == NULL) 
				pFirst = pLast;
	        }


	    /* Use that when processing a request */
		 void removeFirst(){ 
			struct Person *paux;

	        if (pFirst != NULL) {
	        	paux = pFirst->next;

	           	if ( paux == NULL) 
					pLast = NULL;

	            pFirst = paux;

	            if (pFirst != NULL) 
					pFirst->prev = NULL;
	            }
	    
			}

		/* Process some given weight g */
		void process(int g){

			Person *p;

			p = pFirst->next;
		
			if(s.isFull(g))
				while(!s.isEmpty())
					s.pop();

			s.push(pFirst->PACKAGE_WEIGHT);
			removeFirst();
			pFirst = p;
		}


		/* If the list is empty return 1. Else return 0. */
		int  eGoala(){
			if(pFirst == NULL && pLast == NULL)
				return 1;
			return 0;
		}

		void print_stack(){
			
			int k;
			int i;
			k = s.topLevel;
			if(k >= 0)
			printf("%d", s.stackArray[k]);

				for(i=k-1; i>=0; i--)
					printf(", %d", s.stackArray[i]);
				
				
		}

		void flush_stack(){

			if(!s.isEmpty())
				{
					printf("%d",s.peek());
					s.pop();
				}
			
			while(!s.isEmpty()){

				printf(", ");
				printf("%d",s.peek());
				s.pop();
			}

		}

		void print_queue(){

			struct Person *paux;
			paux = pFirst;

			if(paux != NULL)
			{
			printf("(%d, %d)", paux->PERSONAL_ID, paux->PACKAGE_WEIGHT);
			paux = paux->next;
			}
			while(paux != NULL){
				printf(", ");
				printf("(%d, %d)", paux->PERSONAL_ID, paux->PACKAGE_WEIGHT);
				paux = paux->next;
			}

		}

	};
						
