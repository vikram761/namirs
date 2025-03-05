#pragma once

#include <string>
#include <vector>

class Table {
  private:
    std::vector<std::string> header; std::vector<std::vector<float>> data;
    int rows_, columns_;
    
  public:
    Table();
    Table(std::vector<std::string> header, std::vector<std::vector<float>> data);
    std::vector<float> sum();
    void print();
    std::pair<std::vector<float>, float> sample_random_point();
    int rows(); 
    int cols();
};
