/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#include "Kindergarten.hpp"

using namespace std;

Kindergarten::Kindergarten(string n, string a)
  : name(n), address(a)
{}

void Kindergarten::addTeacher(string name, string surname, int age)
{
  Teacher teacher(name,surname,age);
  teachersList.push_back(teacher);
  return;
}

void Kindergarten::addTeacher(Teacher teacher)
{
  teachersList.push_back(teacher);
  return;
}

void Kindergarten::addChild(string name, string surname, int age)
{
  Child child(name,surname,age);
  childrenList.push_back(child);
  return;
}

void Kindergarten::addChild(Child child)
{
  childrenList.push_back(child);
  return;
}

void Kindergarten::addGroup(string name)
{
  Group group(name);
  groupsList.push_back(group);
  return;
}

void Kindergarten::addGroup(Group group)
{
  groupsList.push_back(group);
  return;
}

int Kindergarten::assignTeacher(string name, string surname, string groupName)
{
  list<Teacher>::iterator teacherIter;
  list<Group>::iterator groupIter;
  teacherIter=findObject<Teacher,list<Teacher>::iterator>(&teachersList,name,surname);
  groupIter=findObject<Group,list<Group>::iterator>(&groupsList,groupName);
  if(teacherIter!=NULLTeacher&&groupIter!=NULLGroup)
  {
    groupIter->setTeacherPointer(teacherIter);
    teacherIter->setGroupName(groupName);
    return 1;
  }
  return 0;
}

int Kindergarten::assignChild(string name, string surname, string groupName)
{
  list<Child>::iterator childIter;
  list<Group>::iterator groupIter;
  childIter=findObject<Child,list<Child>::iterator>(&childrenList,name,surname);
  groupIter=findObject<Group,list<Group>::iterator>(&groupsList,groupName);
  if(childIter!=NULLChild&&groupIter!=NULLGroup)
  {
    groupIter->getChildrenPointerList()->push_back(childIter);
    childIter->setGroupName(groupName);
    return 1;
  }
  return 0;
}

int Kindergarten::removeTeacher(string name, string surname)
{
  list<Teacher>::iterator teacherIter;
  list<Group>::iterator groupIter;
  string groupName;
  teacherIter=findObject<Teacher,list<Teacher>::iterator>(&teachersList,name,surname);
  if(teacherIter!=NULLTeacher)
  {
    groupName=teacherIter->getGroupName();
    if(groupName!="")
    {
      groupIter=findObject<Group,list<Group>::iterator>(&groupsList,groupName);
      groupIter->getTeacherPointer()=NULLTeacher;
    }
    teachersList.erase(teacherIter);
    return 1;
  }
  return 0;
}

int Kindergarten::removeChild(string name, string surname)
{
  list<Child>::iterator childIter;
  list<Group>::iterator groupIter;
  list<list<Child>::iterator>::iterator childIterIter;
  string groupName;
  childIter=findObject<Child,list<Child>::iterator>(&childrenList,name,surname);
  if(childIter!=NULLChild)
  {
    groupName=childIter->getGroupName();
    if(groupName!="")
    {
      groupIter=findObject<Group,list<Group>::iterator>(&groupsList,groupName);
      childIterIter=findObject<list<Child>::iterator,list<list<Child>::iterator>::iterator>(groupIter->getChildrenPointerList(),childIter);
      groupIter->getChildrenPointerList()->erase(childIterIter);
    }
    childrenList.erase(childIter);
    return 1;
  }
  return 0;
}

int Kindergarten::removeGroup(string groupName)
{
  list<Group>::iterator groupIter;
  groupIter=findObject<Group,list<Group>::iterator>(&groupsList,groupName);
  if(groupIter!=NULLGroup)
  {
    for(auto iter=groupIter->getChildrenPointerList()->begin();iter!=groupIter->getChildrenPointerList()->end();iter++)
    {
      (*iter)->getGroupName()="";
    }
    groupsList.erase(groupIter);
    return 1;
  }
  return 0;
}
void Kindergarten::show()
{
  cout <<"Kindergarten name: " <<name <<endl;
  cout <<"Address: "<<address <<endl;
  cout <<"Teachers: " <<endl;
  displayList<Teacher,list<Teacher>::iterator>(&teachersList);
  cout <<"Children: " <<endl;
  displayList<Child,list<Child>::iterator>(&childrenList);
  cout <<"Groups: " <<endl;
  displayList<Group,list<Group>::iterator>(&groupsList);
}

void Kindergarten::show(string groupName)
{
  list<Group>::iterator groupIter;
  groupIter=findObject<Group,list<Group>::iterator>(&groupsList,groupName);
  if(groupIter==NULLGroup)
  {
    cout <<"Group " <<groupName <<" does't exist"<<endl;
    return;
  }
  cout <<"Group " <<groupName <<" : " <<endl;
  cout <<"Teacher responsible for group: " <<endl;
  if(groupIter->getTeacherPointer()!=NULLTeacher)
  {
    cout<< *(groupIter->getTeacherPointer()) <<endl;
  }
  cout <<"Children in group: " <<endl;
  for(auto iter=groupIter->getChildrenPointerList()->begin();iter!=groupIter->getChildrenPointerList()->end();iter++)
  {
    cout << *(*iter) <<endl;
  }
}
