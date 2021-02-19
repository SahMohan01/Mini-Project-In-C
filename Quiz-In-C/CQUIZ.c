#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char first_name[10],last_name[10];
float score;
void help();
FILE *f1;
void show_record()
{
	system("clear");
	f1 = fopen("sorted_record.txt","r");
	printf("\n***************************************SCOREBOARD*********************************************\n\n");
	int i = 1;
	while((fscanf(f1,"%s",first_name)) != EOF)
	{
		fscanf(f1,"%s %f",last_name,&score);
		printf("\t\t\t\t %3d. %s %s has won $%f\n",i,first_name,last_name,score);
		i++;
	}
	printf("Press Enter to return to home.\n");
        fclose(f1);
}
void add_player(char plfname[], char pllname[],float plscore)
{
	FILE *fp;
	system("clear");
	fp = fopen("QuizRecord.txt","a");
	fprintf(fp,"%s %s %f",plfname,pllname,plscore);
	fclose(fp);
}
void sort_record()
{
	f1 = fopen("QuizRecord.txt","r");
    	int count = 0;
	while(fscanf(f1,"%s %s %f",first_name,last_name,&score) != EOF)
	{
		count++;
	}
	rewind(f1);
	struct record
	{
		char fname[10];
		char lname[10];
		float score;
	};
	struct record player[count],temp_record;
	for(int i = 0; i < count; i++)
	{
		fscanf(f1,"%s %s %f",player[i].fname,player[i].lname,&player[i].score);	
	}
	fclose(f1);
	for(int i =1; i<= count-1 ;i++)
	{
		temp_record.score= player[i].score;
                strcpy(temp_record.fname,player[i].fname);
      		strcpy(temp_record.lname,player[i].lname);
		int j;
		for( j = i-1; j>=0 && temp_record.score > player[j].score; j--)
		{
			strcpy(player[j+1].fname,player[j].fname);
			strcpy(player[j+1].lname,player[j].lname);
		        player[j+1].score = player[j].score;
		}
		strcpy(player[j+1].fname,temp_record.fname);
		strcpy(player[j+1].lname,temp_record.lname);
		player[j+1].score = temp_record.score;
	}
	FILE *f2;
	f2 = fopen("sorted_record.txt","w");
	for(int i =0; i < count; i++)
	{
		fprintf(f2,"%s %s %f\n",player[i].fname,player[i].lname,player[i].score);
	}
	fclose(f2); 	
}

