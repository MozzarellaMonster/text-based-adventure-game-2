// Header file for Trackers.cpp
#ifndef TRACKERS_HPP
#define TRACKERS_HPP
#include <string>

using namespace std;

extern string water_riddle;
extern string wind_riddle;
extern string fire_riddle;
extern string correct_riddle;
extern string current_riddle;

extern string shimmer;
extern string completed_world;

extern int jungle_repeat;
extern int set_riddle;
extern bool first_room_explored;
extern bool second_room_obelisk_complete;

extern bool first_archway_read;
extern bool second_archway_read;
extern bool third_archway_read;
extern bool fourth_archway_read;
extern bool fifth_archway_read;
extern bool sixth_archway_read;
extern bool seventh_archway_read;
extern bool saw_archway;

bool dod_completed;
bool hotc_completed;
bool tgc_completed;
bool oasis_completed;
bool twg_completed;
bool tsl_completed;

extern bool dod_explored_room;
extern bool dod_looked_outside;
extern bool dod_investigated_platform;
extern bool dod_sandstorm;
extern bool dod_used_dagger;

#endif