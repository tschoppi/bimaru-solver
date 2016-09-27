#ifndef BIMARU_BOARD_H_
#define BIMARU_BOARD_H_

// The Board class stores the board state, meaning:
//  - Boats that are placed
//  - Boats that still need to be placed
//  - Original edge constraints
//  - Local (temporary) edge constraints
//
// In order to fulfill this, the board is represented as a nxn vector, where n
// is the size of the edge of the board. This vector is filled with characters
// that indicate the state of a field: One of the boat characters (A, H, V, <,
// =, >, O) or the character to indicate a forbidden field (X).

#include <vector>

namespace bimaru {

class Board {
  private:
    int size;
    std::vector<int> top_constraints;
    std::vector<int> side_constraints;
    std::vector< std::vector<char> > board;
    std::vector<int> boats;

  public:
    // Constructor for first board, which initialises an empty board
    Board(const int size, const std::vector<int> boat_lengths, 
            const std::vector<int> top_constr, 
            const std::vector<int> side_constr);
    // Constructor from a known board and outstanding boats
    Board(std::vector< std::vector<char> > board, std::vector<int> boats,
            std::vector<int> top_constr, std::vector<int> side_constr);
    
};

} // namespace bimaru

#endif // BIMARU_BOARD_H_
