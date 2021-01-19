#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include<windows.h>

using namespace std;

void squareLineMaker(string num1, string num2, string num3);
void playerfiledMaker(vector<string> numbers);
int getUserInput();
bool checkGameOver(string forWho , vector<string> numbers);
bool checkGameFull(vector<string> numbers);

int main()
{
    // make the play field
    vector<string> numbers = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    // ask user for chose

    int userChoose{0};
    int computerChoose{0};  
    bool gameOver = true;
    string userChooseToString = "";
    string computerChooseToString = "";
    int indexPlayerOne{0};
    int indexPlayerTwo{0};
    bool findIndexUser = true;
    bool findIndexComputer = true;

   


    playerfiledMaker(numbers);

    while (true)
    {
        
        userChoose = getUserInput();

        userChooseToString = to_string(userChoose);
        
        for (int i=0; i<9 ; i++)
        {

            if (numbers[i] == userChooseToString && numbers[i] != "X" && numbers[i] != "O")
            {
                findIndexUser = true;
                indexPlayerOne = i;
                break;
            }       
            else
            {
                findIndexUser = false;
            }
                
        }
        if(!findIndexUser)
        {
            cout<<"not a valid number already there , TRY AGAIN !! \n";
            continue;
        }       
        else
            {
                numbers.at(indexPlayerOne) = "X";
                playerfiledMaker(numbers);
                gameOver = checkGameOver("X",numbers);
                if(gameOver)
                {
                    cout<<" *****YOU HAVE WIN WELL DONE******"<<endl;
                    break;
                }
            }
    
       cout << "COMPUTER TURN \n";
        Sleep(1000);

        do{
            srand(time(NULL));
            computerChoose = rand() % 10 + 1;
            computerChooseToString = to_string(computerChoose);
       
        for (int i=0; i<9 ; i++)
        {

             if (numbers[i] == computerChooseToString && numbers[i] != "X" && numbers[i] != "O")
            {
                findIndexComputer = true;
                indexPlayerTwo = i;
                break;
            }       
            else
            {
                findIndexComputer = false;
            }
        }

        }while(!findIndexComputer);
        
         numbers.at(indexPlayerTwo) = "O";
         playerfiledMaker(numbers);
         gameOver = checkGameOver("O",numbers);
         if(gameOver)
         {
              cout<<" *****YOU LOST THE GAME COMPUTER WINS******"<<endl;
              break;
         }

        gameOver = checkGameFull(numbers);
        if(gameOver)
        {
              cout<<" *****NO WINNERS******"<<endl;
              break;
         }
    }

    return 0;
}

void squareLineMaker(string num1, string num2, string num3)
{

    cout << "|";
    for (int i = 1; i <= 18; i++)
    {
        cout << "-";
    }
    cout << "|";
    cout << "\n|      |      |    |\n";
    cout << "|  " << num1 << "   |  " << num2 << "   |  " << num3 << " |";
    cout << "\n|      |      |    |\n|";
    for (int i = 1; i <= 18; i++)
    {
        cout << "-";
    }
    cout << "|";
    cout << "\n";
}

void playerfiledMaker(vector<string> numbers)

{

    squareLineMaker(numbers.at(0), numbers.at(1), numbers.at(2));
    squareLineMaker(numbers.at(3), numbers.at(4), numbers.at(5));
    squareLineMaker(numbers.at(6), numbers.at(7), numbers.at(8));
}

int getUserInput()
{
    int userChoose{0};
    do
    {
        cout << "choose a number to draw your symbole (X is for you and O for the computer ) : \n";
        cin >> userChoose;
        if (userChoose <= 0 || userChoose >= 10)
            cout << "ENTER A VALID INPUT !!!" << endl;

    } while (userChoose <= 0 || userChoose >= 10);

    return userChoose;
}


bool checkGameOver(string forWho , vector<string> numbers)
{
       if(numbers[0]== forWho && numbers[1] == forWho && numbers[2] == forWho)
       {
           return true;
       }
       else if(numbers[3]== forWho && numbers[4] == forWho && numbers[5] == forWho)
       {
           return true;
       }
        else if(numbers[6]== forWho && numbers[7] == forWho && numbers[8] == forWho)
       {
           return true;
       }
        else if(numbers[0]== forWho && numbers[7] == forWho && numbers[6] == forWho)
       {
           return true;
       }
        else if(numbers[1]== forWho && numbers[4] == forWho && numbers[7] == forWho)
       {
           return true;
       }
        else if(numbers[2]== forWho && numbers[5] == forWho && numbers[8] == forWho)
       {
           return true;
       }
        else if(numbers[0]== forWho && numbers[4] == forWho && numbers[8] == forWho)
       {
           return true;
       }
        else if(numbers[2]== forWho && numbers[4] == forWho && numbers[6] == forWho)
       {
           return true;
       }
        return false;
       
}

bool checkGameFull(vector<string> numbers)
{

    const vector<string> numbersVersionOne = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    bool isOver = false;
    for(int i=0;i<9;i++)
    {
        if(numbersVersionOne[i] ==  numbers[i] )
        {
            isOver = false;
            break;
        }
        else
            isOver = true;
    }

    return isOver;

}