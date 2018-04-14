/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#ifndef Group_hpp
#define Group_hpp

#include <iostream>
#include <string>
#include <list>
#include "Teacher.hpp"
#include "Child.hpp"

#define NULLGroup static_cast<list<Group>::iterator>(0)

class Group
{
  std::string name;
  std::list<std::list<Child>::iterator> ChildrenPointerList;
  std::list<Teacher>::iterator teacherPointer;
public:
  Group(std::string);

  std::string getName();
  std::list<std::list<Child>::iterator>* getChildrenPointerList();
  std::list<Teacher>::iterator getTeacherPointer();

  void setTeacherPointer(std::list<Teacher>::iterator);

  friend std::ostream &operator <<(std::ostream &os, const Group &group);
};

#endif //Group_hpp
