#ifndef HEADER_H
#define HEADER_H


#include <string>

using namespace std;


//enum for the colour of the Chesspieces
enum piece_colour{Black, White};


/*separate function declarations*/

/*function to output the colour of a piece*/
string output_colour(piece_colour colour);

/*function to return the oppositie colour*/
piece_colour opp_colour(piece_colour colour);


#endif
