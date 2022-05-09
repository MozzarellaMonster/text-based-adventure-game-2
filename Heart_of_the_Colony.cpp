// File containing functions for The Heart of the Colony passage
#include <iostream>
#include <string>
#include "Heart_of_the_Colony.hpp"
#include "Functions.hpp"
#include "Items.hpp"
#include "Trackers.hpp"

using namespace std;

bool explored_left_tunnel = false;

void hotc_explore_nest_text(){
    print_line();
    cout << "You are now free to explore the ant nest as you please, however keep in mind the warnings the Ant Queen gave you:\n"
            "\n\t\"[S]hould you attempt to to bring harm upon any of my subjects or overstay your welcome, I will feed you to them.\"\n\n"
            "You shiver slightly from the memory, but clear your head and focus on the matter at hand. You need to explore the nest and find\n"
            "the token you will need before you can return to the temple.\n"
            "From where you stand, you can see three different tunnels before you that lead away from the Queen's Chambers.\n"
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
        if explored_left_tunnel{
            cout << "You look back to the tunnel that leads to the egg room, and shake your head.\n"
                    "You did not find the token there, it would be unlikely to be there now.\n"
                    "You look back to the options before you.\n";
            hotc_explore_nest();
        }
        else{
            cout << "You decide to explore the left tunnel.\n"
                    "You go down the left tunnel for some distance before it opens into a large open cavernous space with several large stalagnate\n"
                    "serving as pillars for the massive room. Along the walls and floor of the room are several oblong pill-shaped objects with distinct silhouettes wriggling around inside of them.\n"
                    "\"Eggs,\" you think to yourself before hesitantly crossing the threshold into the room. The room is lit with several organic-looking lanterns embedded in the ceiling of the room,\n"
                    "providing a warm glow to the entirety of the large space. Several female worker ants are milling about the room, tending to the different egg clusters and largely ignoring you.\n"
                    "However, if you get a little too close to any one egg, a distinct hiss is heard from any that are nearby. You make haste and search the room without setting off the worker ant's aggression.\n"
                    "Unfortunately, you could find nothing of importance in the room and head back through the tunnel to the Queen's Chambers.\n";
            explored_left_tunnel = true;
            hotc_explore_nest();
        }   
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        cout << "You decide to explore the middle tunnel.\n";
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        cout << "You decide to explore the right tunnel.\n";
    }
    else if(choice == 'D' || choice == 'd'){
        print_line();
        cout << "You decide to explore the Queen's Chambers.\n";
    }
    else{
        try_again();
        hotc_explore_nest();
    }
}

void hotc_tunnel_options(){

}
