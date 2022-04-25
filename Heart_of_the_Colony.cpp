// File containing functions for The Heart of the Colony passage
#include <iostream>
#include <string>
#include "Heart_of_the_Colony.hpp"
#include "Functions.hpp"
#include "Items.hpp"
#include "Trackers.hpp"

using namespace std;

void hotc_explore_nest_text(){
    print_line();
    cout << "You are now free to explore the ant nest as you please, however keep in mind the warnings the Ant Queen gave you:\n"
            "\n\t\"[S]hould you attempt to to bring harm upon any of my subjects or overstay your welcome, I will feed you to them.\"\n\n"
            "You shiver slightly from the memory, but clear your head and focus on the matter at hand. You need to explore the nest and find\n"
            "the token you will need before you can return to the temple.\n"
            "From where you stand, you can see three different tunnels before you that lead away from the Queen's Chambers."
            "First, there is the middle tunnel where you were first found but never found out what was at the other end, then there is the\n"
            "tunnel on the left that remains unexplored and the tunnel on the right that also remains unexplored.\n";
    hotc_explore_nest();
}

void hotc_explore_nest(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the left tunnel\n";
    cout << "B. Explore the middle tunnel\n";
    cout << "C. Explore the right tunnel\n";
    cout << "D. Explore the Queen's Chambers\n";
    print_line();
    cin >> choice;

    if(choice == 'A' || choice == 'a'){
        print_line();

    }
    else if(choice == 'B' || choice == 'b'){
        print_line();

    }
    else if(choice == 'C' || choice == 'c'){
        print_line();

    }
    else if(choice == 'D' || choice == 'd'){
        print_line();

    }
    else{
        try_again();
        hotc_explore_nest();
    }
}

void hotc_tunnel_options(){

}
