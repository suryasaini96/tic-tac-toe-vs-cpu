/*TIC TAC TOE game development

Name: Tic Tac Toe V/S CPU
Copyright: Surya Saini
Author: Surya Saini
Date: 02-11-15 02.48
Description: Tic Tac Toe game supporting player vs player and player vs cpu modes.

WELCOME TO TIC TAC TOE GAME

1|2|3
-----
4|5|6
-----
7|8|9

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void display();
void win();
void prev_pos();
void CPU_intel();

int arr[3][3]={1,2,3,4,5,6,7,8,9};
int count1=0,count2=0,val,flag;

main()
{
    int i,j,r,c,count=0,mode;
    char ch;
    do
    {
        int assign=1;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                arr[i][j]=assign;
                assign++;
            }
        }
        system("cls");
        system("COLOR FC");
        printf("\t\t   Welcome to Tic Tac Toe Game\n\n");
        display();
        printf("\n\n");
        printf("1. Player V/S Player Mode ");
        printf("\n2. Player V/S CPU Mode ");
        printf("\n\nEnter choice: ");
        fflush(stdin);
        scanf("%d",&mode);
        Beep(500,500);
        switch(mode)
        {
            case 1:	system("cls");
                    printf("\t\t\t  Tic Tac Toe \n\n\t\t    Player V/S Player Mode\n");
                    display();
                    for(i=1;i<10;i++) // Player vs Player Mode
                    {
                        count=0;
                        if(i%2==1) // Turn for player 1 comes at i=1,3,5 and so on till 9
                        {
                            do
                            {
                                flag=0;
                                printf("\n\nPLAYER 1: ");
                                scanf("%d",&val);
                                Beep(500,500);
                                Sleep(100);
                                int c;
                                if(val>=1&&val<=9)
                                {
                                    prev_pos();
									if (flag==1)
                                    {
                                        printf("\nSorry the position is previously occupied.Enter again.");
                                        printf("\a");
                                    }
                                    else if (flag==0)
                                    {
                                        for(r=0;r<3;r++)
                                        {
                                            for(c=0;c<3;c++)
                                            {
                                                count=count+1;
                                                if(count==val)
                                                {
                                                    arr[r][c]=100; // number for player 1 gets stored as 100 which will be later replaced by X
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    printf("\nSorry the number is not between 1 and 9. Enter again.");
                                    printf("\a");
                                    flag=1;
                                }
                            }while(flag==1);
                        }
                        else if(i%2==0) // Turn for player 2 comes at i=2,4,6 and so on till 8
                        {
                            do
                            {
                                flag=0;
                                printf("\n\nPLAYER 2: ");
                                scanf("%d",&val);
                                Beep(500,500);
                                Sleep(100);
                                int c;
                                if(val>=1&&val<=9)
                                {
                                	prev_pos();
                                    if(flag==1)
                                    {
                                        printf("\nSorry, the position is previously occupied.Enter again.");
                                        printf("\a");
                                    }
                                    else if(flag==0)
                                    {
                                        for(r=0;r<3;r++)
                                        {
                                            for(c=0;c<3;c++)
                                            {
                                                count=count+1;
                                                if(count==val)
                                                {
                                                    arr[r][c]=10; // number for player 2 gets stored as 10 which will be later replaced by O
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    printf("\nSorry, the number is not between 1 and 9. Enter again.");
                                    printf("\a");
                                    flag=1;
                                }
                            }while(flag==1);
                        }
                        system("cls");
                        printf("\t\t\t  Tic Tac Toe \n\n\t\t    Player V/S Player Mode\n");
                        display();
                        win();
                        if(count1==3)
                        {
                            printf("\n\n\t\t\t Player 1 WINS!\n");
                            printf("\a");
                            break;
                        }
                        else if(count2==3)
                        {
                            printf("\n\n\t\t\t Player 2 WINS!\n");
                            printf("\a");
                            break;
                        }
                    }
                    if((count1!=3)&&(count2!=3))
                    {
                        printf("\n\n\t\t\t  Its a draw!\n\n");
                        printf("\a");
                    }
                    break;
            case 2: system("cls");
                    printf("\t\t\t  Tic Tac Toe \n\n\t\t      Player V/S CPU Mode\n");
                    display();
                    srand(time(NULL)); // Initialising the psedo-random number generator to be used later
                    int corner=0;
                    for(i=1;i<10;i++) // Player vs CPU Mode
                    {
						count=0;
                        if(i%2==1) // Turn for player 1 comes at i=1,3,5 and so on till 9
                        {
                            do
                            {
                                flag=0;
                                printf("\n\nPLAYER : ");
                                scanf("%d",&val);
                                Beep(500,500);
                                if(val>=1&&val<=9)
                                {
                                	prev_pos();
                                    if (flag==1)
                                    {
                                        printf("\nSorry the position is previously occupied.Enter again.");
                                        printf("\a");
										Sleep(1040);
                                    }
                                    else if (flag==0)
                                    {
                                        for(r=0;r<3;r++)
                                        {
                                            for(c=0;c<3;c++)
                                            {
                                                count=count+1;
                                                if(count==val)
                                                {
                                                    arr[r][c]=100; // number for player 1 gets stored as 100 which will be later replaced by X
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    printf("\nSorry the number is not between 1 and 9. Enter again.");
                                    printf("\a");
					 				Sleep(1040);
                                    flag=1;
                                }
                                if((val==1||val==3||val==7||val==9)&&i==1)
                                {
                                	corner=1;
								}
                                
                            }while(flag==1);
                            system("cls");
                            printf("\t\t\t  Tic Tac Toe \n\n\t\t      Player V/S CPU Mode\n");
                            display();
                            printf("\n\nPLAYER : %d",val);
                        }
                        else if(i%2==0) // Turn for CPU comes at i=2,4,6 and so on till 8
                        {
                            do
                            {
                                flag=0;
                                val=1+rand()%9;
								CPU_intel(); /* checks if Player or the CPU is about to win */
								prev_pos();
								if(corner==1) // CPU's turn is in the middle when in first turn Player puts at corner so as to make the game HARDER for player ! :)
								{
									val=5;
									corner=0;
								}
            
								 /*Assigning and printing value here*/     
								if(flag==0)
                                {
                                for(r=0;r<3;r++)
                                {
                                    for(c=0;c<3;c++)
                                    {
                                        count=count+1;
                                        if(count==val)
                                        {
                                            arr[r][c]=10; // number for CPU gets stored as 10 which will be later replaced by O
                                        }
                                    }
                                }
                                printf("\n\nCPU : %d",val);
                                Beep(500,600);
								Sleep(500);
                                }
                     			/*Assigning and priting value 'END'here*/   
                            
							}while(flag==1);
						}

                        if(i%2==0) // Clear screen and display after each CPU's turn
                        {
                            system("cls");
                            printf("\t\t\t  Tic Tac Toe \n\n\t\t      Player V/S CPU Mode\n");
                            display();
                        }

                        win();
                        if(count1==3)
                        {
                            system("cls");
                            printf("\t\t\t  Tic Tac Toe \n\n\t\t      Player V/S CPU Mode\n");
                            display();
                            printf("\n\n\t\t 	    YOU WIN!\n");
                            printf("\a");
                            break;
                        }
                        else if(count2==3)
                        {
                            printf("\n\n\t\t\t   CPU WINS!\n");
                            printf("\a");
                            break;
                        }
                     }
                    if((count1!=3)&&(count2!=3))
                    {
                        system("cls");
                        printf("\t\t\t  Tic Tac Toe \n\n\t\t      Player V/S CPU Mode\n");
                        display();
                        printf("\n\n\t\t\t  Its a draw!\n");
                        printf("\a");
                    }
                    break;
            default: printf("\nWrong mode selection.Enter again.");
                     printf("\a");
					 Sleep(1040);
        }

        if(mode==1||mode==2)
        {
            printf("\nWant to play again? (y/n):");
            fflush(stdin);
            scanf("%c",&ch);
        }
    }while(ch=='y'||ch=='Y'||(mode!=1&&mode!=2));

}

