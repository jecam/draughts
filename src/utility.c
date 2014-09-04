/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2014 Assignment #1
 * Full Name        : Josephine Pramudia
 * Student Number   : s3491523
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller and Virginia King
 **********************************************************************/
#include "utility.h"

/* Tidy up residual data in stdin when encountering an error. You will
 * need to use this when there is a possibility that there will be
 * leftover characters in the input buffer. */
void read_rest_of_line(void)
{
    int ch;
    /* remove all characters from the buffer */
    while(ch = getc(stdin), ch!='\n' && ch!=EOF)
        ;
    /* clear the error status of the input pointer */
    clearerr(stdin);
}


/* int check_if_correct(char * coordinates){ */


/* 	return 0 = all good */
/* 	return 1 = wrong input */
/* 	return -1 = RTM (\n ^d) */


/*     int bool=0; */

/* 	if(strcmp(coordinates,"\n")==0){ */
/* 		bool = -1; */
/* 	}else if(coordinates[3]!= '-'){ */
/*         bool=1; */
/*     }else if(coordinates[1]!= ','){ */
/*         bool=1; */
/*     }else if(coordinates[5]!= ','){ */
/*         bool=1; */
/*     } */
/*     return bool; */
/* } */

/* int find_coordinates(char *coordinates, unsigned *start_x, */
/*     unsigned *start_y, unsigned *end_x, unsigned *end_y) */
/* { */



/*     char *token; */
/*     char *junk; */
/*     /\* 1 is bad *\/ */
/* 	int bool=1; */
/* 	int coords[5]; */
/* 	int i; */

/* 	printf("%s\n",coordinates); */

/* 	coordinates[strlen(coordinates)-1]='\0'; */

/* 	printf("1. %s\n",coordinates); */

/* 	/\*first token*\/ */
/* 	token = strtok(coordinates,",-"); */
/* 	coords[0] = strtol(coordinates,&junk,10); */
/* /\*	if(junk !=0){ */
/* 		bool =-1; */
/* 	rest of tokens */
/* 	}else*\/ */
/* 	if(coords[0]==0){ */
/* 		bool = 1; */
/* 	}else{ */
/* 		printf("%d",coords[0]); */

/* 		for(i = 1; i <4;i++) */
/* 		{ */
/* 			token = strtok(NULL, ",-"); /\*NULL = tokenise the last string used in strtok();*\/ */
/* 			coords[i] = strtol(token,&junk,10); */
/* 			printf("%d",coords[i]); */

/* 			bool = 0; */

/* 			if(coords[i]<0 || coords[i]>7){ */
/* 				bool=1; */
/* 				break; */
/* 			} */
/* 		} */
/* 	} */

/* 	*start_x = (unsigned) coords[0]; */
/* 	*start_y = (unsigned)coords[1]; */
/* 	*end_x = (unsigned)coords[2]; */
/* 	*end_y = (unsigned)coords[3]; */

/*     /\*starting coordinate*\/ */


/* 	printf("bool %d\n",bool); */
/* 	printf("the wrong thing --%s---\n",junk); */
/* 	return bool; */

/* } */

/* int previous_check(unsigned *previous_x, unsigned *previous_y, unsigned *now_x, unsigned *now_y) */
/* { */

/* 	/\* 1 means they're not the same*\/ */
/* 	int bool=1; */

/* 	if(*previous_x == *now_x){ */
/* 		printf("\n in 1st if %d\n",bool); */

/* 		if(*previous_y == *now_y){ */
/* 			printf("\n in 2nd if %d\n",bool); */
/* 			bool=0; */
/* 			} */
/* 	} */

/* 	printf("prev_x %d, prev_y %d, now_x %d, now_y %d\n",*previous_x,*previous_y,*now_x,*now_y); */
/* 	printf("\n%d\n",bool); */
/* 	return bool; */
/* } */






/*int find_coordinates(char *coordinates, unsigned *start_x,
    unsigned *start_y, unsigned *end_x, unsigned *end_y)
{
    int k;
    char *token1,*token2, *token3;
    char *part1, *part2;

    char *endPtr1,*endPtr2,*endPtr3,*endPtr4;

    int bool=0;

	token1 = strtok(coordinates,"-");
	for(k=0;k<2;k++){
		if(k==0){
            part1 = token1;
            token1 = strtok(NULL,"-");
		}
		else
			part2 = token1;
	}

	token2 = strtok(part1,",");
	for(k=0;k<2;k++){
		if(k==0){
			*start_x = strtol(token2, &endPtr1, 10);
			if (strcmp(endPtr1, "") != 0)
				bool = 1;
			else if (*start_x < 0 || *start_x > 7)
				bool =1;
			token2 = strtok(NULL,",");
		}
		else{
			*start_y = (int) strtol(token2, &endPtr2, 10);
			if (strcmp(endPtr2, "") != 0)
  				bool = 1;
			else if (*start_y < 0 || *start_y > 7)
				bool =1;
			}
	}

	token3= strtok(part2,",");
    for(k=0;k<2;k++){
        if(k==0){
            *end_x = (int) strtol(token3, &endPtr3, 10);
            if (strcmp(endPtr3, "") != 0)
                bool = 1;
            else if (*start_y < 0 || *start_y > 7)
                bool =1;
            token3 = strtok(NULL,",");
        }
        else{
            *end_y = (int) strtol(token3, &endPtr4, 10);
            if (strcmp(endPtr4, "") != 0)
                bool = 1;
            else if (*start_y < 0 || *start_y > 7)
                bool =1;
        }
    }

	return bool;

}
*/
