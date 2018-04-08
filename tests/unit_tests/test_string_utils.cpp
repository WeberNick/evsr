//
// Created by Alexander Weiß on 07.04.18.
//

//
// Created by Alexander Weiß on 31.03.18.
//

#include "utility.hh"
#include "gtest/gtest.h"

TEST(To_Lower_Equals_Test, Equals) {

    std::string loweredWord = Utility::StringOp::toLower("You");

    EXPECT_EQ("you", loweredWord);
}

TEST(Count_Word_Equals_Test, Equals) {

    std::string sentence = "Hi how are you today, you look gorgeous";
    EXPECT_EQ(2, Utility::StringOp::countWordInString(sentence, "you", true));
}

TEST(Word_Trim_Equals_Test, Equals) {

    std::string sentence = " Whitespaces are lost ";
    Utility::StringOp::trim(sentence);
    EXPECT_EQ("Whitespaces are lost", sentence);
}
