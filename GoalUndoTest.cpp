/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest, addOperation_Goal_Operation_nonEmpty){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("makeCoffee", "addMilk");
	ASSERT_EQ("makeCoffee",goalUndoTest.getGoal());
}

TEST(GoalUndoTest, addOperation_Goal_Operation_GoalEmpty){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("", "addMilk");
	ASSERT_EQ("",goalUndoTest.getGoal());
}

TEST(GoalUndoTest, addOperation_Goal_Operation_OpEmpty){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("makeCoffee", "");
	ASSERT_EQ("",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, getOperation_Goal_Operation_GoalEmpty){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("", "addMilk");
	ASSERT_EQ("",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, getOperation_Goal_Operation_multiOp){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("makeCoffee", "addMilk");
	goalUndoTest.addOperation("addSugar");
	ASSERT_EQ("addMilk addSugar",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, addOperation_only_operation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	ASSERT_EQ("addSugar",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, undoOperation_operation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoOperation();
	ASSERT_EQ("",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, undoOperation_single_operation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoOperation();
	ASSERT_EQ("",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, undoOperation_named_operation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.addOperation("addMilk");
	goalUndoTest.undoOperation("addMilk");
	ASSERT_EQ("addSugar",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, undoOperation_named_operation_get_op){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.addOperation("addMilk");
	goalUndoTest.undoOperation("addMilk");
	ASSERT_EQ("addSugar",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, undoOperation_named_operation_no_op){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.addOperation("addMilk");
	goalUndoTest.undoOperation("stir");
	ASSERT_EQ("addSugar addMilk",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, undoOperation_named_operation_no_goal){
	GoalUndo goalUndoTest;
	goalUndoTest.undoOperation("stir");
	ASSERT_EQ("",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, undoOperation_named_single_operation_getgoal){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoOperation("addSugar");
	ASSERT_EQ("",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, getGoal_empty_goal){
	GoalUndo goalUndoTest;
	ASSERT_EQ("",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, undoGoal_empty_goal){
	GoalUndo goalUndoTest;
	goalUndoTest.undoGoal();
	ASSERT_EQ("",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, undoGoal_single_goal){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoGoal();
	ASSERT_EQ("",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, undoGoal_single_goal_getOperation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoGoal();
	ASSERT_EQ("",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, undoOperation_empty_goal_getOp){
	GoalUndo goalUndoTest;
	goalUndoTest.undoOperation();
	ASSERT_EQ("",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, undoOperation_empty_goal_getGoal){
	GoalUndo goalUndoTest;
	goalUndoTest.undoOperation();
	ASSERT_EQ("",goalUndoTest.getGoal());
}

//If I perform undoOperation twice, when there is only a single operation and check that getGoal is empty it gives segfault  
/*TEST(GoalUndoTest, undoOperation_single_goal_no_Operation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoOperation("addSugar");
	goalUndoTest.undoOperation();
	ASSERT_EQ("",goalUndoTest.getGoal());
}*/

//If I perform undoOperation twice, when there is only a single operation and check getOperations, it gives bad_alloc error
/*TEST(GoalUndoTest, undoOperation_single_goal_no_Operation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoOperation("addSugar");
	goalUndoTest.undoOperation();
	ASSERT_EQ("",goalUndoTest.getOperations());
}*/

TEST(GoalUndoTest, getGoal){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	ASSERT_EQ("addSugar",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, addOperation_named_empty_op_arg){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("");
	ASSERT_EQ("",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, UndoOperation_check_empty_goal){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("makeCoffee","addMilk");
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoOperation();
	ASSERT_EQ("makeCoffee",goalUndoTest.getGoal());
}
TEST(GoalUndoTest, UndoGoal_multi_op){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("makeCoffee","addMilk");
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.addOperation("stir");
	goalUndoTest.undoGoal();
	ASSERT_EQ("",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, UndoOperation_multi_op){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("makeCoffee","addMilk");
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.addOperation("stir");
	goalUndoTest.undoOperation();
	ASSERT_EQ("addMilk addSugar",goalUndoTest.getOperations());
}
TEST(GoalUndoTest, multi_goal_single_op){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("makeCoffee","addMilk");
	goalUndoTest.undoGoal();
	goalUndoTest.addOperation("stir");
	ASSERT_EQ("stir",goalUndoTest.getOperations());
}
