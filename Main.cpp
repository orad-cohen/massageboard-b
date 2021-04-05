#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
ariel::Board board;
board.post(42,78,Direction::Horizontal,"Lost cat");
board.post(47,68,Direction::Horizontal,"Help Wanted");
cout<< board.read(42,75,Direction::Horizontal,7)<< endl;
cout<< board.read(42,78,Direction::Vertical,10)<< endl;
board.post(41,76,Direction::Vertical,"Party time");
board.post(43,71,Direction::Vertical,"Wazzap");
board.show(); // shows the board in a reasonable wa                    y. For example:

}
