#include<iostream>
#include<string>
using namespace std;
    char user[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char turn = 'O';
    int row,column;
  bool draw=false;

int game()
{
	system("cls");
	cout<<"\n\n\t\t\t\t\t\t\t\t\t TIC TAC TOE GAME"<<endl;
	cout<<"____________________________________________________________________________________";
	cout<<"____________________________________________________________________________________"<<endl;	
	cout<<"\n\n\t\t\t\tWelcome to the most played 2D game and a sort of fun using X or O in the desired position"<<endl;
	cout<<"\n\nRules:-"<<endl;
	cout<<"\n1.Each player will be entering the number to put respective X or O in the desired position."<<endl;
	cout<<"2.player who gets a combination of 3 same characters either diagonal or horizontally or vertically will be declared as winner."<<endl;
	cout<<"\nEnjoy the game ! Be a winner !!!"<<endl;

	cout<<"\n\n\t Player 1 which takes character 'O'";
	cout<<"\n\t Player 2 which takes character 'X'";

	cout<<"\n\n\t\t\t\t\t\t\t\t\t _________________"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|     |     |     |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  "<<user[0][0]<<"  |  "<<user[0][1]<<"  |  "<<user[0][2]<<"  |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|_____|_____|_____|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|     |     |     |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  "<<user[1][0]<<"  |  "<<user[1][1]<<"  |  "<<user[1][2]<<"  |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|_____|_____|_____|"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|     |     |     |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|  "<<user[2][0]<<"  |  "<<user[2][1]<<"  |  "<<user[2][2]<<"  |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|_____|_____|_____|"<<endl;
		
}
int player_turn()
{
	int position;
	
	if(turn=='O')
	cout<<"\n\n\n Player 1 (O) turn : ";
	
	if(turn=='X')
	cout<<"\n\n\n Player 2 (X) turn : ";
    cin>>position;
    
    switch(position)
    {
    	case 1:
    	    row=0;column=0;
    		break;
    	case 2:
    	    row=0;column=1;
    		break;
    	case 3:
    		row=0;column=2;
    		break;
    	case 4:
    		row=1;column=0;
    		break;
		case 5:
			row=1;column=1;
    		break;
		case 6:
			row=1;column=2;
    		break;
		case 7:
			row=2;column=0;
    		break;
		case 8:
			row=2;column=1;
    		break;
		case 9:
			row=2;column=2;
    		break;
		default	:
		    cout<<"Invalid input"<<endl;
			break;		    		
	}
	if(turn=='O' && user[row][column]!='X' && user[row][column]!='O')
	{
		user[row][column]='O';
		turn='X';
    }

	else if(turn=='X' && user[row][column]!='X' && user[row][column]!='O')
	{
		user[row][column]='X';
		turn='O';
	}
    else
    {
    	cout<<" Box already filled!\n try again later ";
    	player_turn();
	}
	game();
	
}

bool gameover()
{
	int i,j,k;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(user[i][0]==user[i][1] && user[i][0]==user[i][2] || user[0][j]==user[1][j] && user[0][j]==user[2][j]  )
	return false;
	
	if(user[0][0]==user[1][1] && user[0][0]==user[2][2] || user[0][2]==user[1][1] && user[0][2]==user[2][0] )
	return false;
	
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(user[i][j] != 'O' && user[i][j] != 'X')
	return true;
	
	draw=true;
	return false;
	
}
int main()
{
	
	while(gameover())
	{
    game();
	player_turn();
    gameover();
    }   
    if(turn=='X' && draw==false)
    cout<<"Player 1 (O) won the game !!! \n\n\n\t\t\t\t\t\t Congratulations "<<endl;
    
    else if(turn=='O' && draw==false)
    cout<<"Player 2 (X) won the game !!! \n\n\n\t\t\t\t\t\t Congratulations"<<endl;
    
    else
    cout<<"Game Draw"<<endl;
}
