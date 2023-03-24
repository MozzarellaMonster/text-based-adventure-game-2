// File containing functions for The Whistling Gorge passage
#include<iostream>
#include<string>
#include"The Whistling Gorge.hpp"
#include"Functions.hpp"
#include"Trackers.hpp"
#include"Items.hpp"

using namespace std;

bool explored_left_path;
bool explored_right_path;
bool looked_around;

bool denied_fruit;

void the_whistling_gorge_text()
{
    print_line();
    cout << "You stumble through the Gate, barely managing to regain your balance to avoid face planting in the chalky white dust.\n"
            "Standing upright, you find yourself in a large canyon with looming rock faces on either side of you.\n"
            "You look back to see a large similarly carved Gate set into the rock face behind you.\n"
            "However, this one is clearly inactive as nothing but black stone greets you between either pillar of the Gate."
            "You turn back around and see what looks like a small forest a few hundred meters away from you.\n"
            "With no other option in the dead end of the canyon you find yourself in, you walk forward.\n"
            "As you approach the forest, you soon realize that seemingly every tree within it is dead.\n"
            "Their gnarled, twisted branches reach toward the calm blue sky like withering fingers from a grave.\n"
            "Wandering through the thicket, you notice several trees have lines of holes scattered along the length of their trunks.\n"
            "Like the holes along the length of a flute. You stop and stare at one series close to you before you feel the breeze pick up\n"
            "and you hear a somber whistling tone all around you…\n\n"
            "                                                       *****                                                                   \n"
            "You shake yourself from your stupor, regaining control of your limbs. It is then you notice your fingernails caked with the\n"
            "chalky white dust, and you look down to see you are crouched in front of a small hole in the ground where you had been digging.\n"
            "You stand back up, shaking the dust free from your hands. The breeze is noticeably gone, and the somber whistle nowhere to be heard.\n"
            "You don't know why you were digging, but you're sure it wasn't for a good reason, as a creeping dread crawls slowly up your spine.\n"
            "Something tells you it would be in your best interest to not hear the whistling woods again.\n"
            "Walking forward, you soon come upon a split in the path. There are two options: the path on the left goes up a hill,\n"
            "the path on the right goes further into the forest.\n";
    print_line();

    the_whistling_gorge();
}

void the_whistling_gorge()
{
    char choice;
    print_line();
    cout << "What would you like to do?\n";
    cout << "A. Take the path on the left";
    cout << "B. Take the path on the right";
    cout << "C. Look around where you are";
    cout << "D. Go back";
    print_line();
    cin >> choice;

    if (choice == 'A' || choice == 'a')
    {
        print_line();
        cout << "You decide to take the path on the left. You walk forward and come to a small hill, where there is another dead tree\n"
                "planted on the very crest of the hill. This tree however, bears fruit. Small, shriveled berries grow in clusters along\n"
                "several of the branches. Some of which are within reach.\n\n";
        // To be filled in...
    }
}