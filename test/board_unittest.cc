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

class BoardTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    size = 4;
    my_constraints = {0, 0, 0, 0};
    std::vector<int> boats = {4, 3, 4};
    myBoard = new bimaru::Board(size, boats, my_constraints, my_constraints);
    emptyBoard = new bimaru::Board(size, std::vector<int>({}), my_constraints, my_constraints);
  }

  int size;
  bimaru::Board * myBoard;
  bimaru::Board * emptyBoard;
  std::vector<int> my_constraints;

  virtual void TearDown() {
    delete myBoard;
    delete emptyBoard;
  }
};

TEST_F(BoardTest, Accessors) {
  EXPECT_EQ(myBoard->getSize(), size);
  EXPECT_EQ(myBoard->getTopConstraints(), my_constraints);
  EXPECT_EQ(myBoard->getSideConstraints(), my_constraints);
}

TEST_F(BoardTest, Queries) {
  EXPECT_FALSE(myBoard->isSolved());
  EXPECT_TRUE(emptyBoard->isSolved());
}
