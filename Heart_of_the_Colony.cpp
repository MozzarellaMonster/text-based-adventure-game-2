// File containing functions for The Heart of the Colony passage
#include <iostream>
#include <string>
#include "Heart_of_the_Colony.hpp"
#include "Functions.hpp"
#include "Items.hpp"
#include "Trackers.hpp"

using namespace std;

bool hotc_explored_left_tunnel = false;
bool hotc_explored_middle_tunnel = false;
bool hotc_explored_right_tunnel = false;

void the_queens_chambers(){
    cout << "Eventually, the tunnel opens up into a large chamber where you spy a distinct silhouette facing away from you: the Ant Queen.\n"
            "Not completely unexpected, you think to yourself.\n"
            "\"No, I suppose it is not, human.\", you suddenly hear in your head.\n"
            "Your eyes widen at the intrusion of the distinctly feminine voice within your thoughts.\n"
            "\"But your sudden unannounced appearance before my Court is. Now, state your reason for visiting.\"\n"
            "The huge ant queen turns to face you, looking down upon you with a terrible intelligence in its multifaceted eyes.\n"
            "You stare, dumbstruck for a moment. Then, regaining your composure, you speak back at it with your thoughts.\n"
            "\"I apologize. I only wish to travel back to my world, and I must find a token here to do so.\", you think.\n"
            "\"I see. You are but another contestant for the game of the Worldwalkers. Unfortunately for you, not even I am aware of the location of your token.\"\n"
            "The Ant Queen turns back away from you. \"You are free to look, but should you attempt to bring harm upon any of my subjects or overstay your welcome,\"\n"
            "The Ant Queen looks back at you, \"I will feed you to them.\"\n"
            "A cold shiver runs down your spine, and you quickly nod in acknowledgement.\n"
            "\"Now, leave my chambers and hasten your search, for my patience is limited.\"\n"
            "You get up quickly and leave, noticing the ants around you have stopped escorting you.\n";

    hotc_explore_nest_text();
}

