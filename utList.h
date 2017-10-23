#ifndef UTLIST_H
#define UTLIST_H

#include "atom.h"
#include "number.h"
#include "variable.h"
#include "struct.h"
#include "list.h"

#include <string>
using std::string;

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST(List, constructor)
{
  List l(vector<Term *>{});
  EXPECT_EQ("[]", l.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers)
{
  Number n1(496), n2(8128);
  List l(vector<Term *>{&n1, &n2});
  EXPECT_EQ("[496, 8128]",l.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms)
{
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars)
{
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail)
{
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail)
{
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail)
{
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed)
{
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail)
{
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed)
{
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed)
{
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed)
{
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed)
{
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
// TEST(List, headAndTailMatching1)
// {
//   Atom f("first"), s("second"), t("third");
//   vector<Term *> args = {&f, &s, &t};
//   List l(args);

//   EXPECT_EQ(string("first"), l.head()->symbol());
//   EXPECT_EQ(string("[second, third]"), l.tail()->value());
// }

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
// TEST(List, headAndTailMatching2)
// {
//   Atom f("first"), s("second"), t("third");
//   vector<Term *> args = {&f, &s, &t};
//   List l(args);

//   EXPECT_EQ(string("second"), l.tail()->head()->value());
//   EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
// }

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3)
{
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4)
{
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST(List, emptyExecptionOfHead)
{
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST(List, emptyExecptionOfTail)
{
}

#endif