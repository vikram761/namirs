#include "data_table.h"
#include <map>
#include <vector>
#include <iostream>

Table::Table(std::unordered_map<std::string, int> new_header, std::vector<std::vector<float>> new_data) {
  this->header = new_header;
  this->data = new_data;
};

std::vector<float> Table::sum() {
  std::vector<float> result(this->data.size());

  for (int i = 0; i < (this->data).size(); ++i) {
    for (int j = 0; j < (this->data)[0].size(); ++j)
      result[i] += this->data[i][j];
  };

  return result;
};

void Table::print() {


  for (auto [key, value]: this->header) std::cout << key << " ";
  std::cout << std::endl;

 for (int i = 0; i < this->data[0].size(); ++i) {
   for (int j = 0; j < this->data.size(); ++j) {
     std::cout << this->data[j][i] << " ";
   };
   std::cout << std::endl;
 };



};
