#include"gtest.h"
#include"../Queue_list/Queue.h"

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(TQueue<int> q);
}

TEST(Queue, can_copy_the_queue)
{
    TQueue<int> q;
    q.Push(5);
    ASSERT_NO_THROW(TQueue<int> copy(q));
}

TEST(Queue, the_copied_queue_is_the_same_as_the_original_one)
{
    TQueue<int> q;
    q.Push(5);
    TQueue<int> copy(q);
    EXPECT_EQ(true, q == copy);
}
TEST(Queue, when_you_change_the_original_queue_the_copied_stack_does_not_change)
{
    TQueue<int> q;
    q.Push(5);
    TQueue<int> copy(q);
    copy.GetHead();
    EXPECT_EQ(true, copy.Empty());
    EXPECT_EQ(5, q.GetHead());
}
TEST(Queue, can_assign_empty_queue)
{
    TQueue<int> q1;
    TQueue<int> q2;
    ASSERT_NO_THROW(q1 = q2);
}
TEST(Queue, can_assign_queue_of_the_same_data_types)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(5);
    q1.Push(7);
    q2.Push(3);
    ASSERT_NO_THROW(q1 = q2);
}

TEST(Queue, after_assignment_the_queues_are_equal_to)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(5);
    q1.Push(7);
    q2.Push(3);
    q2 = q1;
    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(q1.GetHead(), q2.GetHead());
    }
}

TEST(Queue, can_compare_queue)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(5);
    q2.Push(3);
    ASSERT_NO_THROW(q2 == q1);
}

TEST(Queue, comparing_the_queue_with_itself_gives_the_truth)
{
    TQueue<int> q;
    EXPECT_EQ(true, q == q);
}

TEST(Queue, comparing_the_same_queue_gives_the_truth)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(5);
    q2.Push(5);
    EXPECT_EQ(true, q1 == q2);
}

TEST(Queue, comparing_different_queue_gives_the_lie)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(5);
    EXPECT_EQ(true, q1 != q2);
}
TEST(Queue, can_check_the_queue_for_emptiness)
{
    TQueue<int> q;
    ASSERT_NO_THROW(q.Empty());
}
TEST(Queue, initially_the_queue_is_empty)
{
    TQueue<int> q;
    q.Push(5);
    q.GetHead();
    EXPECT_EQ(true, q.Empty());
}
TEST(Queue, checking_for_the_emptiness_of_a_non_empty_queue_returns_false)
{
    TQueue<int> q;
    q.Push(5);
    EXPECT_EQ(false, q.Empty());
}
TEST(Queue, can_add_an_item_to_an_incomplete_queue)
{
    TQueue<int> q;
    ASSERT_NO_THROW(q.Push(5));
}
TEST(Queue, can_see_what_is_at_the_top_of_a_non_empty_queue)
{
    TQueue<int> q;
    q.Push(5);
    ASSERT_NO_THROW(q.SeeHead());
}
TEST(Queue, viewing_the_top_of_the_queue_does_not_change_the_state_of_the_stack)
{
    TQueue<int> q;
    q.Push(5);
    int a = q.SeeHead();
    EXPECT_EQ(a, q.SeeHead());
}
TEST(Queue, cant_look_at_the_top_of_an_empty_queue)
{
    TQueue<int> q;
    ASSERT_ANY_THROW(q.SeeHead());
}
TEST(Queue, can_take_an_element_from_a_non_empty_non_empty_queue)
{
    TQueue<int> q;
    q.Push(5);
    ASSERT_NO_THROW(q.GetHead());
}
TEST(Queue, taking_an_element_from_the_queue_reduces_its_size_by_one)
{
    TQueue<int> q;
    q.Push(5);
    q.GetHead();
    EXPECT_EQ(true, q.Empty());
}
TEST(Queue, cant_take_an_element_from_an_empty_queue)
{
    TQueue<int> q;
    ASSERT_ANY_THROW(q.GetHead());
}