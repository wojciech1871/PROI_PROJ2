/*
 * Wojciech Celej
 * 271248
 * Wiktor Kusmirek
 * Projekt 2
*/

#ifndef findObject_hpp
#define findObject_hpp

/* find object type of objType in list<objType> pointed by collection
  object has attributes name and surname
  function returns iterator to this object */
template <class objType, class iterType>
iterType findObject(std::list<objType> *collection, std::string name, std::string surname)
{
  for(iterType iter=collection->begin(); iter!=collection->end(); iter++)
  {
    if(iter->name==name && iter->surname==surname) return iter;
  }
  return static_cast<iterType>(0);
}

/* overloaded version of function above
  object has attribute name only */
template <class objType, class iterType>
iterType findObject(std::list<objType> *collection, std::string name)
{
  for(iterType iter=collection->begin(); iter!=collection->end(); iter++)
  {
    if(iter->name==name) return iter;
  }
  return static_cast<iterType>(0);
}

template <class objType, class iterType>
iterType findObject(std::list<objType> *collection, objType object)
{
  for(iterType iter=collection->begin(); iter!=collection->end(); iter++)
  {
    if(*iter==object) return iter;
  }
  return static_cast<iterType>(0);
}

/* function display all elements on list pointed by collection */
template <class objType, class iterType>
void displayList(std::list<objType> *collection)
{
  for(iterType iter=collection->begin(); iter!=collection->end();iter++)
  {
    std::cout <<*iter <<std::endl;
  }
}

#endif //findObject_hpp
