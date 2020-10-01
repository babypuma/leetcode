/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/01
 *
 * Source : https://leetcode-cn.com/problems/shortest-way-to-form-string/
 * Problem:	Shortest Way to Form String
 *
 */
#include <gtest/gtest.h>
#include "shortest_way_to_form_string.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, shortestWay) {
  struct TestData {
    string src;
    string target;
    int val;
  };
  TestData test_data[] = {
    {"abc", "abcbc", 2},
    {"abc", "acdbc", -1},
    {"xyz", "xzyxz", 3},
    {"aaaaa", "aaaaaaaaaaaaa", 3},
    {"crlzlnuhhwgrwwjcbkixocaatjtezwztgnbuljzkxrrjspgqxiuuqavodztpppdohemdtzjswmcvndiqviahniycneowwfephukgrgfphgkwqogyhimchmpbwmfonpqxtyfvswmwgpdosbsvasrtuhtnreurrirrmowutmtrikpzdtnasltkhgfaamuorumoywxbpxucbiwnugkiqmihidqbomqlyfignjmvdlpnxhskkmlwnvegayiafdqmmdaamzlbtposcxyuoapqffjxqgeskbemstkpamdfwpmkmqvzxrlojwfxvtzwjdtjzgbaxgdijivnvlylhlxvqmosjmpnhiziqjexwnthxynvuznuxreoukjrhmludkihconwhpxgdsxhjqiplijcdetghfmctzeonlpuvyfuovyyksxbbscdmfnkdgwanxpjeulicphtolprwulwvfuypzyvnpensxodxxexplhnivbwskjjvygfdsodubduzuiauyukbfsyfpgigecccoafclrmwdjcuoildcznmqfgpbuorbghahlygddqhhzikvcjyxtwkjwviwanfqbvkvufrawpmvantjmmuujgautfpvtwwnpkrpkdyiovyqqasdyfhytg", "qggsfsgbyhpzypxfghsvxunjoxdqxndvfisweotkchsnfmshwsanulfpwgcwailntbvaunxqmrlvmufdrxjamkixgyasjblwptpwyoskeksjvlbsfurlilvhkjhvozpsrnyrzkqqgyfobghqqoodchwlojbfzwpastapezusnlqffkiobybkszwyfgqjofclfvqebifrdvmmktfozxaqjruyhlashvofhjsxkuelknvisgnuktqisexxpeckrcvmfmhfgxlezlsidgiectdudwwfpvtohxsgiopummzwmhjjshlygagurauolxxcopyvpljjikgpbgskfqufcgtkrhagywvruziihstrspdriamgdwehzwojvwhhtyxhtrrnbvbddwobbkxxjutjrztrpwwooafkbaxiahdqwoctomeytmiauanfutejtkwdvmwbactthlbvgmgsypqxjpbkfmaoziawqgnirqjixencnlbimhooiqxjksuvkpmajhemmrhwvghvhosdwlblyaxkflycndgftjfxlvrerzywhxcbciuhatwszdhasggliwzpkrrxxydcbgflzwefxzlhtvbbniarqugasulcwsbxbldtitakwosjchrhpxwrdnfq", 26},
  };
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.shortestWay(test_data[i].src, test_data[i].target), test_data[i].val);
  }
}
