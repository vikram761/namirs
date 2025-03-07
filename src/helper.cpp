#include "data_table.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "helper.h"

void print_help() {
  std::cout.fill(' ');
  std::cout << "░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓██████▓▒░  " << std::endl;
  std::cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ " << std::endl;
  std::cout << "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ " << std::endl;
  std::cout << " ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░ " << std::endl;
  std::cout << "   ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ " << std::endl;
  std::cout << "   ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ " << std::endl;
  std::cout << "   ░▒▓█▓▒░    ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░  " << std::endl;
  std::cout << std::endl;

  std::cout << "usage: namirs [-v | --version] [-h | --help]" << std::endl;
  std::cout << std::string(14, ' ') <<  "<command> [<args>]" << std::endl;

  std::cout << "some standard commends used in namirs:" <<  std::endl;
  std::cout << "\t" << std::setw(10) << std::left << "train" << "Trains the model" << std::endl;
  std::cout << "\t" << std::setw(10) << std::left << "predict" <<  "Predict using the model" <<  std::endl;
  std::cout << "\t" << std::setw(10) << std::left << "test" << "Test the accuracy of the model" <<  std::endl;
  std::cout << "\t" << std::setw(10) << std::left << "deploy" << "exposes a port with a webserver to predict" <<  std::endl;

};

std::shared_ptr<Table> parse_csv() {
  using namespace std;
  ifstream input_file("../simple_linreg_salary.csv");

  string line; 
  getline(input_file, line);

 vector<string> headers;

  int prv = 0;
  for (int i = 0; i <= line.size(); ++i) {
    if (i == line.size() || line[i] == ',') {
      headers.push_back(line.substr(prv, i - prv));
      prv = i + 1;
    };
  };

  vector<vector<float>> table(headers.size(), vector<float>(0, 0));
  while (input_file.good()) {

    getline(input_file, line);
    if (line == "") break;

    int prv = 0, current_index = 0;
    for (int i = 0; i <= line.size(); ++i) {
      if (i == line.size() || line[i] == ',') {
        table[current_index].push_back(stof(line.substr(prv, i - prv))); 
        prv = i + 1;
        current_index++;
      };
    };

  };

  return make_shared<Table>(headers, table);
};