void display()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("\n\t\t\t");
        for(j=0;j<3;j++)
        {
            if(arr[i][j]==100)
            {
                printf(" %c  ",'X');
            }
            else if(arr[i][j]==10)
            {
                printf(" %c  ",'O');
            }
            else
            {
                printf(" %d  ",arr[i][j]);
            }
            if(j<2)
            {
                printf("| ");
            }
        }

        if(i<2)
        printf("\n\t\t\t---------------");
    }
}

void win()
{
    int x,r,c;
    for(r=0;r<3;r++) // loop for checking row wise line
    {
            count1=0;
            count2=0;
            for(c=0;c<3;c++)
            {
                x=arr[r][c];
                if(x==100)
                {
                count1++;
                }
                else if(x==10)
                {
                count2++;
                }

            }
            if(count1==3||count2==3)
            break;
    }

    if((count1!=3)&&(count2!=3))
    {
        for(c=0;c<3;c++) // column wise line check
        {
            count1=0;
            count2=0;
            for(r=0;r<3;r++)
            {
                x=arr[r][c];
                if(x==100)
                {
                count1++;
                }
                else if(x==10)
                {
                count2++;
                }
            }
            if(count1==3||count2==3)
            break;
        }
    }

    if((count1!=3)&&(count2!=3))
    {
        count1=0;
        count2=0;
        for(r=0;r<3;r++) //left to right diagonal elements check hence r=c
        {
            if(arr[r][r]==100)
            {
                count1++;
            }
            else if(arr[r][r]==10)
            {
                count2++;
            }
        }
    }

    if((count1!=3)&&(count2!=3))
    {
        count1=0;
        count2=0;
        for(r=0;r<3;r++) //right to left diagonal hence (0,2) (1,1) (2,0) //c+r=2
        {
            for(c=0;c<3;c++)
            {
                if((c+r)==2)
                {
                    if(arr[r][c]==100)
                    count1++;
                    else if(arr[r][c]==10)
                    count2++;
                }
            }

        }
    }
}

