#include "../FwrdList_Stack/TLStack.h"
#include "gtest.h"

TEST(TLStack, can_create_stack_with_positive_size)
{
    ASSERT_NO_THROW(TLStack<int> st());
}


TEST(TLStack, can_get_length)
{
    TLStack<int> st;
    int m = st.Number_of_el();
    EXPECT_EQ(0, m);
}


TEST(TLStack, new_stack_is_empty)
{
    TLStack<int> st;
    EXPECT_EQ(1,st.empty());
}
TEST(TLStack, can_push)
{
    TLStack<int> st;
    int c1 = 1;
    int c2 = 2;
    int c3 = 3;
    ASSERT_NO_THROW(st.Push(c1));
    ASSERT_NO_THROW(st.Push(c2));
    ASSERT_NO_THROW(st.Push(c3));
    
}
TEST(TLStack, can_pop)
{
    TLStack<int> st;
    int c1 = 1;
    int c2 = 2;
    int c3 = 3;
    ASSERT_NO_THROW(st.Push(c1));
    ASSERT_NO_THROW(st.Push(c2));
    ASSERT_NO_THROW(st.Push(c3));
    int b1, b2, b3;
    ASSERT_NO_THROW(b1 = st.Pop());
    ASSERT_NO_THROW(b2 = st.Pop());
    ASSERT_NO_THROW(b3 = st.Pop());
   
}
TEST(TLStack, can_push_and_pop)
{
    TLStack<int> st;
    int c1 = 1;
    int c2 = 2;
    int c3 = 3;
    ASSERT_NO_THROW(st.Push(c1));
    ASSERT_NO_THROW(st.Push(c2));
    ASSERT_NO_THROW(st.Push(c3));
    int b1, b2, b3;
    ASSERT_NO_THROW(b1 = st.Pop());
    ASSERT_NO_THROW(b2 = st.Pop());
    ASSERT_NO_THROW(b3 = st.Pop());
    EXPECT_EQ(c1, b3);
    EXPECT_EQ(c2, b2);
    EXPECT_EQ(c3, b1);
}

TEST(TLStack, throws_when_use_pop_on_empty_stack)
{
    TLStack<int> st;
    ASSERT_ANY_THROW(st.Pop());
}


TEST(TLStack, throws_when_use_First_el_on_empty_stack)
{
    TLStack<int> st;
    ASSERT_ANY_THROW(st.First_el());
}

TEST(TLStack, return_true_when_use_Empty_on_empty_stack)
{
    TLStack<int> st;
    bool m = st.empty();
    EXPECT_EQ(1, m);
}
TEST(TLStack, false_when_use_Empty_on_not_empty_stack)
{
    TLStack<int> st;
    st.Push(1);
    st.Push(1);
    bool m = st.empty();
    EXPECT_EQ(0, m);
}
