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

  std::string getName();
  std::string getSurname();
  std::string getGroupName();

  void setGroupName(std::string);

  friend std::ostream &operator <<(std::ostream &os, const Teacher &teacher);
};

#endif //Teacher_hpp
