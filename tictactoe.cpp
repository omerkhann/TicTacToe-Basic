#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

void displayBoard(char []);
int checkWinner(char[]);
bool checkTie(char[]);
bool isValid(char[], int);
int playerOneTurn(string playername);
int playerTwoTurn(string);
int computerTurn();


int main()
{

string player1, player2;
char board[9] = {'1','2','3','4','5','6','7','8','9'};
int p1Score = 0, 
	p2Score = 0,
	gameTypeChoice = 0;
int winnerReturn = 0;

bool flag = true;
bool playerWinCheck = false;

	

	cout<<"==========="<<endl;
	cout<<"Tic Tac Toe"<<endl;
	cout<<"==========="<<endl;

	cout<<"Welcome to the Tic Tac Toe game!"<<endl;
	cout<<"Would you like to play: \n1. Player v Player\n2. Player v Computer\nEnter your choice: "<<endl;
	cin>>gameTypeChoice;
	cin.ignore();

	switch (gameTypeChoice)
	{
	
	case 1:

		cout<<"Enter Player 1's name: ";
		getline(cin,player1);
		cout<<"Enter Player 2's name: ";
		getline(cin,player2);
		displayBoard(board);

		while(flag){

			int turn1 = playerOneTurn(player1);
			board[turn1] = 'O';
			displayBoard(board);

			winnerReturn = checkWinner(board);
			if (winnerReturn == 1){
				cout<<"Player 1 won!";
				p1Score++;
				break;
			}
			

			int turn2 = playerTwoTurn(player2);
			board[turn2] = 'X';
			displayBoard(board);

			winnerReturn = checkWinner(board);
			if (winnerReturn == 2){
				cout<<"Player 2 won!";
				p2Score++;
				flag = false;
			}			
								
			displayBoard(board); 
	
		}

		break;

	case 2:

		cout<<"Enter Player 1's name: ";
		getline(cin,player1);
    	displayBoard(board); 

		break;		

	default:
	cout<<"Invalid option entered";
		break;
	}
return 0;
}


void displayBoard(char board[]){

	for(int i=0; i<9; i++)
	{
		if((i%3==0)&&((i/3)>0))
		{
			cout<<endl;
			cout<<"---|---|---";
			cout<<endl;
		}
		if(i==2||i==5||i== 8){
			cout<<" "<<board[i]<<" ";
		}
		else{
		cout<<" "<<board[i]<<" |";
		}
	}
	cout<<endl<<endl;
}


int playerOneTurn(string playername){
	
	int cell = 0;
	cout<<playername<<"'s turn (O)"<<endl;
	while((cell<1)||(cell>9)){
	cout<<"Enter the number of the cell where you want to place your O: ";
	cin>>cell;
	}
	return cell-1;
}


int playerTwoTurn(string playername){
	
	int cell = 0;
	cout<<playername<<"'s turn (X)"<<endl;
	while((cell<1)||(cell>9)){
	cout<<"Enter the number of the cell where you want to place your X: ";
	cin>>cell;
	}
	return cell-1;
}

/*bool checkWinner(char board[]){
	if(board[0]==board[1])
	return true;
}*/

int checkWinner(char board[]) {
   
   //Returns 1 if P1 wins
   //Returns 2 if P2 wins
   //Returns 0 if no one wins

    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2]) 
		{
			if(board[i * 3]=='O')
            	return 1;
			else if (board[i*3] == 'X'){
				return 2;
			}
		}
        }
    
    // Check columns
    for (int i = 0;i < 3; ++i) {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
            if(board[i]=='O')
            	return 1;
			else if (board[i] == 'X'){
				return 2;
			}
        }
    }
    
    // Check diagonals
    if ((board[0] == board[4] && board[4] == board[8]) || (board[2] == board[4] && board[4] == board[6])) {
        	if(board[0]=='O')
            	return 1;
			else if (board[0] == 'X')
				return 2;
	}
			else return 0;
}