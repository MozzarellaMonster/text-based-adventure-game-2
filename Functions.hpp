//Header file for Functions.cpp
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include<vector>

using namespace std;

extern void print_line();
extern void try_again();
extern void reset();
extern void retry();
extern void retry(void (*func)());
extern void present_options(vector<string> option_names, vector<string> dialogue, void (*func)());
extern void archway(string message, string name, bool archway_read, void (*func)());
extern void deposit(string key);
extern void determine_riddle();
extern bool inv_contains(string object);
extern void start();

extern void first_choice();
extern void temple_entrance();

extern void temple_first_room_text();
extern void temple_first_room();

extern void temple_second_room_text();
extern void temple_second_room();

extern void the_desert_of_the_dead_text();
extern void the_desert_of_the_dead();

extern void the_heart_of_the_colony_text();
extern void the_heart_of_the_colony();

extern void the_garden();
extern void the_whistling_gorge();
extern void the_silken_throne();
extern void the_labyrinth();

#endif