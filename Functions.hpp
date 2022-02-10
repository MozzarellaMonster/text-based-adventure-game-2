//Header file for Functions.cpp
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

using namespace std;

extern void try_again();
extern void retry();
extern void retry(void *func);
extern void shimmer();
extern void archway(string message, string name, bool archway_read, void (*func)());
extern void determine_riddle();
extern void start();
extern void first_choice();
extern void temple_entrance();
extern void temple_first_room_text();
extern void temple_first_room();
extern void temple_second_room_text();
extern void temple_second_room();
extern void the_room_of_the_dead();
extern void the_heart_of_the_colony();

#endif