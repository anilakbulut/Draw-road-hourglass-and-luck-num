/*ANIL AKBULUT HW02 Number:151044029*/
/*These are used libraries*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*Random number range and trial are defined for lucky number game*/
#define LOWER_BOUND 1
#define UPPER_BOUND 1024
#define TRIAL 10
/*These are used functions*/
void draw_hourglass(int height);
int bound_power_calc(int num);
int make_a_guess (int trial, int min, int max);
void show_scores(int score_human, int score_program);
void draw_mountain_road(int lenght,int max_radius);
void menu();

void main(int argc, char const *argv[])
{
	srand(time(NULL));/*used to produce different numbers of time*/
	menu();
}
/*This function is menu function.It is calls other functions and plays game*/
void menu(){
	int choice=1; /*choice is the number of values the user enter*/
	int height; /*height is input for hourglass function*/
	int lenght,max_radius; /*lenght and max_radius are input for mountain road function*/
	int score_human=0,score_program=0;/*score_human and score_program are count for show_scores function*/
	while(choice!=4){ /*If choice is not equal 4,game is continue*/
		printf("***** MENU *****\n");
		printf("1. Play Lucky Number\n");
		printf("2. Draw Hourglass\n");
		printf("3. Draw Mountain Road\n");
		printf("4. Exit\n");
		printf("Choice:");
		scanf("%d",&choice); /*User enters the input*/
		printf("\n");
		switch(choice){
			/*If user enters 1,lucky number plays*/
			case 1: if(make_a_guess(TRIAL,LOWER_BOUND,UPPER_BOUND)==1) score_human++;
					else score_program++;/*If user wins human score increase,else program score increase*/
					show_scores(score_human,score_program);
					printf("\n");
					break;
			/*If user enters 2,draws hourglass*/
			case 2:	printf("Please enter the height : ");
					scanf("%d",&height);/*User enters the input*/
					while(height%2!=1){/*If height is not odd number,user again enters input*/
						printf("Please enter the odd number for height : ");
						scanf("%d",&height);
					}
					printf("\n");
					draw_hourglass(height);
					printf("\n");
					break;
			/*If user enters 3,draws mountain road*/
			case 3: printf("Please enter the lenght value : ");
					scanf("%d",&lenght);/*User enters the lenght values*/
					while(lenght<0){	/*If lenght smaller than 0,user again enters input*/
						printf("Please enter the lenght value(at least 0): ");
						scanf("%d",&lenght);
					}
					printf("Please enter the max_radius value : ");
					scanf("%d",&max_radius);/*User enters the max_radius values*/
					while(max_radius<0){	/*If max_radius smaller than 0,user again enters input*/
						printf("Please enter the max_radius(at least 0): ");
						scanf("%d",&max_radius);
					}
					printf("\n");
					draw_mountain_road(lenght,max_radius);
					printf("\n");
					break;
			/*The menu ends ,if the user enter 4*/
			case 4: break;
			/*If the user enters others number,print erros message*/
			default: printf("This is an invalid choice .Try again!\n");
					 break;
		}
	}
}
/*This function prints human and computers scores*/
void show_scores(int score_human, int score_program){
	printf("Your score : %d ",score_human );
	printf("Program score : %d\n",score_program);
}
/*This function calculates power of number */
int bound_power_calc(int num){
	int i;
	int result=1;
	for(i=0;i<num;i++){
		result = result*2;	
	} 
	return result;
}
/*This function is lucky number game*/
int make_a_guess (int trial, int min, int max){
	int LN=LOWER_BOUND+rand()%(UPPER_BOUND);/*LN is a lucky number.LN is a random number in the given range*/
	int distance,GN;/*GN is input for user's guess*/
	int sub=1;
	int status;/*status is a return value and use for show_scores function*/
	int count=1;
	while(trial>0 && sub!=0){/*If the trial and substaction are bigger than 0,while-loop is continue*/
		printf("(Trial : %d) Make a guess between %d-%d: ",count,min,max);
		scanf("%d",&GN);/*User enters guess number*/
		while(GN<min || GN>max){ /*If GN smaller than min or bigger than max,user enters again*/
			printf("Please enter a value in the range of min and max: ");
			scanf("%d",&GN);
		}
		if(LN>=GN) sub = LN - GN;/*If lucky number bigger than GN, sub is this value*/
		else sub = GN - LN;	/*else sub is this value*/
		if(GN>LN) max=GN;/*If GN is bigger than Ln, max values is GN*/
		else min=GN;/*If LN is bigger than GN,min values is GN*/
		/*The following if conditions are used to determine the distance*/
		if(sub>=bound_power_calc(9) && sub<bound_power_calc(10)){
			distance=10;
		}
		if(sub>=bound_power_calc(8) && sub<bound_power_calc(9)){
			distance=9;
		} 
		if(sub>=bound_power_calc(7) && sub<bound_power_calc(8)){
			distance=8;
		} 
		if(sub>=bound_power_calc(6) && sub<bound_power_calc(7)){
			distance=7;
		} 
		if(sub>=bound_power_calc(5) && sub<bound_power_calc(6)){
			distance=6;
		} 
		if(sub>=bound_power_calc(4) && sub<bound_power_calc(5)){
			distance=5;
		} 
		if(sub>=bound_power_calc(3) && sub<bound_power_calc(4)){
			distance=4;
		} 
		if(sub>=bound_power_calc(2) && sub<bound_power_calc(3)){
			distance=3;
		} 
		if(sub>=bound_power_calc(1) && sub<bound_power_calc(2)){
			distance=2;
		} 
		if(sub==bound_power_calc(0)){
			distance=1;
		}
		if(sub==0){/*If user true guesses,print on screen "you win"*/
			distance=0;
			printf("Distance is %d: ",distance );
			printf("You win!\n");
			status=1;
		}
		else{ 
			if(trial==1) printf("Distance is %d: ",distance );
			else printf("Distance is %d: \n",distance );
		}
		trial--; /*trial and count values are updates*/
		count++;
	}
		if(distance!=0){/*If user false guesses,print on screen "you lose"*/
			printf("You lose!\n");
			status=0;
		}
	return status;
}
/*This function draws hourglass*/
void draw_hourglass(int height){
	int star=height;
	int i,j,temp_space=0,space=0;
	for (i=1; i <= height; i++) /*This loop runs up to the number of height*/
	{
		for(j= 1;j <= space; j++){/*The space is drawn first*/
			printf(" ");
		}
		for (j = 0; j < star; j++)/*Then star is drawn*/
		{
			printf("*");
		}
		printf("\n");/*Then move to bottom line*/
		if(star==1){ /*If star is 1,space and star numbers are increased*/
			temp_space=1;
			star=star+2;
		}
		else{ /*If star is not 1...*/
			if(temp_space==1) { /*If temp_space is 1,the top side of the hourglass is drawn*/
				star=star+2;
			}
			else{
				star=star-2;
			}
		}
		if(temp_space==0){ /*If the bottom of the hourglass is drawn..*/
			space++; /*spaces is increased*/
		}
		else{
			space--;
		}
	}
}
/*This function draws mountain road*/
void draw_mountain_road(int lenght,int max_radius){
	int i,j,k,m;/*used for loops*/
	int space=max_radius; /*space equals max_radius values*/
	int random;
	for (i = 1; i <=lenght ; i++)
	{
		random=rand()%(max_radius+1);/*random is a radius for every shapes*/
		if(i%2==1){ /*If i is a odd numbers,the left half of the circle is drawn*/
			for(k=1;k<=random;k++){ /*First,slashes are drawn*/
				for(m=1;m<=space;m++){
					printf(" ");
				}
				printf("/\n");
				space--;
			}
			for(k=1;k<=space;k++){/*Then,spaces are drawn*/
				printf(" ");
			}
				printf("|\n");
				space++;
			for(k=1;k<=random;k++){/*Then,backslash are drawn*/
				for(m=1;m<=space;m++){
					printf(" ");
				}
				printf("\\\n");
				space++;
			}
		}
		if(i%2==0){/*If i is a even number,the right half of the circle is drawn*/
			for(k=1;k<=random;k++){/*First,backslashes are drawn*/
				for(m=1;m<=space;m++){
					printf(" ");
				}
				printf("\\\n");
				space++;
			}
			for(k=1;k<=space;k++){/*Then,spaces are drawn*/
				printf(" ");
			}
			printf("|\n");
			space--;
			for(k=1;k<=random;k++){/*Then,slashes are drawn*/
				for(m=1;m<=space;m++){
					printf(" ");
				}
				printf("/\n");
				space--;
			}
		}
	}
}