#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

void display();
int inputUser();
int winner(string, string);
void showChoice(string choice);
void slowPrint(string text, int delay);
void setColor(int color);
void playSound(int result);
void showScoreboard(int userScore, int computerScore, const string& result);

int main()
{
    srand(time(0));
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    char input;
    int userScore = 0;
    int computerScore = 0;

    do
    {
        system("cls");
        display();
        int result = inputUser();

        if (result == 1)
        {
            userScore++;
        }
        else if (result == 0)
        {
            computerScore++;
        }

        cout << "Would you like to play again? (y/n): ";
        cin >> input;
    }
    while (input != 'n');


    cout << "\nFinal Score for " << name << " is: ";
    setColor(14);
    cout << userScore << endl;
    setColor(7);

    cout << "Final Score for Computer is: ";
    setColor(12);
    cout << computerScore << endl;
    setColor(7);


    string resultText;
    if (userScore > computerScore)
    {
        resultText = "WINNER";
    }
    else if (userScore < computerScore)
    {
        resultText = "LOSER";
    }
    else
    {
        resultText = "DRAW";
    }


    showScoreboard(userScore, computerScore, resultText);


    slowPrint(name + " Your final score is: " + to_string(userScore), 100);

    cout << "\n\n********************************\n\n";

    return 0;
}

int inputUser()
{
    int input;
    string userChoice;

    cout << "1) Rock\n2) Paper\n3) Scissors\n";

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> input;

        if (input == 1)
        {
            userChoice = "Rock";
            break;
        }
        else if (input == 2)
        {
            userChoice = "Paper";
            break;
        }
        else if (input == 3)
        {
            userChoice = "Scissors";
            break;
        }
        else
        {
            setColor(4);
            cout << "Invalid input! Please enter 1, 2, or 3.\n";
            setColor(7);
        }
    }

    cout << "\nYou chose:\n";
    showChoice(userChoice);

    int computerInput = rand() % 3 + 1;
    string computerChoice = (computerInput == 1) ? "Rock" :
                            (computerInput == 2) ? "Paper" : "Scissors";

    cout << "Computer chose:\n";
    showChoice(computerChoice);

    int result = winner(userChoice, computerChoice);

    playSound(result);

    if (result == 1)
    {
        setColor(10);
        cout << "You win!\n";
    }
    else if (result == 0)
    {
        setColor(4);
        cout << "Computer won!\n";
    }
    else
    {
        setColor(6);
        cout << "It's a Draw!\n";
    }
    setColor(7);

    return result;
}

int winner(string userChoice, string computerChoice)
{
    if (userChoice == computerChoice) return -1;

    if ((userChoice == "Rock" && computerChoice == "Scissors") ||
            (userChoice == "Scissors" && computerChoice == "Paper") ||
            (userChoice == "Paper" && computerChoice == "Rock"))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    setColor(11);
    cout << "********************************\n";
    cout << "__________ Rock, Paper, Scissors Game __________\n";
    cout << "\nGame Rules:\n";
    setColor(15);
    cout << "-> Rock crushes Scissors\n";
    cout << "-> Scissors cuts Paper\n";
    cout << "-> Paper covers Rock\n\n";
    setColor(7);
}

void showChoice(string choice)
{
    if (choice == "Rock")
    {
        setColor(9);
        cout << "    ___\n";
        cout << "---'   __)\n";
        cout << "      (___)\n";
        cout << "      (___)\n";
        cout << "      (__)\n";
        cout << "---._(__)\n\n";
    }
    else if (choice == "Paper")
    {
        setColor(13);
        cout << "     ___\n";
        cout << "---'    _)_\n";
        cout << "           __)\n";
        cout << "          ___)\n";
        cout << "         ___)\n";
        cout << "---.____)\n\n";
    }
    else if (choice == "Scissors")
    {
        setColor(14);
        cout << "    ___\n";
        cout << "---'   _)_\n";
        cout << "          __)\n";
        cout << "       ____)\n";
        cout << "      (__)\n";
        cout << "---._(__)\n\n";
    }
    setColor(7);
}

void slowPrint(string text, int delay)
{
    for (char ch : text)
    {
        cout << ch << flush;
        Sleep(delay);
    }
    cout << endl;
}

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void playSound(int result)
{
    if (result == 1)
    {
        Beep(800, 200);
        Beep(1000, 200);
    }
    else if (result == 0)
    {
        Beep(400, 200);
        Beep(300, 200);
    }
    else
    {
        Beep(600, 200);
        Beep(600, 200);
    }
}

void showScoreboard(int userScore, int computerScore, const string& result)
{
    setColor(11);
    cout << "\n\n";
    cout << "*********** SCOREBOARD ****************\n";
    cout << "*                                                                                         *\n";
    cout << "*                      User Score: " << userScore << "                                                      *\n";
    cout << "*                      Computer Score: " << computerScore << "                                                  *\n";
    cout << "*                      Result: " << result << "                                                       *\n";
    cout << "*                                                                                         *\n";
    cout << "*******************************\n\n";

    if (result == "WINNER")
    {
        setColor(10);
        cout << "W   W  W   W  III  N   N  N   N  EEEE  RRRR  \n";
        cout << "W   W  W   W   I   NN  N  NN  N  E     R   R \n";
        cout << "W   W  W   W   I   N N N  N N N  EEEE  RRRR  \n";
        cout << "W W W  W W W   I   N  NN  N  NN  E     R  R  \n";
        cout << " W W    W W   III  N   N  N   N  EEEE  R   R \n";
    }
    else if (result == "LOSER")
    {
        setColor(4);
        cout << "L       OOO   SSSS  EEEE  RRRR  \n";
        cout << "L      O   O  S     E     R   R \n";
        cout << "L      O   O  SSSS  EEEE  RRRR  \n";
        cout << "L      O   O     S  E     R  R  \n";
        cout << "LLLLL   OOO   SSSS  EEEE  R   R \n";
    }
    else
    {
        setColor(6); // Yellow for DRAW
        cout << "D D D   RRRR    AAAAA  W   W\n";
        cout << "D   D   R   R   A   A  W   W\n";
        cout << "D   D   RRRR    AAAAA  W W W\n";
        cout << "D   D   R  R    A   A  W W W\n";
        cout << "DDDD    R   R   A   A  W W W\n";
    }
    setColor(7); // Reset color
    cout << "\n**********************\n";
}