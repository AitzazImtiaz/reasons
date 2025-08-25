/* 
Reasons entry point: The following file will handle all entry points
to the programming language.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "repl.h"
#include "cxxopts.hpp"

void intro(const std::string& version){
  // Default output
  std::cout << "\x1B[34mReasons,\033[0m";
  std::cout << version << "\n";
  std::cout << "\x1B[92m by Aitzaz Imtiaz\033[0m\n";
  std::cout << "\n";
  std::cout << "Reasons first prototype was developed in late 2025 by Aitzaz Imtiaz under The Broke Consortium \n";
  std::cout << "of Mathematical Research, aiming to study a discourse on logic, and other non-trivial mathematical \n";
  std::cout << "fields to improvise upon philosophical developments. Much of its development took place around in \n";
  std::cout << "reformation of Broke Quarterly and deepening the legislation of consortium allegiance.";
  std::cout << "\n \n";
  std::cout << "The language was inspired by K-drama \"When Life Gives You Tangerines\" and named after the American \n";
  std::cout << "drama \"13 Reasons Why\" character Clay Jensen. This is why, Reasons intend to support both Korean and \n";
  std::cout << "English. \n";
  std::cout << "\n Type \"--help\" for further help. \n";  
}
int main(int argc, char *argv[]){
  std::ifstream versionFile("../VERSION");
  if (!versionFile) {
    std::cerr << "Failed to open VERSION file!" << std::endl;
    return 1;
  }

  std::string version;
  std::getline(versionFile, version); // stores the result in version variable
  versionFile.close();

  if (argc < 2){
    intro(version);
    return 0;
  }

  cxxopts::Options options("Reasons", "A philosophical programming language");
  
  options.add_options()
    ("h,help", "Print usage")
    ("r,repl", "Run the REPL")
    ("v,version", "Show version info");

  auto argument = options.parse(argc, argv);
  if (argument.count("help")) {
    std::cout << options.help() << std::endl;
    return 0;
  }
  if (argument.count("version")){
    std::cout << version << "\n";
    return 0;
  }
  if (argument.count("repl")) {
    std::cout << "Starting REPL...\n";
    repl();
  }
  return 0;
}
