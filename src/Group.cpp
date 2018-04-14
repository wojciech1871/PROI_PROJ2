/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#include "Group.hpp"

using namespace std;

Group::Group(string n)
  : name(n)
  {}

std::string Group::getName()
{
  return name;
}

std::list<std::list<Child>::iterator>* Group::getChildrenPointerList()
{
  return &ChildrenPointerList;
}

std::list<Teacher>::iterator Group::getTeacherPointer()
{
  return teacherPointer;
}

void Group::setTeacherPointer(std::list<Teacher>::iterator tP)
{
  teacherPointer=tP;
}

ostream &operator <<(ostream &os, const Group &group)
{
  os <<group.name;
  return os;
}
