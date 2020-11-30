// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class TowersOfHannoiGame
{
public:
	
	TowersOfHannoiGame() : m_GameEnded(false)
	{
		
	}
	
	bool IsGameEnded() { return m_GameEnded; }
	
	void startGame(){
		int number_discs=4;
		for(int i = 1; i <= number_discs; i++){
			startingTower.push(5-i);
		}
	}	
	
	
	void PrintTowers()
	{
		cout<<"Tower One: ";
		if(startingTower.isEmpty() == true){
			cout << "Empty" << endl;
		}else{
			cout << startingTower.toString() << endl;
		}
		cout << "Tower Two: ";
		if(secondTower.isEmpty() == true){
			cout << "Empty" << endl;
		}else{
			cout << secondTower.toString() << endl;
		}
		cout << "Tower Three: ";
		if(endingTower.isEmpty() == true){
			cout << "Empty" << endl;
		}else{
			cout << endingTower.toString() << endl;
		}
	}

	int peekStartingTower(){
		if(startingTower.isEmpty() != true){
			return startingTower.peek();
		}else{
			return 0;
		}
	}

	int peekSecondTower(){
		if(secondTower.isEmpty() != true){
			return secondTower.peek();
		}else{
			return 0;
		}
	}
	int peekEndingTower(){
		if(endingTower.isEmpty() != true){
			return endingTower.peek();
		}else{
			return 0;
		}
	}
	void popStartingTower(){
		startingTower.pop();
	}
	void popSecondTower(){
		secondTower.pop();
	}
	void popEndingTower(){
		endingTower.pop();
	}
	void pushStartingTower(int val){
		startingTower.push(val);
	}
	void pushSecondTower(int val){
		secondTower.push(val);
	}
	void pushEndingTower(int val){
		endingTower.push(val);
	}
	bool isEmptyStartingTower(){
		return startingTower.isEmpty();
	}
	bool isEmptySecondTower(){
		return secondTower.isEmpty();
	}
	bool isEmptyEndingTower(){
		return endingTower.isEmpty();
	}
	int sizeOfEndingTower(){
		return endingTower.getSizeS();
	}
private:
	bool m_GameEnded;
	ArrayBasedStack startingTower;
	ArrayBasedStack secondTower;
	ArrayBasedStack endingTower;
};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;
	ArrayBasedQueue moves;
	game.startGame();
	int move;
	int totalMoves;

	bool receivedEndToken = false;

	while (!receivedEndToken || game.IsGameEnded())
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str()); //atoi basically static casts a string to int
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());

				int holdInt; //hang onto any value that will be dequeued from the front.
				int val1;
				int val2;
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
					

				}else	

				{
					if(fromId == toId){
						cout << "Invalid move. You should be moving it to another tower, not the same one." << endl;
					}else if(fromId == 1 && toId == 2){
						if(game.isEmptySecondTower()){
							holdInt = game.peekStartingTower();
							game.popStartingTower();
							game.pushSecondTower(holdInt);
							moves.enQueue(inputLine);
						}else{
						val1 = game.peekStartingTower();
						val2 = game.peekSecondTower();
							if(val1 < val2){
								holdInt = game.peekStartingTower();
								game.popStartingTower();
								game.pushSecondTower(holdInt);
								moves.enQueue(inputLine);
							}else{
								cout << "Invalid Move: Bigger Disk cannot be stacked onto smaller disk." << endl;
							}
						}
					}else if (fromId == 1 && toId == 3)
					{
						if(game.isEmptyEndingTower()){
							holdInt = game.peekStartingTower();
							game.popStartingTower();
							game.pushEndingTower(holdInt);
							moves.enQueue(inputLine);
						}else{
							val1 = game.peekStartingTower();
							val2 = game.peekEndingTower();
							if(val1 < val2){
								holdInt = game.peekStartingTower();
								game.popStartingTower();
								game.pushEndingTower(holdInt);
								moves.enQueue(inputLine);
							}else{
								cout << "Invalid Move: Bigger Disk cannot be stacked onto smaller disk." << endl;
							}
						}				
					}else if(fromId == 2 && toId == 3)
					{
						if(game.isEmptyEndingTower()){
							holdInt = game.peekSecondTower();
							game.popSecondTower();
							game.pushEndingTower(holdInt);
							moves.enQueue(inputLine);
						}else{
							val1 = game.peekSecondTower();
							val2 = game.peekEndingTower();
							if(val1 < val2){
								holdInt = game.peekSecondTower();
								game.popSecondTower();
								game.pushEndingTower(holdInt);
								moves.enQueue(inputLine);
							}else{
								cout << "Invalid Move: Bigger Disk cannot be stacked onto smaller disk." << endl;
							}
						}
					}else if(fromId == 2 && toId == 1)
					{
						if(game.isEmptyStartingTower()){
							holdInt = game.peekSecondTower();
							game.popSecondTower();
							game.pushStartingTower(holdInt);
							moves.enQueue(inputLine);
						}else{
							val1 = game.peekSecondTower();
							val2 = game.peekStartingTower();
							if(val1 < val2){
								holdInt = game.peekSecondTower();
								game.popSecondTower();
								game.pushStartingTower(holdInt);
								moves.enQueue(inputLine);
							}else{
								cout << "Invalid Move: Bigger Disk cannot be stacked onto smaller disk." << endl;
							}
						}
					}else if(fromId == 3 && toId == 1)
					{
						if(game.isEmptyStartingTower()){
							holdInt = game.peekEndingTower();
							game.popEndingTower();
							game.pushStartingTower(holdInt);
							moves.enQueue(inputLine);
						}else{
							val1 = game.peekEndingTower();
							val2 = game.peekStartingTower();
							if(val1 < val2){
								holdInt = game.peekEndingTower();
								game.popEndingTower();
								game.pushStartingTower(holdInt);
								moves.enQueue(inputLine);
							}else{
								cout << "Invalid Move: Bigger Disk cannot be stacked onto smaller disk." << endl;
							}
						}
					}else if(fromId == 3 && toId == 2)
					{
						if(game.isEmptySecondTower()){
							holdInt = game.peekEndingTower();
							game.popEndingTower();
							game.pushSecondTower(holdInt);
							moves.enQueue(inputLine);
						}else{
							val1 = game.peekEndingTower();
							val2 = game.peekSecondTower();
							if(val1 < val2){
								holdInt = game.peekEndingTower();
								game.popEndingTower();
								game.pushSecondTower(holdInt);
								moves.enQueue(inputLine);
							}else{
								cout << "Invalid Move: Bigger Disk cannot be stacked onto smaller disk." << endl;
							}
						}
					}	
				

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;

				

			}
		}
		if(game.sizeOfEndingTower() == 3){
			receivedEndToken = true;
		}
	}
	}
	std::ofstream ofs("moves.txt", std::ofstream::out);
	totalMoves = moves.getSizeQ();
	for (int i = 0; i <= totalMoves; i++)
 	{
  		std::string name = moves.peekFront();
		moves.deQueue();
  		std::cout << name << " " << std::endl;
  		ofs<< name << " " << std::endl;
 	} 
 	std::cout <<  std::endl;
 	ofs.close();
    
	return 0;
}

