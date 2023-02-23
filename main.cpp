#include <iostream>
// #include <stdlib.h>     //FOR system("cls")
#include <string.h> //FOR strlen()
#include <ctime>
#include <cstdlib> //FOR srand() & rand()
#include <stdio.h> //FOR remove() & rename()
#include <fstream>

using namespace std;

class Hangman
{
  string selectedWord;
  string unknownWord;
  char guessedWord;
  int wrongGuesses, flag, n, len, score, hscore, check;

public:
  Hangman() // Initializing and selecting word
  {
    wrongGuesses = 0;
    score = 0;
    hscore = 0;

    srand(time(0));

    n = rand() % 13;

    if (n == 0)
      selectedWord = "hypnotized";
    if (n == 1)
      selectedWord = "chemistry";
    if (n == 2)
      selectedWord = "maths";
    if (n == 3)
      selectedWord = "wish";
    if (n == 4)
      selectedWord = "black";
    if (n == 5)
      selectedWord = "human";
    if (n == 6)
      selectedWord = "love";
    if (n == 7)
      selectedWord = "boyfriend";
    if (n == 8)
      selectedWord = "friends";
    if (n == 9)
      selectedWord = "champion";
    if (n == 10)
      selectedWord = "lubricant";
    if (n == 11)
      selectedWord = "worship";
    if (n == 12)
      selectedWord = "education";

    len = selectedWord.length();

    // len = strlen(selectedWord);

    unknownWord = string(len, '_');
  }

  void Menu();

  void Display();
  void Reset();

  void Interaction();
  void Intro();
  void Score();

  void Logic();
};

// FOR ACCESSING
void Hangman::Menu()
{
  char choice;

  Intro();

  do
  {
    Interaction();
    Reset();

    if (check == 1)
    {
      cout << "\n\t\tPLAY AGAIN (Y/N) : ";
      cin >> choice;
    }
    else
      choice = 'n';

    // TO PLAY AGAIN
  } while (choice == 'Y' || choice == 'y');

  Score();
}

void Hangman::Display()
{

  system("cls");

  // HEADER
  cout << "\n\n\t\t\t"
       << "HANGMAN" << endl;
  cout << "\t\t    "
       << "-x___________x-"
       << "\n"
       << endl;

  // GRAPHIC

  switch (wrongGuesses)
  {

  case 0:

    cout << "\t\t      "
         << " __________" << endl; // 10
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 7" << endl;

    break;

  case 1:

    cout << "\t\t      "
         << " __________" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|          O" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 6" << endl;

    break;

  case 2:

    cout << "\t\t      "
         << " __________" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|          O" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 5" << endl;

    break;

  case 3:

    cout << "\t\t      "
         << " __________" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|          O" << endl;
    cout << "\t\t      "
         << "|         \\|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 4" << endl;

    break;

  case 4:

    cout << "\t\t      "
         << " __________" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|          O" << endl;
    cout << "\t\t      "
         << "|         \\|/" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 3" << endl;

    break;

  case 5:

    cout << "\t\t      "
         << " __________" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|          O" << endl;
    cout << "\t\t      "
         << "|         \\|/" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 2" << endl;

    break;

  case 6:

    cout << "\t\t      "
         << " __________" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|          O" << endl;
    cout << "\t\t      "
         << "|         \\|/" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|         /" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 1" << endl;

    break;

  case 7:

    cout << "\t\t      "
         << " __________" << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|          O" << endl;
    cout << "\t\t      "
         << "|         \\|/ " << endl;
    cout << "\t\t      "
         << "|          |" << endl;
    cout << "\t\t      "
         << "|         / \\ " << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "|" << endl;
    cout << "\t\t      "
         << "-" << endl;
    cout << "\n\t\t\      "
         << "Tries Left : 0" << endl;

    break;
  }

  cout << "\n\tWord: " << unknownWord << "\tLength: " << len << "\n"
       << endl;
}

// RESTARTING
void Hangman::Reset()
{
  wrongGuesses = 0;
  srand(time(0));

  n = rand() % 13;

  if (n == 0)
    selectedWord = "hypnotized";
  if (n == 1)
    selectedWord = "chemistry";
  if (n == 2)
    selectedWord = "maths";
  if (n == 3)
    selectedWord = "wish";
  if (n == 4)
    selectedWord = "black";
  if (n == 5)
    selectedWord = "human";
  if (n == 6)
    selectedWord = "love";
  if (n == 7)
    selectedWord = "boyfriend";
  if (n == 8)
    selectedWord = "friend";
  if (n == 9)
    selectedWord = "champion";
  if (n == 10)
    selectedWord = "lubricant";
  if (n == 11)
    selectedWord = "worship";
  if (n == 12)
    selectedWord = "education";

  len = selectedWord.length();

  unknownWord = string(len, '_');
}

