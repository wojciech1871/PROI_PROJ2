/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#include "Teacher.hpp"

using namespace std;

Teacher::Teacher(string n, string s, int a)
  : name(n), surname(s), groupName(""), age(a)
  {}

ostream &operator <<(ostream &os, const Teacher &teacher)
{
  os <<setw(15) <<left <<teacher.name <<setw(15) <<left <<teacher.surname;
  os <<setw(15) <<left <<teacher.age <<setw(15) <<left <<teacher.groupName;
  return os;
}
