// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.h"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template<class T, class C>
void read_file_to_cont(std::ifstream& f, C& c) {
    T t;
    while (f >> t)
        c.push_back(t);
}

template<class T, class C>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    C c = {};
    read_file_to_cont<T, C>(fi, c);
    my_selection_sort(c.begin(), c.end());
    for (auto &t : c)
        fo << t << std::endl;
}

template<class T>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  // read second line to decide container
  char cont_type;
  fi >> cont_type;
  fo << cont_type << std::endl;
  switch (cont_type)
  {
    case 'l':
      read_and_sort<T, std::list<T>>(fi, fo);
      break;
    case 'v':
      read_and_sort<T, std::vector<T>>(fi, fo);
      break;
    case 'd':
      read_and_sort<T, std::deque<T>>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown container");
  }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
  // read first line to decide value type
  char val_type;
  fi >> val_type;
  fo << val_type << std::endl;
  switch(val_type)
  {
    case 'i':
      read_and_sort_decide_container<int>(fi, fo);
      break;
    case 'u':
      read_and_sort_decide_container<unsigned>(fi, fo);
      break;
    case 'f':
      read_and_sort_decide_container<float>(fi, fo);
      break;
    case 'd':
      read_and_sort_decide_container<double>(fi, fo);
      break;
    case 'c':
      read_and_sort_decide_container<char>(fi, fo);
      break;
    case 's':
      read_and_sort_decide_container<std::string>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown value");
  }
}
