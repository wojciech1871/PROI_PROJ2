/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#include "Child.hpp"

using namespace std;

Child::Child(string n, string s, int a)
  : name(n), surname(s), groupName(""), age(a)
  {}

std::string Child::getName()
{
  return name;
}

std::string Child::getSurname()
{
  return surname;
}

std::string Child::getGroupName()
{
  return groupName;
}

void Child::setGroupName(std::string gn)
{
  groupName=gn;
}

ostream &operator <<(ostream &os, const Child &child)
{
  os <<setw(15) <<left <<child.name <<setw(15) <<left <<child.surname;
  os <<setw(15) <<left <<child.age <<setw(15) <<left <<child.groupName;
  return os;
}
