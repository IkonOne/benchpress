#include <gtest/gtest.h>

#include <bplib/ds/dense_map.h>

#include <string>

TEST(dense_map_test, find_returns_expected_values) {
    bplib::dense_map<int, std::string> m;
    m.push_back({5, "5"});
    m.push_back({100, "100"});
    m.push_back({1, "1"});
    m.push_back({3, "3"});

    EXPECT_EQ(*m.find(1), "1");
    EXPECT_EQ(*m.find(3), "3");
    EXPECT_EQ(*m.find(5), "5");
    EXPECT_EQ(*m.find(100), "100");
}