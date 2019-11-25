/********************************************************************************************************************************************************/
/***Title: Project #4 - Hangman                                                                                                                       ***/                                                                                 ***/
/***Developer: Haeri Kyoung                                                                                                                           ***/
/***Date: 5-14-2017                                                                                                                                   ***/
/***Description: This is a program that simulates playing the game Hangman. This version of the game will be limited to words with up to six letters. ***/
/********************************************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void draw_hangman(int count)
{
    if (count == 0)
    {
        cout << "  +" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 1)
    {
        cout << "  +----+" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 2)
    {
        cout << "  +----+" << endl;
        cout << "  |    |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 3)
    {
        cout << "  +----+" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 4)
    {
        cout << "  +----+" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |    |" << endl;
        cout << "  |    |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 5)
    {
        cout << "  +----+" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |   \\|" << endl;
        cout << "  |    |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 6)
    {
        cout << "  +----+" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |   \\|/" << endl;
        cout << "  |    |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 7)
    {
        cout << "  +----+" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |   \\|/" << endl;
        cout << "  |    |" << endl;
        cout << "  |   /" << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
    else if (count == 8)
    {
        cout << "  +----+" << endl;
        cout << "  |    |" << endl;
        cout << "  |    O" << endl;
        cout << "  |   \\|/" << endl;
        cout << "  |    |" << endl;
        cout << "  |   / \\ " << endl;
        cout << "  |" << endl;
        cout << "  +-------" << endl;
    }
}

int main(void)
{
    char again;
    do
    {
    srand(time(NULL));          // random seed for randomly choosing one word out of 30 words that are in the text file
    ifstream inFile;
    string infilename = "/Users/HaeriKyoung/Desktop/CPET 121/Xcode/project_4/Hangman/Hangman/words.txt";          // Absolute path for direct location (Xcode)
    inFile.open(infilename);
    string data, the_word;          // 'the_word' is a string of asterick representing the unknown word
    int const ROWS = 2;
    int const COLS = 6;
    int ran_num, word_len, max_guesses = 0, max_letter, wrong_count = 0;
    char letter, selected_word[ROWS][COLS] = {'*', '*', '*', '*', '*', '*', '-', '-', '-', '-', '-', '-'};
    
        cout << "WELCOME TO THE GAME HANGMAN !" << endl;
        cout << endl;
        cout << "Please use lower case letters when guessing a letter." << endl;
        cout << "Do not enter the same letter more than once." << endl;
        cout << endl;

        ran_num = (rand() % 30) + 1;          // Random number generator from 1 to 30
        do
        {
            for (int a = 1; a < 31; a++)
            {
                getline(inFile, data);
                if (a == ran_num)
                {
                    the_word = data;          // One selected random number is equal to the word that is in the opened file which has 30 words
                }
            }
        } while (!(inFile.eof()));
        
        word_len = the_word.length();          // For printing the initial amount of '*' and '_' that show the numbers of letter that is randomly selected
        max_letter = the_word.length();          // For counting the maxiumum amount of tries that the user will have

        do
        {
            cout << endl;
            draw_hangman(max_guesses);
            cout << endl;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < word_len; j++)
                {
                    cout << selected_word[i][j] << "  ";          // this array that has '*' and '-' will be printed out with space " "
                }
                cout << endl;
            }
            if (max_guesses == 8)     // If the maximum amount that the user can give a wrong try is equal to 8, the user fails to win
            {
                cout << endl;
                cout << "Sorry, You've Lost :(" << endl;
                break;
            }
            if (max_letter == 0)     // If all the letters that the user guesses match with all the letters of the unknown word before hangman gallows is drawn, the user wins.
            {
                cout << endl;
                cout << "Congratulations!!! You Won!!!" << endl;
                break;
            }
            cout << endl;
            cout << "Guess a letter: ";
            cin >> letter;          // User input for one letter
            
            for (int k = 0; k < word_len; k++)
            {
                if (letter == the_word[k])          // Checking whether the user input letter is equal to any letters of the selected word
                {
                    selected_word[0][k] = letter;
                    max_letter--;
                }
                else if (letter != the_word[k])          // If the user input letter does not match with any letters of the word,
                {
                    wrong_count++;                       // then increment wrong_count by 1
                }
            }
            if (wrong_count == word_len)           // if wrong_count is equal to word_len (it will only be equal when the user matches the letter),
            {
                max_guesses++;                     // increment max_guesses by 1 so that the hangman gallows will be drawn for one more step becuase the user fails to match
                wrong_count = 0;                   // reset wrong_count to 0 so that wrong_count can be correctly used again until the game ends
            }
            else if (wrong_count != word_len)      // if wrong_count is not equal to word_len (indicates the the user succeeds to match the letter),
            {
                wrong_count = 0;                   // then reset wrong_count to 0
            }
        } while (!(max_guesses > 9));
       
        inFile.close();
        cout << "\n\nDo you want to play again? [Y/N] ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
}
