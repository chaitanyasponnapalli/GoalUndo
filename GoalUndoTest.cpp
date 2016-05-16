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
	/*std::vector <std::string> operationsTest;
	std::stack <Goal> goalsTest;
	
	operationsTest.push_back("addMilk");
	operationsTest.push_back("addSugar");*/
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
/*TEST(GoalUndoTest, undoOperation_single_goal_no_Operation){
	GoalUndo goalUndoTest;
	goalUndoTest.addOperation("addSugar");
	goalUndoTest.undoOperation("addSugar");
	goalUndoTest.undoOperation();
	ASSERT_EQ("",goalUndoTest.getGoal());
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

