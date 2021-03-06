// File to keep track of player's progress in main story.
#include "Trackers.hpp"
#include <string>

using namespace std;

string water_riddle = "\tUnhindered, I can destroy cities, yet tamed I supply them. I carve the very Earth, yet flesh does not yield.\n"
                      "\tI reign over the many kingdoms of man, for I have seen them all. For millennia you have tried to control me,\n"
                      "\tto confine me, yet you are the greatest prisoner, for you cannot live without me.\"";

string wind_riddle = "\tI roam the world, wild and free. Sailors and storms both rely on me.\n"
                     "\tI can caress your skin and steal your breath away. Or I can tear your home apart and throw you away.\"";

string fire_riddle = "\tA force to be reckoned with, it was I that gave man the power they possess. I am protection, I am light, but I have no loyalties.\n"
                     "\tI devour fiercely, but have no thirst, for if I drink I will die.\"";

string correct_riddle = "You walk up to the wall with the same symbol and gently touch it.\n"
                        "At first, nothing happens. Then, there's a low rumbling sound as the wall slowly slides up into the ceiling.\n"
                        "You slowly approach and look into the room beyond. Or at least you try to, but it's so dark that not even the burning flame is able to cast much light.\n"
                        "Cautiously, you take a single step into the room and suddenly several bowls ignite around the perimeter of the much larger room, bathing the room in a warm glow.\n"
                        "It is then you hear a voice in your head:\n\"Well done\".\n";
string current_riddle;

string shimmer = "The same opaque liquid shimmer that you saw in the ring of the machine in The House is faintly visible in the dark opening.\n"
                "Though this particular one is much larger, encompassing the entire entrance of the archway with an oily appearance.\n"
                "The shimmer also appears less active, like an undisturbed lake of water.\n";

int jungle_repeat = 0;

// First room
int set_riddle;
bool first_room_explored = false;
bool second_room_obelisk_complete = false;

// Second room trials
bool first_archway_read = false;
bool second_archway_read = false;
bool third_archway_read = false;
bool fourth_archway_read = false;
bool fifth_archway_read = false;
bool sixth_archway_read = false;
bool seventh_archway_read = false;
bool saw_archway = false;

// Desert of the Dead
bool dod_explored_room = false;
bool dod_looked_outside = false;
bool dod_investigated_platform = false;
bool dod_sandstorm = false;
bool dod_used_dagger = false;