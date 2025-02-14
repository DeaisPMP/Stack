#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"

TEST(Stack, Top)
{
    Stack<int> s;
    
    EXPECT_THROW(s.top(), std::logic_error);
}

TEST(Stack, PopE)
{
    Stack<int> s;
    EXPECT_THROW(s.pop(), std::logic_error);
}

TEST(Stack, Push)
{
    Stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    EXPECT_EQ(7, s.top());
}

TEST(Stack, Pop)
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    EXPECT_EQ(2, s.top());
}

TEST(Stack, PopDeq)
{
    Stack<int> s;
    s.push(5);
    s.push(3);
    s.push(2);
    s.pop();
    EXPECT_EQ(3, s.top());
    s.push(5);
    s.pop();
    EXPECT_EQ(5, s.top());
}

TEST(Stack, Last)
{
    Stack<int> s;
    s.push(5);
    s.push(3);
    s.push(5);
    EXPECT_EQ(5, s.top());
    s.pop();
    s.pop();
    EXPECT_EQ(3, s.top());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
