// File containing functions for The Glowing Cave passage
#include<iostream>
#include<string>
#include"The_Glowing_Cave.hpp"
#include"Functions.hpp"
#include"Trackers.hpp"
#include"Items.hpp"

using namespace std;

bool gc_explored_left_tunnel = false;
bool gc_explored_right_tunnel = false;
bool gc_explored_path = false;

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
            "There is also another path on the opposite side of the wall, between some large mushrooms you see a well-tread path leading further into the cave.\n\n";
    
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
    if(choice == 'A' || choice == 'a'){
        print_line();
        if(gc_explored_left_tunnel){
            // To be filled in...
        }
        else{
            cout << "You decide to explore the left tunnel.\n"
                    "After approaching the left tunnel, you lift your hand to brush away the faintly glowing pink moss swaying over the entrance and feel a damp breeze coming from the opening.\n"
                    "A muffled roaring noise accompanies the slight mist spraying from the entrance, giving you the image of rushing water. The mist gently dampens your face as if to verify your thoughts.\n"
                    "You take a cautious step into the tunnel.\n";
            
            gc_left_tunnel();
        }
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        if(gc_explored_right_tunnel){
            // To be filled in...
        }
        else{
            cout << "You decide to explore the right tunnel.\n"
                    "You walk up to the right tunnel, noticing that this tunnel is darker in comparison to the rest of the chamber or the other tunnel, but not enough to keep you from seeing.\n"
                    "The air here feels drier as well. In fact, it seems that the air from the chamber you're in is flowing out into the tunnel. Despite the fantastical and warm atmosphere of the cave so far,\n"
                    "you feel a sudden surge of trepidation staring into the dim tunnel, as if you were staring down the throat of a large leviathan about to swallow you whole.\n"
                    "Closing your eyes and taking a deep breath, you brace yourself and grip the handle of the dagger, the cold metal of it bringing you some comfort in the unfamiliar surroundings.\n"
                    "After a while, you open your eyes and make your way down the tunnel.\n";
            
            gc_right_tunnel();
        }
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        if(gc_explored_path){
            // To be filled in...
        }
        else{
            cout << "You decide to explore the well-tread path on the opposite side of the cavern.\n"
                    "You turn your back to the two tunnels and quietly make your way across the cave, careful not to make too much noise.\n"
                    "You approach the well-tread path stretching between the fluorescent fungi, smaller mushrooms growing on either side of the pathway, giving the whole thing a comforting feeling of familiarity,\n"
                    "despite the fact that this whole thing is entirely new to you. A small smile plays across your lips as you confidently walk down the path that so many others have tread upon before you.\n"
                    "Walking in the footprints of the Worldwalkers.\n";
            
            gc_pathway();
        }
    }
    else{
        try_again();
        the_glowing_cave();
    }
}

void gc_left_tunnel_text(){
    // Natural land bridge and waterfall - dangerous balancing game
    print_line();
    cout << "You find yourself in a large cavern, a narrow, natural land bridge stretching across a massive canyon splitting the chamber in two. A large waterfall cascades down from above and to the left of the land bridge,\n"
            "completely soaking the bridge to the point that puddles have formed on it, giving the illusion of holes. Were it not for the constant spray sending ripples through the puddles, you'd believe the illusion.\n"
            "Looking up, you find that the source of the waterfall cannot be determined as the entire top half of the chamber is engulfed in darkness. You glance down towards the equally shrouded bottom of the chamber\n"
            "and try to imagine how deep it must be. You look around and find a nearby glowing mushroom growing on the wall near the entrance and pluck it right off. You hold the mushroom over the crevasse and let go.\n"
            "The light from the mushroom gradually fades as it falls into the abyss, confirming your suspicions that the canyon is, in fact, very deep. Deep enough that you'd be falling for some time before you inevitably die.\n"
            "You look back up across the bridge and spy a flickering orange light in the distance. Squinting, you think you see shadows move back and forth in front of the light. A bonfire, perhaps? If that's a bonfire, then the\n"
            "shadows must be people, right? Maybe they can help you find what you're looking for. You look back down to the bridge and weigh your options.\n"
            "Either you can risk crossing the bridge, which is not only barely wide enough for two people to walk across, but completely soaked, or you can simply try to get the attention of the figures on the other side of the chamber.\n";
    
    gc_left_tunnel();
}

void gc_left_tunnel(){
    // To be filled in...
};

void gc_right_tunnel(){
    // Large chamber full of bats - being quiet is necessary
    print_line();
}

void gc_pathway(){
    // Evidence of Worldwalkers - abandoned basket and/or cart in clearing - journal
    print_line();
}