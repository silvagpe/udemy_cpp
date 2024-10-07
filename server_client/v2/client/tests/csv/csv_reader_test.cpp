// my_test.cpp
#include <gtest/gtest.h>
#include "../../src/csv/csv_reader.cpp"

// Teste básico da função Add
TEST(CSV, CheckFileOpen) {

    csv_client::csv::csv_reader::CsvReader reader;
    reader.openFile();

    EXPECT_EQ(reader.openFile(), "Teste");
}

// TEST(MathUtilsTest, AddNegativeNumbers) {
//     EXPECT_EQ(Add(-1, -2), -3);
// }

// TEST(MathUtilsTest, AddMixedNumbers) {
//     EXPECT_EQ(Add(-1, 2), 1);
// }

//https://www.youtube.com/watch?v=pxJoVRfpRPE&t=301s