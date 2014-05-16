#include "pub_def.h"
#include "log_inc.h"
#include "stl_inc.h"
#include "gtest/gtest.h"

TEST(TENO_LOG, TENO_LOG_001)
{
    EXPECT_EQ(F_SUCCESS, log_init());
}

TEST(TENO_STL, TENO_STL_001)
{
    T_LIST *stl_list = T_NULL;
    T_UINT32 nice = 8;
    EXPECT_EQ(F_FAILURE, stl_list_create(T_NULL));
    EXPECT_EQ(F_SUCCESS, stl_list_create(&stl_list));
    EXPECT_EQ(0, stl_list->size);
    EXPECT_EQ(T_NULL, stl_list->head);

    EXPECT_EQ(F_SUCCESS, stl_list_insert(stl_list, (T_VOID*)&nice, sizeof(nice)));
    EXPECT_EQ(8, *(T_UINT32 *)stl_list->head->data);
    EXPECT_EQ(1, stl_list->size);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
