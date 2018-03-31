/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#ifndef Kindergarten_hpp
#define Kindergarten_hpp

#include <iostream>
#include <string>
#include <list>
#include "Teacher.hpp"
#include "Child.hpp"
#include "Group.hpp"
#include "templateFunctions.hpp"

class Kindergarten
{
  std::string name;
  std::string address;
  std::list<Teacher> teachersList;
  std::list<Child> childrenList;
  std::list<Group> groupsList;

public:
  Kindergarten(std::string,std::string);

  void addTeacher(std::string,std::string,int);
  void addTeacher(Teacher);
  void addChild(std::string,std::string,int);
  void addChild(Child);
  void addGroup(std::string);
  void addGroup(Group);

  int assignTeacher(std::string,std::string,std::string);
  int assignChild(std::string,std::string,std::string);

  int removeTeacher(std::string,std::string);
  int removeChild(std::string,std::string);
  int removeGroup(std::string);

  void show();
  void show(std::string);
};

#endif //Kindergarten_hpp
