#include "data_table.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <utility>

Table::Table() { std::srand(time(0)); };

Table::Table(std::vector<std::string> new_header, std::vector<std::vector<float>> new_data) : Table() {
  this->header = new_header;
  this->data = new_data;
  this->rows_ = data.empty() ? 0 : new_data[0].size();
  this->columns_ = new_header.size();
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

  for (const auto key: this->header) std::cout << key << " ";
  std::cout << std::endl;

  for (int i = 0; i < this->data[0].size(); ++i) {
    for (int j = 0; j < this->data.size(); ++j) {
      std::cout << this->data[j][i] << " ";
    };
    std::cout << std::endl;
  };

};

std::pair<std::vector<float>, float> Table::sample_random_point() {
  if(rows_ == 0) 
    throw std::runtime_error("Cannot sample from an empty table.");

  int random_number = std::rand() % rows_;

  std::vector<float> input;
  for(int i =0; i < columns_ - 1; i++)
    input.push_back(data[i][random_number]);

  float output = data[columns_ -1][random_number];
  return std::make_pair(input, output);

};

int Table::rows() { return rows_; };
int Table::cols() { return columns_; };

