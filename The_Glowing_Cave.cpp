// File containing functions for The Glowing Cave passage
#include<iostream>
#include<string>
#include"The_Glowing_Cave.hpp"
#include"Functions.hpp"
#include"Trackers.hpp"
#include"Items.hpp"

using namespace std;

bool explored_left_tunnel = false;
bool explored_right_tunnel = false;
bool explored_path = false;

void the_glowing_cave_text(){
    print_line();
    cout << "Bracing yourself, you close your eyes and take a step into the portal.\n"
            "However, you are met with an eerie silence, followed by a sudden feeling of moisture in the air.\n"
            "You open your eyes and are immediately met with the beautiful site of a large glowing fungi right in front of you.\n"
            "Awestruck, you slowly circle the giant mushroom as you drag your hand across the surface of its massive stem.\n"
            "It's about as big as a tree, with a soft turquoise light emanating from the gills and cap of the mushroom.\n"
            "Trails of the soft light are made where your fingers brush the stem before softly fading like a heat-sensitive coating.\n"
            "After a moment, you finally move your eyes away from the mesmerizing mushroom and scan your surroundings.\n"
            "You appear to be in a large cavern, surrounded by clusters of the strange glowing fungi scattered about the walls an floors of the cave.\n"
            "With the mushrooms providing the only light in the otherwise dark and dank cave, you slowly take a step forward.\n"
            "You accidentally step into a deep puddle you were trying to avoid and end up making a large splash sound that echoes a bit within the confines of the cave.\n"
            "You suddenly hear an odd shuffling noise. Unsettled, you slowly look up and can barely make out large shapes spread out across the ceiling of the underground chamber.\n"
            "Bats. Very large bats. You stand stock still, your shoe now completely soaked, but you dare not wake the flying mammal."
            "After the bat settles down, you quietly sigh in relief. Looking back toward the ground level of the cave, you see two tunnels branching off from the chamber you're in directly ahead of you.\n"
            "There is also another path on the opposite side of the wall, between some large mushrooms you see a well-tread path leading further into the cave.";
    the_glowing_cave();
}

void the_glowing_cave(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Explore the left tunnel\n";
    cout << "B. Explore the right tunnel\n";
    cout << "C. Explore the well-tread path\n";
    print_line();
    cin >> choice;
    if(choice == 'a' || choice == 'A'){
        
    }
    else if(choice == 'b' || choice == 'B'){

    }
    else if(choice == 'c' || choice == 'C'){

    }
    else{
        try_again();
        the_glowing_cave();
    }
    retry();
}
