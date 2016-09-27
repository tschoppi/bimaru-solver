#include "board.h"
#include "gtest/gtest.h"


TEST(BoardClass, Initialisation) {
    int size = 5;
    std::vector<int> top_constr = {0, 0, 0, 0, 0};
    std::vector<int> side_constr = top_constr;
    std::vector<int> boats = {4, 3, 4};
    auto * myBoard = new bimaru::Board(size, boats, top_constr, side_constr);
    EXPECT_TRUE(myBoard != NULL);
    delete myBoard;

    std::vector< std::vector<char> > board = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    myBoard = new bimaru::Board(board, boats, top_constr, side_constr);
    EXPECT_TRUE(myBoard != NULL);
    delete myBoard;
}

