/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#ifndef Teacher_hpp
#define Teacher_hpp

#include <iostream>
#include <string>
#include <list>
#include <iomanip>

#define NULLTeacher static_cast<list<Teacher>::iterator>(0)

class Teacher
{
  std::string name;
  std::string surname;
  std::string groupName;
  int age;

public:
  Teacher(std::string,std::string,int);

  friend class Kindergarten;
  template <class objType, class iterType>
  friend iterType findObject(std::list<objType> *collection, std::string name, std::string surname);
  friend std::ostream &operator <<(std::ostream &os, const Teacher &teacher);
};

#endif //Teacher_hpp
