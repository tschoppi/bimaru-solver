#ifndef BIMARU_BOARD_H_
#define BIMARU_BOARD_H_

// The Board class stores the local board state, meaning:
//  - Boats that still need to be placed
//  - Local (temporary) edge constraints
//
// In order to fulfill this, the board is represented as a nxn vector, where n
// is the size of the edge of the board. This vector is filled with characters
// that indicate the state of a field: One of the boat characters (A, H, V, <,
// =, >, O) or the character to indicate a forbidden field (X).
// The constraints are used for column selection when trying to place a new
// boat.

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
      const std::vector<int> top_constr, const std::vector<int> side_constr);
  // Constructor from a known board and outstanding boats
  Board(std::vector< std::vector<char> > board, const std::vector<int> boats,
      const std::vector<int> top_constr, const std::vector<int> side_constr);

  // Accessors
  int getSize() {return size;}
  std::vector<int> getTopConstraints() {return top_constraints;}
  std::vector<int> getSideConstraints() {return side_constraints;}
  
  // Queries
  bool isSolved();
};

} // namespace bimaru

#endif // BIMARU_BOARD_H_