// MAIN
void Hangman::Interaction()
{

  system("cls");

  // GAME STARTS
  do
  {
    Display();

    cout << "Guess a letter(s) of the word : ";
    cin >> guessedWord;

    Logic(); // To check winning condition

  } while (check == 0);

  // RESULTS
  if (check == 1)
  {
    Display();
    cout << "You have guessed the correct word : " << selectedWord << endl;
    score++;

    // STORING HIGHSCORE IN THE FILE

    ofstream fout("Score.txt");

    if (fout.is_open()) // If file already exists
    {
      ifstream fin("Score.txt"); // For reading highscore from the file
      ofstream temp("temp.txt");

      fin >> hscore;

      if (score > hscore)
      {
        temp << score; // Storing score in new file

        temp.close();
        fin.close();

        flag = 1; // Primary Key for updating highscore
      }
      else
      {
        temp.close();
        fin.close();

        flag = 0; // Primary Key for not updating highscore
      }
    }
    else
    {
      fout << score;
    }

    fout.close();

    if (flag == 1) // Updating Highcore
    {
      remove("Score.txt");
      rename("temp.txt", "Score.txt");
    }
    else
    {
      remove("temp.txt");
    }
  }
  else
  {
    int key;

    Display();

    cout << "\n\t\t    "
         << "GAME OVER!\n"
         << endl;
    cout << "Sorry you couldn't guess the correct word\nCorrect Word : " << selectedWord << endl;

    cout << "\n\nPress any key to continue...";
    cin >> key;
  }
}

void Hangman::Intro()
{
  char key;

  // HEADER
  cout << "\n\n\t\t\t"
       << "Hangman" << endl;
  cout << "\t\t    "
       << "-x___________x-" << endl;
  cout << "\n\t        Created by Vatsal Singh\n\n"
       << endl;

  // DISpLAY
  cout << "\t\t      "
       << " __________" << endl;
  cout << "\t\t      "
       << "|          |" << endl;
  cout << "\t\t      "
       << "|          O" << endl;
  cout << "\t\t      "
       << "|         \\|/ " << endl;
  cout << "\t\t      "
       << "|          |" << endl;
  cout << "\t\t      "
       << "|         / \\ " << endl;
  cout << "\t\t      "
       << "|" << endl;
  cout << "\t\t      "
       << "|" << endl;
  cout << "\t\t      "
       << "|" << endl;
  cout << "\t\t      "
       << "-" << endl;

  cout << "\n\t\t    "
       << "*INSTRUCTIONS*\n"
       << endl;

  cout << "1. You have to guess the word, given by computer." << endl;
  cout << "2. You can guess a letter or group of letters." << endl;
  cout << "3. You can have maximum 7 wrong guesses." << endl;
  cout << "4. You do not have to use capital letters." << endl;

  cout << "\npress any key to continue... ";
  cin >> key;
}

void Hangman::Score()
{
  char Exit;

  system("cls");

  cout << "\n\n\t\t      SCOREBOARD" << endl;
  cout << "\t\t  -x_______________x-\n"
       << endl;

  cout << "\t"
       << "Number of Correct Words you've guessed : " << score << endl;

  // FOR SHOWING HIGH SCORE

  ifstream fin("Score.txt");
  fin >> hscore;

  fin.close();

  cout << "\n\n\t"
       << "High Score : " << hscore;

  // FOR GIVING TIME TO SEE RESULTS
  cout << "\n\n\n\n\n\tpress any key to exit...";
  cin >> Exit;
}

void Hangman::Logic()
{
  check = 0;
  flag = 0;

  for (int i = 0; i < len; i++)
  {
    if (guessedWord != unknownWord[i]) // STOP REPEATING LETTERS
    {
      if (guessedWord == selectedWord[i])
      {
        unknownWord[i] = guessedWord;
        flag = 1;
        break;
      }
    }
  }

  if (flag == 0) // LETTER NOT MATCHED
  {
    wrongGuesses++;
  }

  if (unknownWord == selectedWord) // LETTER MATCHED
  {
    check = 1;
  }

  if (wrongGuesses == 7) // RAN OUT OF TRIES
  {
    check = -1;
  }

  //   return check;
}

int main()
{
  Hangman obj;
  obj.Menu();

  return 0;
}
