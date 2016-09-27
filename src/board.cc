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

Board::Board(std::vector< std::vector<char> > board, std::vector<int> boats,
        std::vector<int> top_constr, std::vector<int> side_constr) :
    size(board.size()),
    top_constraints(top_constr),
    side_constraints(side_constr),
    board(board),
    boats(boats)
{}

} // namespace bimaru
