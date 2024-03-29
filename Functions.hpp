//Header file for Functions.cpp
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include<vector>

using namespace std;

extern vector<string> inventory;
extern vector<string> journals;
extern vector<string> obslots;

extern void print_line();
extern void try_again();
extern void reset();
extern void retry();
extern void retry(void (*func)());
extern void retry(void (*func)(bool), bool show_interlude);
extern void archway(string message, string name, bool *archway_read, void (*func)());
extern void deposit();
extern void determine_riddle();
extern void start();
extern void show_inventory();
extern void interlude();
extern void clear_screen();

extern void first_choice();
extern void temple_entrance();

extern void temple_first_room_text();
extern void temple_first_room();

extern void temple_second_room_text();
extern void temple_second_room(bool from_world);

extern void the_desert_of_the_dead_text();
extern void the_desert_of_the_dead();

#endif