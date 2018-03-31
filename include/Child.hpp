/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#ifndef Child_hpp
#define Child_hpp

#include <iostream>
#include <string>
#include <list>
#include <iomanip>

#define NULLChild static_cast<list<Child>::iterator>(0)

class Child
{
  std::string name;
  std::string surname;
  std::string groupName;
  int age;

public:
  Child(std::string,std::string,int);

  friend class Kindergarten;
  template <class objType, class iterType>
  friend iterType findObject(std::list<objType> *collection, std::string name, std::string surname);
  friend std::ostream &operator <<(std::ostream &os, const Child &child);
};

#endif //Child_hpp
