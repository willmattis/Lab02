// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include "TowerGame.h"

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{

	}

	bool IsGameEnded() { return m_GameEnded; }

	void PrintTowers()
	{
		cout<<"1st Stack: "<<stack1.toString()<<endl;
		cout<<"2nd Stack: "<<stack2.toString()<<endl;
		cout<<"3rd Stack: "<<stack3.toString()<<endl;
	}

private:
	bool m_GameEnded;

};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;
	
	ArrayBasedQueue record;
	ArrayBasedStack stack1;
	ArrayBasedStack stack2;
	ArrayBasedStack stack3;
	ArrayBasedStack temp;
	
	int A;
	int B;
	int C;
	int D;
	
	stack1.push(4);
	stack1.push(3);
	stack1.push(2);
	stack1.push(1);
	
	bool receivedEndToken = false;

	while (!receivedEndToken && !game.IsGameEnded())
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

				int diskId = atoi(disk.c_str()); 
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
				record.enQueue(inputline)
				if (fromId==1) {
					stack1.pop();
					if (toId==2) {
						stack2.push(diskId);
					}
					else if (toId==3) {
						stack3.push(diskId);
					}
				}
				else if (fromId=2) {
				    stack2.pop();
				    if (toId=1) {
					stack1.push(diskId);
				    }
				    else if (toId=3) {
					stack3.push(diskId);
				    }
				}
				else if (fromId=3) {
				    stack3.pop();
				    if (toId=1) {
					stack1.pop();
				    }
				    else if (toId=2) {
					stack2.push(diskId);
				    }  
				}
				temp=stack3;
				
				A=temp.peek();
				temp.pop();
				
				B=temp.peek();
				temp.pop();
				
				C=temp.peek();
				temp.pop();
				
				D=temp.peek();
				temp.pop();

				if ((A=1) && (B=2) && (C=3) && (D=4)) {
				    
					receivedEndToken=true;
					cout<<"Steps: "<<toString(record)<<endl;
					while (!record.isEmpty()) {
						record.deQueue();

				    	}
				    	cout<<"You have completed the tower of hanoi"<<endl;
			        }
		}



	}

    return 0;
}

