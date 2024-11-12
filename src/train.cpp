#include <iostream>
#include <ostream>
#include <toml++/toml.hpp>
#include "helper.h"
#include "data_table.h"

void train() {

  std::string s;
  std::cout << "Load File: ";
  std::cin >> s;

  Table parsed_table = parse_csv();

  parsed_table.print();

  return;
};
