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

ostream &operator <<(ostream &os, const Group &group)
{
  os <<group.name;
  return os;
}