void hotc_explore_nest_text(){
    print_line();
    cout << "You are now free to explore the ant nest as you please, however keep in mind the warnings the Ant Queen gave you:\n"
            "\n\t\"[S]hould you attempt to to bring harm upon any of my subjects or overstay your welcome, I will feed you to them.\"\n\n"
            "You shiver slightly from the memory, but clear your head and focus on the matter at hand. You need to explore the nest and find\n"
            "the token you will need before you can return to the temple.\n"
            "From where you stand, you can see three different tunnels before you that lead away from the Queen's Chambers.\n"
            "First, there is the middle tunnel where you were first found but never found out what was at the other end, then there is the\n"
            "two tunnels to the left and right that remain unexplored.\n";
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
        if(hotc_explored_left_tunnel){
            cout << "You look back to the tunnel that leads to the egg room, and shake your head.\n"
                    "You did not find the token there, it would be unlikely to be there now.\n"
                    "You look back to the options before you.\n";
            hotc_explore_nest();
        }
        else{
            cout << "You decide to explore the left tunnel.\n"
                    "You go down the left tunnel for some distance before it opens into a large open cavernous space with several large pillars.\n"
                    "Along the walls and floor of the room are several oblong pill-shaped objects with distinct silhouettes wriggling around inside of them.\n"
                    "\"Eggs,\" you think to yourself before hesitantly crossing the threshold into the room. The room is lit with several organic-looking lanterns embedded in the ceiling,\n"
                    "providing a warm glow to the entirety of the large space. Several female worker ants are milling about, tending to the different egg clusters and largely ignoring you.\n"
                    "However, if you get a little too close to any one egg, a distinct hiss is heard from any that are nearby. You make haste and search the room without setting off the worker ant's aggression.\n"
                    "Unfortunately, you could find nothing of importance in the room and head back through the tunnel to the Queen's Chambers.\n";
            hotc_explored_left_tunnel = true;
            hotc_explore_nest();
        }   
    }
    else if(choice == 'B' || choice == 'b'){
        print_line();
        if(hotc_explored_middle_tunnel){
            cout << "You look back towards the middle tunnel, remembering how it leads back to the colony's food storage chamber.\n"
                    "There was nothing of note in there. You look back to the other tunnels.\n";
            hotc_explore_nest();
        }
        else{
            cout << "You decide to explore the middle tunnel.\n"
                    "You go down the middle tunnel for quite a distance before eventually you find yourself in a large circular room with a high ceiling.\n"
                    "The room is lit with organic-looking lanterns hung in even distances along the circumference of the room. In the middle of the room stands a\n"
                    "large spire of various objects. It takes you a moment before you realize that this room contains all of the colony's collected food. Large, seed-like\n"
                    "objects are collected in a huge mound and stacked carefully in the center of the room. Surprisingly, there are nearly no ants at all in this room\n"
                    "and you are free to explore to your heart's content. You make sure not to disturb the giant spire though, as moving one thing out of place may just cause\n"
                    "the whole thing to collapse. After searching for some time, you decide the room does not contain what you are looking for and leave, trekking back through\n"
                    "the tunnel to the Queen's Chambers.\n";
            hotc_explored_middle_tunnel = true;
            hotc_explore_nest();
        }
    }
    else if(choice == 'C' || choice == 'c'){
        print_line();
        if(hotc_explored_right_tunnel){
            cout << "You look down the right tunnel, where the history of the colony was written on the walls of a large chamber.\n"
                    "It was an otherwise empty room. You look back towards the other tunnels.\n";
            hotc_explore_nest();
        }
        else{
            cout << "You decide to explore the right tunnel.\n"
                    "After walking for several minutes, you arrive at a large room covered in hieroglyphics.\n"
                    "Taking a closer look at some of the nearby glyphs, from what can be gathered, they appear\n"
                    "to tell the history of the \"Worldwalkers\" and the ants of this colony. Several of the hieroglyphs\n"
                    "are also written in areas unreachable to you. Looking up at the ceiling, you see that the ants didn't\n"
                    "waste any area, as even the ceiling is covered. You can't see what the story is told from those, but you\n"
                    "can imagine it tells the story of the colony, starting from the first generation and probably the first Queen.\n"
                    "Following the curve of the hieroglyphs, it appears the circle the room in a spiral, coming down from the center\n"
                    "of the ceiling, to near your head height.\n"
                    "You would search the room, but there is no need to, since the only purpose\n"
                    "the room seems to serve is as a record of the history of the colony, it lays purposefully empty.\n"
                    "After giving one final look around the room, you head back down the tunnel.\n";
            hotc_explored_right_tunnel = true;
            hotc_explore_nest();
        }

    }
    else if(choice == 'D' || choice == 'd'){
        print_line();
        cout << "You decide to explore the Queen's Chambers.\n"
                "The ants that escorted you down the tunnel have now left the chamber, leaving you alone with the Queen, her guards, and one other ant.\n"
                "The guards stare you down as the Queen busily attends to what appears to be a map of the nest and converses with the other ant.\n"
                "Looking about the room, you notice something strange. There appears to be a pile of what appears to be junk in one corner of the room.\n"
                "You approach it and look through the rubble. Soon, you come across what appears to be a broken piece of amber with a strange claw embedded within.\n"
                "\"Take it,\" you hear in your head. You lift the large piece of amber out of the rubble and tuck it under your arm. Almost immediately, a portal opens up.\n"
                "\"WHAT ARE YOU DOING?!\" a voice booms in your head. \"DO NOT TOUCH THOSE.\" Your head spins around to see the guards closing in on you and the\n"
                "glaring angrily at you. \"MY CONQUEST ITEMS ARE NOT FOR YOU TO TAKE!\" Quickly, you make a mad dash for the open portal and narrowly dodge multiple ants\n"
                "that attempt to stop you, even stepping on one to avoid two others.\n"
                "You leap into the portal but not before the Queen lets out one last enraged shriek in your head. You close your eyes against the pain and tumble out onto the floor of the temple.\n"
                "A cold breeze embraces you as you open your eyes and pick yourself up. A mild throbbing in your cranium soon follows as you stagger slightly but quickly right yourself and proceed\n"
                "to put the amber piece in the stone obelisk. That's another one down. You turn back to the archways.\n\n";
        temple_second_room();
    }
    else{
        try_again();
        hotc_explore_nest();
    }
}

