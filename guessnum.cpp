// Copyright Warren & Carter Sande & partners :-) 2009-2022
// Released under MIT license   https://opensource.org/licenses/mit-license.php
// ------------

#include <iostream>
#include <string>
#include <random>

bool playAgain();
int getGuess(int, int);
bool isNum(const std::string&);

int main()
{
    const int minNumber{1};
    const int maxNumber{100}; // Refer to the line 92 before setting the new value
    const unsigned maxTries{6};

    std::random_device rd;
    std::uniform_int_distribution<int> dist(minNumber, maxNumber);
    bool gameIsRunning{true};

    while (gameIsRunning)
    {
        int guess{0};
        unsigned tries{0};
        int secret{dist(rd)};

        std::cout << "AHOY!  I'm the Dread Pirate Roberts, ";
        std::cout << "and I have a secret!\n";
        std::cout << "It is a number from " << minNumber << " to " << maxNumber;
        std::cout << ".  I'll give you " << maxTries << " tries.\n";

        while ((guess != secret) && (tries < maxTries))
        {
            // Allows up to maxTries guesses
            guess = getGuess(minNumber, maxNumber);

            if (guess < secret)
            {
                std::cout << "Too low, ye scurvy dog!\n";
            }
            else if (guess > secret)
            {
                std::cout << "Too high, landlubber!\n";
            }

            ++tries; // Uses up one try
        }

        // Prints a message at the end of the game
        if (guess == secret)
        {
            std::cout << "Avast! Ye got it!  Found my secret, ye did!\n";
        }
        else
        {
            std::cout << "No more guesses!  Better luck next time, matey!\n";
            std::cout << "The secret number was " << secret << ".\n";
        }

        if (!playAgain())
        {
            gameIsRunning = false;
        }
    }
    return 0;
}

bool playAgain()
{
    std::string s;

    std::cout << "Do you want to play again? (yes/no)\n";
    getline(std::cin >> std::ws, s);
    return (tolower(s[0]) == 'y');
}

int getGuess(int min, int max)
{
    std::string s;
    int g;

    while (true)
    {
        std::cout << "What's yer guess? ";
        getline(std::cin >> std::ws, s);
        s.erase(0, std::min(s.find_first_not_of('0'), s.size() - 1)); // Removes all leading zeroes

        if (isNum(s))
        {
            s = s.substr(0, 5); // Cuts the string to the 5 characters length, so the max value entered by player now is 99999
            g = stoi(s);

            if ((g >= min) && (g <= max))
            {
                break;
            }
        }
    }

    return g;
}

bool isNum(const std::string& s)
{
    for (auto it{s.begin()}; it != s.end(); it++)
    {
        if (!isdigit(*it))
        {
            return false;
        }
    }

    return true;
}
