#pragma once

#include <string>
#include <vector>
#include <map>


class Table {
  private:
    std::unordered_map<std::string, int> header; std::vector<std::vector<float>> data;

  public:
    Table();
    Table(std::unordered_map<std::string, int> header, std::vector<std::vector<float>> data);
    std::vector<float> sum();
    void print();
};
