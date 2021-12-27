#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Items.hpp"
#include "Functions.hpp"


using namespace std;

int main(){
    char choice;
    vector<Items> items;

    cout << bleh();
    
    cout << "After wandering through the jungle for an immeasurable amount of time, you come across a strange temple.";
    cout << "The temple is constructed of what appears to be large brown stone blocks covered in thick vines and ivy.";
    cout << "A yawning dark doorway opens into the interior of the temple. A simple pedestal stands before you holding a bowl of fire.";
    cout << "\n\n";
    cout << "An engraving in the pedestal below the bowl of fire reads: Fire burns as the brightest light, give yourself to it and be given sight.";
    cout << "An ornate iron dagger lies in a small recess beneath the inscription.";
    cout << "Take the dagger? Y/N: ";
    cin >> choice;

    if(choice == 'Y' || choice == 'y')
    {
        cout << "You take the dagger out of the recess.";
        cout << "Upon closer inspection, you notice there are strange glyphs in the center of the blade.";
        cout << "The glyphs appear to be similar to the glyphs you saw on the stone ring in the basement of The House.";
        cout << "You slowly run your thumb over the strange symbols.";
        cout << "Suddenly, the glyphs glow a menacing red and you feel a sudden urge to cut your hand.";
        cout << "The urge steadily grows until you deftly slice open the palm of your left hand.";
        cout << "Complete surprise overtakes you for a moment as you process what you have just done until you suddenly and involuntarily thrust your hand over the bowl of fire\n and squeeze several drops of your own blood into the waiting flames below.";
        cout << "The bloods sizzles as it hits the hot coals and the fire astoundingly changes colors into a deep red before quickly reverting back.";
        cout << "Instantly, your eyes begin to burn as if they too were exposed to the flames. You drop the dagger as your hands shield your eyes and you scream in pain.";
        cout << "The pain is gone quickly however, and you slowly open your eyes again. Blinking slowly, the world falls back into focus as your eyes adjust to the light of day once again.";
        cout << "As far as you can tell, your eyes are completely fine and your visual acuity is the same as before.";
        cout << "Remarkably however, the cut on your left palm has sealed completely with no visible scars, as if it was never there.";
        cout << "You stand still for a while, flexing your hand and running your fingers over your smooth, unharmed palm.";
        cout << "\"Things could not get any weirder,\" you think to yourself.";
        cout << "Just then, a huge stone slab inset into the wall behind and to the left of the pedestal slides up, followed by another on the right side.";

    }
    else
    {

    }

    return 0;
}
