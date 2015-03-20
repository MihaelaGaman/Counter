	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<ctype.h>

	#include "ghiseu.h"
	#include "stack.h"

	int main(int argc, char * argv[]){

		int N, ok[505], i, j, gasit;
		
		FILE *pf;
		char line[80], *p;

		/* This is information given after a command of type OPEN_WINDOW */
		int w_min, w_max, q, k, win_id;

		/* Parameters of ADD_PERSON command */
		int pers_id, p_weight;

		/* Info used when processing more persons requests */
		int id, g, nr_pers;
		pf = fopen(argv[1], "r");

		fgets(line,'\n', pf);
		N = atoi(line);
		
		class Window w[N];

		for(i=0; i<N; i++)
			/* ok[i] == 1 => counter no i is open */
			ok[i] = 0;

		while(fgets(line, 80, pf)){
			/* Read the first word on each line in the input file and
			   do the proper action for that command */
			p = strtok(line, " \n");

			if(strcmp(p, "OPEN_WINDOW") == 0){

				p = strtok(NULL, " ");
				win_id = atoi(p);

				p = strtok(NULL, " ");
				w_min = atoi(p);

				p = strtok(NULL, " ");
				w_max = atoi(p);

				p = strtok(NULL, " ");
				q = atoi(p);

				p = strtok(NULL, "\n");
				k = atoi(p);

				w[win_id].open_window(win_id, w_min, w_max, q, k);
				ok[win_id] = 1;

				}

			else

				if(strcmp(p, "ADD_PERSON") == 0){

					p = strtok(NULL, " ");
					pers_id = atoi(p);

					p = strtok(NULL, " ");
					p_weight = atoi(p);

					p = strtok(NULL, "\n");
					win_id = atoi(p);

					w[win_id].add_person(pers_id, p_weight);

					}

				else
					if(strcmp(p, "PROCESS") == 0){

						p = strtok(NULL, " ");
						win_id = atoi(p);

						p = strtok(NULL, "\n");
						nr_pers = atoi(p);

						for(i=0; i<nr_pers; i++){
							
							id = w[win_id].pFirst->PERSONAL_ID;
							g = w[win_id].pFirst->PACKAGE_WEIGHT;

							if(g >= w[win_id].s.WEIGHT_MIN && g <= w[win_id].s.WEIGHT_MAX)
								w[win_id].process(g);

							else{
								/* if the weight of the current packet does not meet
								   the requirements of the current counter stack, 
								   look for the first open window after this one */
								gasit = 0;
								j = win_id + 1;

								while(gasit == 0 && j < N){
									if(ok[j] == 1){
										w[j].add_person(id, g);
										w[win_id].removeFirst();
										gasit = 1;

									}

									j++;
								}
								
								/* if there is no open window after the current 
								   counter look before it */
								if(gasit == 0){
									j = 0;
									while(gasit == 0 && j < win_id ){

										if(ok[j] == 1){
											w[j].add_person(id, g);
											w[win_id].removeFirst();
											gasit = 1;
										}

									j++;
									}
								}
							}

						}
					}

					else
						if(strcmp(p, "PROCESS_ALL") == 0){

							//se efectueaza aceleasi operatii ca si in cazul anterior, numai ca de data aceasta se repeta atata timp cat mai exista elemente in stiva
							p = strtok(NULL, "\n");
							win_id = atoi(p);

							while(!w[win_id].eGoala()){

								id = w[win_id].pFirst->PERSONAL_ID;
								g = w[win_id].pFirst->PACKAGE_WEIGHT;

								if(g >= w[win_id].s.WEIGHT_MIN && g <= w[win_id].s.WEIGHT_MAX)
									w[win_id].process(g);

								else{
									gasit = 0;
									j = win_id + 1;

									while(gasit == 0 && j < N){
										if(ok[j] == 1){
											w[j].add_person(id, g);
											w[win_id].removeFirst();
											gasit = 1;

										}

										j++;
									}

									if(gasit == 0){
										j = 0;
										while(gasit == 0 && j < win_id ){

											if(ok[j] == 1){
												w[j].add_person(id, g);
												w[win_id].removeFirst();
												gasit = 1;
											}

											j++;
										}
									}

								}
							}							

						}

						else
							if(strcmp(p, "PRINT_STACKS") == 0){

								printf("STACKS:\n");
								for(i = 0; i < N; i++)
									if(ok[i] == 1){

										printf("%d: ",i);
										w[i].print_stack();
										printf("\n");

									}

							}

							else
								if(strcmp(p, "FLUSH_STACKS") == 0){

									printf("FLUSHING:\n");
									for(i = 0; i < N; i++)
										if(ok[i] == 1){

											printf("%d: ",i);
											w[i].flush_stack();
											printf("\n");

										}

								}	

								else
									if(strcmp(p, "PRINT_QUEUES") == 0){
				
										printf("QUEUES:\n");
											for(i = 0; i < N; i++)
												if(ok[i] == 1){

													printf("%d: ",i);
													w[i].print_queue();
													printf("\n");

												}

										}

		}	

		fclose(pf);
		return 0;

	}


		

