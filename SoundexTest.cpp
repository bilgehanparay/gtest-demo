#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "Soundex.h"

class SoundexEncoding: public testing::Test{
    public:
        Soundex soundex;
    private:
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
    ASSERT_THAT(soundex.encode("A"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits){
    ASSERT_THAT(soundex.encode("I"), testing::Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits){
    ASSERT_THAT(soundex.encode("Ab"), testing::Eq("A100"));
}