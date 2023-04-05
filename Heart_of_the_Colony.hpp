// Header file for Heart_of_the_Colony.cpp
#ifndef HEART_OF_THE_COLONY_HPP
#define HEART_OF_THE_COLONY_HPP

#include <string>

using namespace std;

extern bool hotc_explored_left_tunnel;
extern bool hotc_explored_middle_tunnel;
extern bool hotc_explored_right_tunnel;
extern bool hotc_found_hint;
extern bool hotc_heard_history;
extern bool hotc_read_book;
extern bool hotc_ask_orb;

extern void the_heart_of_the_colony_text();
extern void the_heart_of_the_colony();
extern void hotc_explore_nest_text();
extern void hotc_explore_nest();
extern void hotc_archives_text();
extern void hotc_archives();
extern void hotc_tunnel_options();
extern void the_queens_chambers();


#endif