int main()
{
     int countr,r=0,r1=0,count,i,n;
     float scor;
     char choice;
     mainhome:
     system("clear");
     printf("\t\t\t\t\tC PROGRAM QUIZ GAME\n");
     printf("\n\t\t\t\t________________________________________");

     printf("\n\t\t\t\t\t   WELCOME ");
     printf("\n\t\t\t\t\t      to ");
     printf("\n\t\t\t\t\t   THE GAME ");
     printf("\n\t\t\t\t________________________________________");
     printf("\n\t\t\t\t________________________________________");
     printf("\n\t\t\t\t   BECOME A MILLIONAIRE!!!!!!!!!!!    ") ;
     printf("\n\t\t\t\t________________________________________");
     printf("\n\t\t\t\t________________________________________");
     printf("\n\t\t\t\t > Press S to start the game");
     printf("\n\t\t\t\t > Press V to view the scoreboard ");
     printf("\n\t\t\t\t > press H for help            ");
     printf("\n\t\t\t\t > press Q to quit             ");
     printf("\n\t\t\t\t________________________________________\n\n");
     choice=toupper(getchar());
     if (choice=='V')
	{
	sort_record();
	show_record();
	getchar();
	getchar();
	goto mainhome;
	}
     else if (choice=='H')
	{
	help();
	getchar();
	getchar();
	goto mainhome;
	}
	else if (choice=='Q')
	exit(1);
    else if(choice=='S')
    {
     system("clear");

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tRegister your name(Format = first-name last-name):");
     scanf("%s %s",first_name,last_name);
    getchar();
    system("clear");
    printf("\n ------------------  Welcome %s %s to C Program Quiz Game --------------------------",first_name,last_name);
    printf("\n\n Here are some tips you might wanna know before playing:");
    printf("\n -------------------------------------------------------------------------");
    printf("\n >> There are 2 rounds in this Quiz Game,WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 3 questions to test your");
    printf("\n    general knowledge. You are eligible to play the game if you give atleast 2");
    printf("\n    right answers, otherwise you can't proceed further to the Challenge Round.");
    printf("\n >> Your game starts with CHALLANGE ROUND. In this round you will be asked a");
    printf("\n    total of 10 questions. Each right answer will be awarded $100,000!");
    printf("\n    By this way you can win upto ONE MILLION cash prize!!!!!..........");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option.");
    printf("\n >> You will be asked questions continuously, till right answers are given");
    printf("\n >> No negative marking for wrong answers!");
    printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
    printf("\n\n\n Press Y  to start the game!\n");
    printf("\n Press N to return to the main menu!");
    if (toupper(getchar())=='Y')
		{
		        getchar();
			goto home;
        }
	else
		{
        		getchar();
			goto mainhome;
       system("clear");
       }

     home:
     system("clear");
     count=0;
     for(i=1;i<=3;i++)
     {
    system("clear");
     r1= r1 % 9;


     switch(r1)
		{
		case 0:
		r1++;
		printf("\n\nWhich of the following is a Palindrome number?");
		printf("\n\nA.42042\t\tB.101010\n\nC.23232\t\tD.01234\n\n");
		if (toupper(getchar())=='C')
			{
			    printf("\n\nCorrect!!!");
			    count++;
			    getchar(); getchar();
			    break;
}
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C.23232");
		           getchar();getchar();
		       break;
		       }

        case 1: r1++;
		printf("\n\n\nThe country with the highest environmental performance index is...");
		printf("\n\nA.France\t\tB.Denmark\n\nC.Switzerland\t\tD.Finland\n\n");
		if (toupper(getchar())=='C')
			{printf("\n\nCorrect!!!");count++;
			getchar();getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.Switzerland");
		       getchar(); getchar();
		       break;}

        case 2:r1++;
		printf("\n\n\nWhich animal laughs like human being?");
		printf("\n\nA.Polar Bear\t\tB.Hyena\n\nC.Donkey\t\tD.Chimpanzee\n\n");
		if (toupper(getchar())=='B')
			{printf("\n\nCorrect!!!");count++;
			getchar();getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Hyena");
		       getchar(); getchar();
		       break;}

        case 3:r1++;
		printf("\n\n\nWho was awarded the youngest player award in Fifa World Cup 2006?");
		printf("\n\nA.Wayne Rooney\t\tB.Lucas Podolski\n\nC.Lionel Messi\t\tD.Christiano Ronaldo\n\n");
		if (toupper(getchar())=='B')
			{printf("\n\nCorrect!!!");count++;
			getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Lucas Podolski");
		       getchar();
		       break;}

        case 4:r1++;
        printf("\n\n\nWhich is the third highest mountain in the world?");
        printf("\n\nA.Mt. K2\t\tB.Mt. Kanchanjungha\n\nC.Mt. Makalu\t\tD.Mt. Kilimanjaro\n\n");
        if (toupper(getchar())=='B')
               {printf("\n\nCorrect!!!");count++;
               getchar();
                break;}
        else
		       {printf("\n\nWrong!!! The correct answer is B.Mt. Kanchanjungha");
		       getchar();
		       break;}

        case 5:r1++;
		printf("\n\n\nWhat is the group of frogs known as?");
		printf("\n\nA.A traffic\t\tB.A toddler\n\nC.A police\t\tD.An Army\n\n");
		if (toupper(getchar())=='D' )
			{printf("\n\nCorrect!!!");count++;
			getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.An Army");
		       getchar();
		       break;}
        case 6:	r1++;
		printf("\n\n\nOzone plate is being destroyed regularly because of____ ?");
		printf("\n\nA.L.P.G\t\tB.Nitrogen\n\nC.Methane\t\tD. C.F.C\n\n");
		 if (toupper(getchar())=='D')
			{printf("\n\nCorrect!!!");count++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D. C.F.C");getchar();
		       break;}

	case 7:r1++;
		printf("\n\n\nWho won the Women's Australian Open Tennis in 2007?");
		printf("\n\nA.Martina Hingis\t\tB.Maria Sarapova\n\nC.Kim Clijster\t\tD.Serena Williams\n\n");
		if (toupper(getchar())=='D')
			{printf("\n\nCorrect!!!");count++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.Serena Williams");getchar();
		       break;}

	case 8:r1++;
		printf("\n\n\nWhich film was awarded the Best Motion Picture at Oscar in 2010?");
		printf("\n\nA.The Secret in their Eyes\t\tB.Shutter Island\n\nC.The King's Speech\t\tD.The Reader\n\n");
		if (toupper(getchar())=='C')
			{printf("\n\nCorrect!!!");count++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.The King's Speech");getchar();
			break;}
		
	}
}

	if(count>=2)
	{goto test;}
	else
	{
		system("clear");
		printf("\n\nSORRY YOU ARE NOT ELIGIBLE TO PLAY THIS GAME, BETTER LUCK NEXT TIME");
		printf("\nWanna play FIRST ROUND again?(y/n)");
		if (toupper(getchar()) =='Y')
		{
			getchar();
			goto home;
		}
		else
		{	
			getchar();
			goto mainhome;
		}
	}
     test:
     system("clear");
     printf("\n\n\t*** CONGRATULATION %s %s!!! You are through to the next round. ***",first_name,last_name);
     printf("\n\n\n\n\t!Press ENTER to Start the Game!");
     getchar();
     goto game;
game:
     countr=0;
     for(i=1;i<=10;i++)
     {system("clear");
     r= r % 20;
     switch(r)
		{
		case 0:r++;
		printf("\n\nWhat is the National Game of England?");
		printf("\n\nA.Football\t\tB.Basketball\n\nC.Cricket\t\tD.Baseball\n\n");
		if (toupper(getchar())=='C')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.Cricket");getchar();
		       goto scor;
		       break;}

		case 1:r++;
		printf("\n\n\nStudy of Earthquake is called............,");
		printf("\n\nA.Seismology\t\tB.Cosmology\n\nC.Orology\t\tD.Etimology\n\n");
		if (toupper(getchar())=='A')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Seismology");getchar();
		      goto scor;
		       break;
		       }

        case 2:r++;
		printf("\n\n\nAmong the top 10 highest peaks in the world, how many lie in Nepal? ");
		printf("\n\nA.6\t\tB.7\n\nC.8\t\tD.9\n\n");
		if (toupper(getchar())=='C')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.8");getchar();
		       goto scor;
		       break;}

        case 3:r++;
		printf("\n\n\nThe Laws of Electromagnetic Induction were given by?");
		printf("\n\nA.Faraday\t\tB.Tesla\n\nC.Maxwell\t\tD.Coulomb\n\n");
		if (toupper(getchar())=='A')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {
                printf("\n\nWrong!!! The correct answer is A.Faraday");getchar();
		       goto scor;
		       break;
		       }

        case 4:r++;
		printf("\n\n\nIn what unit is electric power measured?\n\n");
		printf("\n\nA.Coulomb\t\tB.Watt\n\nC.Power\t\t\tD.Units\n\n");
		if (toupper(getchar())=='B')
			{printf("\n\nCorrect!!!");countr++;getchar(); break;}
		else
		       {
		           printf("\n\nWrong!!! The correct answer is B.Power");
		       getchar();
		       goto scor;
		       break;
		       }

		case 5:r++;
		printf("\n\n\nWhich element is found in Vitamin B12?");
		printf("\n\nA.Zinc\t\t\tB.Cobalt\n\nC.Calcium\t\tD.Iron\n\n");
		if (toupper(getchar())=='B' )
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Cobalt");goto scor;
		       getchar();
		       break;}

        case 6:r++;
		printf("\n\n\nWhat is the National Name of Japan?");
		printf("\n\nA.Polska\t\tB.Hellas\n\nC.Drukyul\t\tD.Nippon\n\n");
		if (toupper(getchar())=='D')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.Nippon");getchar();
		       goto scor;
		       break;}

        case 7:r++;
		printf("\n\n\nHow many times a piece of paper can be folded at the most?");
		printf("\n\nA.6\t\tB.7\n\nC.8\t\tD.Depends on the size of paper\n\n");
		if (toupper(getchar())=='B')
			{printf("\n\nCorrect!!!");countr++;getchar(); break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.7");getchar();
		       goto scor;
		       break;}

        case 8:r++;
		printf("\n\n\nWhat is the capital of Denmark?");
		printf("\n\nA.Copenhagen\t\tB.Helsinki\n\nC.Ajax\t\tD.Galatasaray\n\n");
		if (toupper(getchar())=='A')
			{printf("\n\nCorrect!!!");countr++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Copenhagen");getchar();
		       goto scor;
		       break;}

        case 9:r++;
		printf("\n\n\nWhich is the longest River in the world?");
		printf("\n\nA.Nile\t\tB.Koshi\n\nC.Ganga\t\tD.Amazon\n\n");
		if (toupper(getchar())=='A')
			{printf("\n\nCorrect!!!");countr++;getchar(); break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Nile");getchar();break;goto scor;}

        case 10:r++;
		printf("\n\n\nWhat is the color of the Black Box in aeroplanes?");
		printf("\n\nA.White\t\tB.Black\n\nC.Orange\t\tD.Red\n\n");
		if (toupper(getchar())=='C')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
              {printf("\n\nWrong!!! The correct answer is C.Orange");getchar();
              break;goto scor;}

        case 11:r++;
		printf("\n\n\nWhich city is known at 'The City of Seven Hills'?");
		printf("\n\nA.Rome\t\tB.Vactican City\n\nC.Madrid\t\tD.Berlin\n\n");
		if (toupper(getchar())=='A')
			  {printf("\n\nCorrect!!!");countr++;getchar();
			   break;}
		else
              {printf("\n\nWrong!!! The correct answer is A.Rome");getchar();
              break;goto scor;}

		case 12:r++;
		printf("\n\n\nName the country where there no mosquitoes are found?");
		printf("\n\nA.Japan\t\tB.Italy\n\nC.Argentina\t\tD.France\n\n");
		if (toupper(getchar())=='D')
			{printf("\n\nCorrect!!!");countr++;getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.France");getchar();
		       break;goto scor;}

        case 13:r++;
		printf("\n\n\nWho is the author of 'Pulpasa Cafe'?");
		printf("\n\nA.Narayan Wagle\t\tB.Lal Gopal Subedi\n\nC.B.P. Koirala\t\tD.Khagendra Sangraula\n\n");
		if (toupper(getchar())=='A')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Narayan Wagle");getchar();
		       break;goto scor;}

		case 14:r++;
		printf("\n\n\nWhich Blood Group is known as the Universal Recipient?");
		printf("\n\nA.A\t\tB.AB\n\nC.B\t\tD.O\n\n");
		if (toupper(getchar())=='B')
			{printf("\n\nCorrect!!!");countr++;getchar();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.AB");getchar();
		       goto scor;
		       break;}

		case 15:r++;
		printf("\n\n\nWhat is the unit of measurement of distance between Stars?");
		printf("\n\nA.Light Year\t\tB.Coulomb\n\nC.Nautical Mile\t\tD.Kilometer\n\n");
		if (toupper(getchar())=='A')
			{printf("\n\nCorrect!!!");countr++; getchar();
			break;
			}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Light Year");getchar();
		       goto scor;
		       break;}


		case 16:r++;
		printf("\n\n\nThe country famous for Samba Dance is........");
		printf("\n\nA.Brazil\t\tB.Venezuela\n\nC.Nigeria\t\tD.Bolivia\n\n");
		if (toupper(getchar())=='A')
			{printf("\n\nCorrect!!!");countr++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Brazil");getchar();goto scor;
		       break;}

		case 17:r++;
		printf("\n\n\nWind speed is measure by__________?");
		printf("\n\nA.Lysimeter\t\tB.Air vane\n\nC.Hydrometer\t\tD.Anemometer\n\n");
		if (toupper(getchar())=='D')
			{printf("\n\nCorrect!!!");countr++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.Anemometer");getchar();goto scor;
		       break;}

		case 18:r++;
		printf("\n\n\nWhich city in the world is popularly known as The City of Temple?");
		printf("\n\nA.Delhi\tB.Bhaktapur\n\nC.Kathmandu\tD.Agra\n\n");
		if (toupper(getchar())=='C')
			{printf("\n\nCorrect!!!");countr++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.Kathmandu");getchar();goto scor;
		       break;}

		case 19:r++;
		printf("\n\n\nWhich hardware was used in the First Generation Computer?");
		printf("\n\nA.Transistor\t\tB.Valves\n\nC.I.C\t\tD.S.S.I\n\n");
		if (toupper(getchar())=='B')
			{printf("\n\nCorrect!!!");countr++; getchar();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Valves");getchar();goto scor;
		       break;}

		}
}
	scor:
    system("clear");
	scor=countr*100000;
	if(scor>0 && scor<1000000)
	{
	   printf("\n\n\t\t**************** CONGRATULATION *****************");
	     printf("\n\t You won $%f",scor);goto go;}

	 else if(scor==1000000)
	{
	    printf("\n\n\n \t\t**************** CONGRATULATION ****************");
	    printf("\n\t\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
	    printf("\n\t\t You won $%f",scor);
	    printf("\n Thank You!!");
	    goto go;
	}
	 else
{
	 printf("\n\n\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
	    printf("\n\t\t Thanks for your participation");
             printf("\n\t\t TRY AGAIN");
		scor = 0.000000;
	    goto go;}

	go:
	puts("\n\nDo you want to save this score?(y/n)");
	if (toupper(getchar())== 'Y')
	{
		getchar();
		add_player(first_name,last_name,scor);
	}
	else
	{
 		getchar();
	}
        puts("\n\nPress Y if you want to play next game");
	puts("Press M if you want to go main menu");
	if (toupper(getchar())=='Y')
	{
		getchar();
		goto home;
	}
	else
		{
		getchar();
		goto mainhome;}
}
}


void help()
	{system("clear");
    printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ......................... C program Quiz Game...........");
    printf("\n >> There are two rounds in the game, WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 3 questions to test your general");
    printf("\n    knowledge. You will be eligible to play the game if you can give atleast 2");
    printf("\n    right answers otherwise you can't play the Game...........");
    printf("\n >> Your game starts with the CHALLANGE ROUND. In this round you will be asked");
    printf("\n    total 10 questions each right answer will be awarded $100,000.");
    printf("\n    By this way you can win upto ONE MILLION cash prize in USD...............");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option");
    printf("\n >> You will be asked questions continuously if you keep giving the right answers.");
    printf("\n >> No negative marking for wrong answers");

	printf("\n\n\t*********************BEST OF LUCK*********************************");
	printf("\n\n\t*****C PROGRAM QUIZ GAME is developed by Mohan Kumar Sah********");
}



