// File to keep track of player's progress in main story.
#include "Trackers.hpp"
#include <string>

using namespace std;

string water_riddle = "\t\"Unleashed, I ravage cities grand, yet harnessed, I nourish the land.\n"
                      "\tI carve the earth with gentle might, defying flesh, both day and night.\n"
                      "\tFrom realms of rain to ocean deep, I reign over man, a secret to keep.\"";

string wind_riddle = "\t\"I wander wild across the earth's expanse, a zephyr's dance, a tempest's trance.\n"
                     "\tCarrying whispers, sowing seeds, I roam unbounded, meeting no needs.\n"
                     "\tCaressing cheeks, stealing breath away, or razing homes in a furious display.\"";

string fire_riddle = "\t\"A force of power, the light I bestow, an ember's glow, a flickering show.\n"
                     "\tI am warmth and light, a guardian true, yet loyalties, I have none for you.\n"
                     "\tI consume with might, but thirst not within, lest I drink, and all shall end and thin.\"";

string correct_riddle = "You walk up to the wall with the same symbol and gently touch it.\n"
                        "At first, nothing happens. Then, there's a low rumbling sound as the wall slowly slides up into the ceiling.\n"
                        "You slowly approach and look into the room beyond. Or at least you try to, but it's so dark that not even the burning flame is able to cast much light.\n"
                        "Cautiously, you take a single step into the room and suddenly several bowls ignite around the perimeter of the much larger room, bathing the room in a warm glow.\n"
                        "It is then you hear a voice in your head:\n\"Well done\".\n";
string current_riddle;

string shimmer = "The same opaque liquid shimmer that you saw in the machine in the basement of The House is faintly visible in the dark opening.\n"
                "Though this particular one is much larger, encompassing the entire entrance of the archway with an oily appearance.\n"
                "The shimmer also appears less active, like an undisturbed lake of water.\n";

string completed_world = "You look to the now-sealed archway, unable to pass through. You return to the center of the room.\n\n";

int jungle_repeat = 0;

// First room
int set_riddle;
bool first_room_explored = false;

// Second room trials
bool must_deposit = true;
bool second_room_obelisk_complete = false;
bool first_archway_read = false;
bool second_archway_read = false;
bool third_archway_read = false;
bool fourth_archway_read = false;
bool fifth_archway_read = false;
bool sixth_archway_read = false;
bool seventh_archway_read = false;
bool saw_archway = false;

bool dod_completed = false;
bool hotc_completed = false;
bool tgc_completed = false;
bool oasis_completed = false;
bool twg_completed = false;
bool tsl_completed = false;
