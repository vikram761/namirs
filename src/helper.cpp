#include <iostream>
#include <iomanip>

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
