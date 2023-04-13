// File containing functions for The Oasis passage
#include <iostream>
#include <string>
#include "The Oasis.hpp"
#include "Functions.hpp"
#include "Journal Entries.hpp"
#include "Trackers.hpp"
#include "Items.hpp"

using namespace std;

void the_oasis_text()
{
    print_line();
    cout << "You stumble out of the portal and quickly catch your balance as it closes behind you. Standing up straight, you take in your surroundings.\n"
            "You find yourself in a hot and humid jungle, large trees and exotic-looking plants surround you on all sides. The sun burns brightly through the canopy of trees.\n"
            "Although the jungle is dense and the undergrowth thick, you're just able to make out three pathways in front of you - one to your left, one directly ahead, and another to your right.\n"
            "Looking behind you, you see a carved stone archway with no active portal. You look back towards the three pathways in front of you.\n";
    the_oasis();
}

void the_oasis()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the left path\n";
    cout << "B. Explore the middle path\n";
    cout << "C. Explore the right path\n";
    print_line();
    cin >> choice;

    if(choice == 'A' || choice == 'a')
    {
        cout << "You decide to explore the left path.";
    }
    else if(choice == 'B' || choice == 'b')
    {
        cout << "You decide to explore the middle path.";
    }
    else if(choice == 'C' || choice == 'c')
    {
        cout << "You decide to explore the right path.";
    }
    else
    {
        try_again();
        the_oasis();
    }
}