void prev_pos() /*Previously occupied position check*/   
{         
	int c,p,q;
    for(p=0;p<3;p++)
    {
        for(q=0;q<3;q++)
        {
            if(p==0) // when row number is 0 the value of elements in different columns would be q+1
            {
                c=0;
                c=q+1;
                if(c==val)
                {
                    if(arr[p][q]==100||arr[p][q]==10)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(p==1) // when row number is 1 the value of elements in different columns would be q+4
            {
                c=0;
                c=q+4;
                if(c==val)
                {
                    if(arr[p][q]==100||arr[p][q]==10)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(p==2) // when row number is 2 the value of elements in different columns would be q+7
            {
                c=0;
                c=q+7;
                if(c==val)
                {
                    if(arr[p][q]==100||arr[p][q]==10)
                    {
                        flag=1;
                        break;
                    }
                }
            }


        }
        if(flag==1)
        break;
    } 
}

void CPU_intel() /* The conditions check for which Player or the CPU is about to win */
{
	
    int r,c;
	int pos=0,ver1=0,ver2=0;                 
	for(r=0;r<3;r++) //row wise check for Player if it is about to win so that CPU counteracts it
    {
		ver1=0;
        for(c=0;c<3;c++)
        {
            if(arr[r][c]==100)
            {
            	ver1++;
            }
    	}
        if(ver1==2)
        {
			for(c=0;c<3;c++)
			if(arr[r][c]>=1&&arr[r][c]<=9)
        	{
    	    	val=arr[r][c];
    	    	pos=1;
    	    	break;
    		}
    	}     
      	if(pos==1) // elements have been checked and position has been obtained so break
		break;
    } 
    pos=0;
	for(r=0;r<3;r++) //row wise check for CPU if it is about to win
    {
        ver2=0;
        for(c=0;c<3;c++)
        {
			if(arr[r][c]==10)
            {
            	ver2++;
            }
    	}
        if(ver2==2)
        {
			for(c=0;c<3;c++)
			if(arr[r][c]>=1&&arr[r][c]<=9)
        	{
    	    	val=arr[r][c];
    	    	pos=1;
    	    	break;
    		}
    	}    
      	if(pos==1) // elements have been checked and position has been obtained so break
		break;
    }

    if((ver1!=2)&&(ver2!=2)) //column wise check for PLayer when Player and CPU both aren't winning row wise
    {
        pos=0;
		for(c=0;c<3;c++)
        {
            ver1=0;
            for(r=0;r<3;r++)
            {
                if(arr[r][c]==100)
                {
                ver1++;
                }
            }
            if(ver1==2)
            {
				for(r=0;r<3;r++)
				{
					if(arr[r][c]>=1&&arr[r][c]<=9)
	            	{
    	    			val=arr[r][c];
            	    	pos=1;
            	    	break;
            		}
        		}
        	}
			if(pos==1) // elements have been checked and position has been obtained so break
        	break;
        }
    }
    if(ver2!=2) //column wise line check for CPU only when CPU is not winning row wise
    {
        pos=0;
		for(c=0;c<3;c++)
        {
            ver2=0;
            for(r=0;r<3;r++)
            {
                if(arr[r][c]==10)
                {
                ver2++;
                }
            }
            if(ver2==2)
            {
				for(r=0;r<3;r++)
				{
					if(arr[r][c]>=1&&arr[r][c]<=9)
	            	{
    	    			val=arr[r][c];
            	    	pos=1;
            	    	break;
            		}
        		}
        	}
			if(pos==1) // elements have been checked and position has been obtained so break
        	break;
        }
    }

    pos=0;
	if((ver1!=2)&&(ver2!=2)) //left to right diagonal check when both aren't winning row and column wise
    {
        ver1=0;
        ver2=0;

        for(r=0;r<3;r++) //elements are when r=c
        {
            if(arr[r][r]==100)
            {
                ver1++;
            }
            else if(arr[r][r]==10)
            {
                ver2++;
            }
        }
        if(ver1==2||ver2==2)
        {
			for(r=0;r<3;r++)
			{
				if(arr[r][r]>=1&&arr[r][r]<=9)
            	{
    	    		val=arr[r][r];
        	    	break;
        		}
    		}
    	}
    }
    
    pos=0;
	if((ver1!=2)&&(ver2!=2)) //right to left diagonal check when both aren't winning c wise,r wise and left to right diagonal wise
    {
        ver1=0;
        ver2=0;
        for(r=0;r<3;r++) //right to left diagonal hence (0,2) (1,1) (2,0) //c+r=2
        {
            for(c=0;c<3;c++)
            {
                if((c+r)==2)
                {
                    if(arr[r][c]==100)
                    ver1++;
                    else if(arr[r][c]==10)
                    ver2++;
                }
            }
        }
        if(ver1==2||ver2==2)
        {
			for(r=0;r<3;r++)
			{
				for(c=0;c<3;c++)
				{
					if((c+r)==2)
					{
						if(arr[r][c]>=1&&arr[r][c]<=9)
    	            	{
    	    				val=arr[r][c];
                	    	break;
                		}
                	}
    			}
    		}                                    			
    	 }    
    }  		                            
}





