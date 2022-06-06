#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

/**
* creature object is what is moved throughout the maze
*
* variable Row holds the current row the creature is at
* variable Col holds the current column the creature is at
*/
class Creature {
public:
/**
* prints current location of creature into Out
*
* @pre Creature object must be initialized with a row and a column
* @post doesn't change any variables
* @param Out is filled with the current row and column of the creature
* @param Creaature object is used to get it's current row and column
* @return Returns Out
*/
friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
int Row;
int Col;

/**
* move creature to a new location
*
* In order of North, West, South, East, will check if given direction is
* clear. Will move in the first given direction that is clear. Will add a
* letter (N,W,S,E) to the Path variable if creature moves in that given
* direction.
*
* @pre Maze must of been created and Path string must have been created
* @post If creature moves in any of the 4 directions then a '*' will be
* added to that location on the maze where the creature moved to.
* @param Path will have a letter (N,W,S,E) added to it if creature moves
* in that given direction.
* @param Maze object is used to check if creature can move in a given
* direction.
* @return True if creature was able to move to new location or false if
* creature was not able to move to new location.
*/
bool moveForward(std::string &Path, Maze &Maze);

/**
* backtrack, check last letter on Path then go opposite way
*
* Uses branches to check last character of Path. Branch order is N (north),
* W (west), S(south), and else (east). Creature is moved in opposite
* direction of Path's last character. The last character of Path is removed.
*
* @pre Creature must have already moved forward in some direction
* @post The starting location of the creature will have a '+' written on.
* The creature will have moved in the opposite direction of the last
* character in Path. Path will have the last character removed.
* @param Path is used as a stack. Used to know which way to backtrack and
* has last character removed.
* @return void
*/
void backtrack(std::string &Path);

/**
* checks if creature is at the exit
*
* If creature's Row and Col matches Maze's ExitRow and ExitColumn then true
* is returned, else false is returned.
*
* @pre creature and maze must be created
* @post const
* @param Maze used to get ExitRow and ExitColumn.
* @return True if creature location matches exit location, else return false
*/
bool atExit(const Maze &Maze) const;

/**
* moves creature north
*
* Creature's Row is subtracted by 1.
*
* @pre creature and maze must be created
* @post Creature's Row is subtracted by 1.
* @return void
*/
void goNorth();

/**
* moves creature west
*
* Creature's Col is subtracted by 1.
*
* @pre creature and maze must be created
* @post Creature's Col is subtracted by 1.
* @return void
*/
void goWest();

/**
* moves creature south
*
* Creature's Row is added by 1.
*
* @pre creature and maze must be created
* @post Creature's Row is added by 1.
* @return void
*/
void goSouth();

/**
* moves creature east
*
* Creature's Col is added by 1.
*
* @pre creature and maze must be created
* @post Creature's Col is added by 1.
* @return void
*/
void goEast();

public:
/**
* constructor
*
* @pre nothing needs to be done before using this
* @post creature object will have a row and colomn
* @param Row used to set object's Row
* @param Col used to set object's Col
*/
Creature(int Row, int Col);

/**
* has creature solve maze
*
* Uses Maze's markAsPath method, Creatur's atExit method, Creature's
* moveForward method, Maze's markAsVisited method, and Creature's
* backtrack method to have the creature solve the maze.
*
* @pre Maze and Creature must have been created with Creature starting in
* a location that is not a wall ('x') and has a route to the exit
* @post Maze will be marked up with '+'s and '*' indicating visited and
* path locations, repectively.
* @param Maze
* @return a string in the form of NNEEN of the path out of the maze
* (where N means North, E means East, etc)
*/
string solve(Maze *Maze);
};

#endif // ASS3_CREATURE_H