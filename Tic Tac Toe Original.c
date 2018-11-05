	/*TIC TAC TOE game development
	
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
	
	void display();
	void win();
	
	int arr[3][3]={1,2,3,4,5,6,7,8,9};
	int count1=0,count2=0;
	
	main()
	{
		int i,j,val,r,c,count=0;
		int p,q;
		char ch;
		do
		{
			int assign=1,flag;
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
			for(i=1;i<10;i++)
			{
				count=0;
				if(i%2==1) // Turn for player 1 comes at i=1,3,5 and so on till 9
				{
					do
					{
						flag=0;
						printf("\n\nPLAYER 1: ");
						scanf("%d",&val);
						int c;
						if(val>=1&&val<=9)
						{
							for(p=0;p<3;p++)
							{
								for(q=0;q<3;q++)
								{
									if(p==0)  // when row number is 0 the value of elements in different columns would be q+1
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
							
							if (flag==1)
							{	
								printf("\nSorry the position is previously occupied.Enter again.");
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
						int c;
						if(val>=1&&val<=9)
						{
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
								
							if(flag==1)
							{	
								printf("\nSorry, the position is previously occupied.Enter again.");
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
							flag=1;
						}
					}while(flag==1);
				}
				system("cls");
				printf("\t\t   Welcome to Tic Tac Toe Game\n\n");
				display();
				win();
				if(count1==3)
				{
					printf("\n\n\t\t\t Player 1 WINS!\n\n");
					break;
				}
				else if(count2==3)
				{
					printf("\n\n\t\t\t Player 2 WINS!\n\n");
					break;
				}	
			}
			if( (count1!=3)&&(count2!=3) )
			{
				printf("\n\n\t\t\t  Its a draw!\n\n");
			}
			printf("Want to play again? (y/n):");
			fflush(stdin);
			scanf("%c",&ch);
		}while(ch=='y'||ch=='Y');
	
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
		
		
		
		
		
		

