/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
#include "Kindergarten.hpp"

template<class T>
class Interface
{
  T* kindergarten;
  char sign;

  void help()
  {
    std::cout <<"Press button to choose option:" <<std::endl;
    std::cout <<"A - add new child" <<std::endl;
    std::cout <<"S - add new teacher" <<std::endl;
    std::cout <<"D - add new group" <<std::endl;
    std::cout <<"F - assign child to group" <<std::endl;
    std::cout <<"G - assign teacher to group" <<std::endl;
    std::cout <<"Z - remove child" <<std::endl;
    std::cout <<"X - remove teacher" <<std::endl;
    std::cout <<"C - remove group" <<std::endl;
    std::cout <<"V - show information about created kindergarten" <<std::endl;
    std::cout <<"B - show information about group in kindergarten" <<std::endl;
    std::cout <<"H - print help menu"<<std::endl;
    std::cout <<"Q - quit" <<std::endl;
  }
  void init()
  {
    std::string name;
    std::string surname;
    std::string address;
    std::string groupName;
    int age;
    std::string a;
    for(;;)
    {
      std::cout.clear();
      std::cout <<'>';
      std::cin.clear();
      std::cin.sync();
      std::getline(std::cin,a);
      sign=a[0];
      if(sign==0) continue;
      switch(sign)
      {
        case 'a':
          std::cout <<"Submit child's name: ";
          std::cin >>name;
          std::cout <<"Submit child's surname: ";
          std::cin >>surname;
          std::cout <<"Submit chid's age: ";
          std::cin >>age;
          kindergarten->addChild(name,surname,age);
          std::cout <<"Child was added" <<std::endl;
          break;
        case 's':
          std::cout <<"Submit teacher's name: ";
          std::cin >>name;
          std::cout <<"Submit teacher's surname: ";
          std::cin >>surname;
          std::cout <<"Submit teacher's age: ";
          std::cin >>age;
          kindergarten->addTeacher(name,surname,age);
          std::cout <<"Teacher was added" <<std::endl;
          break;
        case 'd':
          std::cout <<"Submit group's name: ";
          std::cin >>groupName;
          kindergarten->addGroup(groupName);
          std::cout <<"Group was added" <<std::endl;
          break;
        case 'f':
          std::cout <<"Submit child's name: ";
          std::cin >>name;
          std::cout <<"Submit child's surname: ";
          std::cin >>surname;
          std::cout <<"Submit group's name: ";
          std::cin >>groupName;
          if(kindergarten->assignChild(name,surname,groupName))
          {
            std::cout <<"Managed to assign child to group" <<std::endl;
          }
          else
          {
            std::cout <<"Wrong data. Didn't manage to assign" <<std::endl;
          }
          break;
        case 'g':
          std::cout <<"Submit teacher's name: ";
          std::cin >>name;
          std::cout <<"Submit teacger's surname: ";
          std::cin >>surname;
          std::cout <<"Submit group's name: ";
          std::cin >>groupName;
          if(kindergarten->assignChild(name,surname,groupName))
          {
            std::cout <<"Managed to assign teacher to group" <<std::endl;
          }
          else
          {
            std::cout <<"Wrong data. Didn't manage to assign" <<std::endl;
          }
          break;
        case 'z':
          std::cout <<"Submit child's name: ";
          std::cin >>name;
          std::cout <<"Submit child's surname: ";
          std::cin >>surname;
          if(kindergarten->removeChild(name,surname))
          {
            std::cout <<"Managed to remove child" <<std::endl;
          }
          else
          {
            std::cout <<"Wrong data. Didn't manage to remove" <<std::endl;
          }
          break;
        case 'x':
          std::cout <<"Submit teacher's name: ";
          std::cin >>name;
          std::cout <<"Submit teacher's surname: ";
          std::cin >>surname;
          if(kindergarten->removeTeacher(name,surname))
          {
            std::cout <<"Managed to remove teacher" <<std::endl;
          }
          else
          {
            std::cout <<"Wrong data. Didn't manage to remove" <<std::endl;
          }
          break;
        case 'c':
          std::cout <<"Submit group's name: ";
          std::cin >>groupName;
          if(kindergarten->removeGroup(groupName))
          {
            std::cout <<"Managed to remove group" <<std::endl;
          }
          else
          {
            std::cout <<"Wrong data. Didn't manage to remove" <<std::endl;
          }
          break;
        case 'v':
          kindergarten->show();
          break;
        case 'b':
          std::cout <<"Submit group's name: ";
          std::cin >>groupName;
          kindergarten->show(groupName);
          break;
        case 'h':
          help();
          break;
        case 'q':
          return;
        default:
          std::cout <<"Command wasn't recognized" <<std::endl;
          break;
      }
    }
  }

public:
  Interface()
  {
    std::string name;
    std::string address;
    std::cout <<"Submit data of new kindergarten:" <<std::endl;
    std::cout <<"Name: ";
    std::cin >>name;
    std::cout <<"Address: ";
    std::cin >>address;
    kindergarten=new Kindergarten(name,address);
    std::cout <<"Kindergarten created" <<std::endl;
    help();
    init();
  }
};
#endif //Interface_hpp
