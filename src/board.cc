// Implementation for the Board class

#include <board.h>

namespace bimaru {

Board::Board(const int size, std::vector<int> boat_lengths, 
    std::vector<int> top_constr, std::vector<int> side_constr) :
  size(size),
  top_constraints(top_constr),
  side_constraints(side_constr),
  boats(boat_lengths)
{
  board.reserve(size);
}

Board::Board(std::vector< std::vector<char> > board, 
    const std::vector<int> boats, const std::vector<int> top_constr, 
    const std::vector<int> side_constr) :
  size(board.size()),
  top_constraints(top_constr),
  side_constraints(side_constr),
  board(board),
  boats(boats)
{}

// isSolved() checks that all constraints are 0, and that no boats are left
// outstanding, because these are the only two conditions that need to be
// fulfilled (boat placement legality is covered during boat placement).
bool Board::isSolved() {
  for(unsigned int i = 0; i < top_constraints.size(); i++) {
    if(top_constraints[i] != 0) return false;
    if(side_constraints[i] != 0) return false;
  }
  return boats.empty();
}

} // namespace bimaru
