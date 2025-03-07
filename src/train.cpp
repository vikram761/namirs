#include <iostream>
#include <memory>
#include <ostream>
#include <toml++/toml.hpp>
#include <vector>
#include "helper.h"
#include "data_table.h"
#include "sgd_regressor.h"

void train() {

  std::string s;
  std::cout << "Load File: ";
  std::cin >> s;

  std::shared_ptr<Table> parsed_table = parse_csv();

  parsed_table->print();
   
  std::cout << std::endl << std::endl <<std::endl ;

  auto model = std::make_unique<SGD_REGRESSOR>(parsed_table);
  model->fit();

  std::vector<float> v = model->weights();

  std::cout << "WEIGHTS : " ;
  for(auto w: v) 
    std::cout << w << "  ";
  std::cout << std::endl << "BIAS : " ;
  std::cout << model->bias() << std::endl << std::endl;

  return;
};