void hotc_tunnel_options(){
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Run away\n";
    cout << "B. Surrender\n";
    cout << "C. Fight\n";
    print_line();
    cin >> choice;

    if(choice == 'a' || choice == 'A'){
        print_line();
        cout << "Quickly, while the ant's attention is away from you, you sprint down the tunnel in the other direction.\n"
                "Immediately, the ants turn around and give chase, chittering loudly all the while. You take a quick look back\n"
                "to see them closing the distance. You try to pick up speed but only succeed in tripping, allowing the ants to catch up to you quickly.\n"
                "You scramble to get back up, but one of the ants steps on your back, putting its full weight on you and pinning you to the ground. Another ant makes\n"
                "its way to the front of you and looks down on you. Without warning, it clamps its large jaws over your cranium. Blood quickly begins to pour where the\n"
                "ant has made contact with your temples and you can feel the pressure increasing as the ant clamps down harder and harder. You pull hard against the jaws\n"
                "of the insect, trying to unclamp them, but they remain in place like a steel vice. It then dawns on you this is how you die - foolishly. Your eyes go wide\n"
                "when you hear a sickening crunch as your skull gives way, then all is black.\n";

        cout << "\n\nEnding 8: Migraine";
        print_line();
        retry(&hotc_tunnel_options);
    }
    else if(choice == 'b' || choice == 'B'){
        print_line();
        cout << "You decide just to surrender to the giant ants. You slowly walk out of the impression in the wall\n"
                "with your hands up, showing your defenseless state. The ants quickly turn toward you, surround you,\n"
                "and then herd you down the tunnel, all the while snapping at your legs with their huge mandibles if\n"
                "you so much as slow down.\n";
        
        the_queens_chambers();
    }
    else if(choice == 'c' || choice == 'C'){
        print_line();
        cout << "You decide to fight. You jump out brandishing the dagger and lunge at the first ant you see.\n"
                "Quickly bringing the dagger down on the back of the ant, you put all your strength into making it a killing blow.\n"
                "The dagger pierces the chitin and stabs the ant, bringing it down. It slumps to the ground, but does not appear dead.\n"
                "The other two ants immediately lunge toward you, angered and ready to kill. The giant insects manuever around you, one on each side, surrounding you.\n"
                "You focus quickly shifts from one to the other and you make striking motions with the dagger to keep them at bay. One ant lunges at your legs, jaws snapping.\n"
                "You turn towards it to fend it off. However, in doing so you have made yourself vulnerable to the other ant. Realizing your mistake you quickly try to\n"
                "turn back around to fend off the other ant but end up losing your balance and tripping over the first ant to attack, which has now locked its jaws around into your leg.\n"
                "You fall flat on your back with your left leg held aloft by the first biting ant. You look over at it, trying to pull out of its jaws, but it only locks in tighter.\n"
                "It then quickly rips its mandibles along the length of your leg, tearing through your sensitive flesh. Pain shoots through your leg as you look down at your now mangled limb.\n"
                "You scream, before a shadow covers your face and you realize the second ant is now standing over you. You quickly try to stab it with the dagger, but it catches your arm\n"
                "and pulls hard. Searing pain tears through your arm as you feel your soft flesh rip apart from the strong jaws. You drop the dagger and scream again. The ants have no mercy\n"
                "for a hostile intruder, however. The second ant grabs your arm again near the shoulder, bites down hard until you feel its mandibles scrape your bone and pulls. A sickening tearing sound\n"
                "can be heard as your arm is torn from its socket. Screams are no longer sufficient in portraying the hellish pain you are in. Tears flow freely from your eyes and you sob loudly as you realize\n"
                "what a terrible mistake you've made. Their task is not over, however. As the first ant moves over your body and grabs your lower jaw with its own and easily yanks it free from your skull.\n"
                "Blood fills your throat as the pain becomes unbearable. You stare at the tunnel ceiling, past the gaze of the ant still looking down at you with your jaw in its own as blood drips from it\n"
                "into your face. The other ant then enters your view and moves closer, its antennae moving over your destroyed visage. You can do nothing except let it happen.\n"
                "Eventually, the ant stops and works together with the other to drag what's left of you down the tunnel. Slowly, your vision fades as you watch the tunnel ceiling pass by and you realize you've lost a lot of blood.\n"
                "One thought strikes you as funny before you eventually die: that you decided to fight an enemy that you knew nothing about and that clearly outnumbered you.\n";

        cout << "\n\nEnding 9: Belligerence";
        print_line();
        retry(&hotc_tunnel_options);
    }
    else{
        try_again();
        hotc_tunnel_options();
    }
}
