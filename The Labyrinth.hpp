// Header file for The Labyrinth passage
#ifndef THE_LABYRINTH_HPP
#define THE_LABYRINTH_HPP

#include <string>

using namespace std;

extern bool timer_done;

extern int saved_index;

extern string object;
extern string saved_object;
extern string time_remaining;
extern string first_puzzle_death;
extern string door_1_riddle;
extern string door_2_riddle;
extern string door_3_riddle;

extern void timer(int time);
extern int fight(string monster, int str_len, int difficulty);
extern void remove_from_inventory(string puzzle, bool recursing);
extern void add_to_inventory();
extern void the_labyrinth_text();
extern void first_puzzle();
extern void second_puzzle();
extern void third_puzzle();
extern void fourth_puzzle();
extern void fifth_puzzle();
extern void sixth_puzzle();
extern void underwater_scene();

#endif