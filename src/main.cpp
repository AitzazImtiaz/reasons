/* 
Reasons entry point: The following file will handle all entry points
to the programming language.
*/

#include <iostream>
#include <cxxopts.hpp>
#include <fstream>
#include <string>

int main(int argc, char *argv[]){
  std::ifstream versionFile("../VERSION");
  if (!versionFile) {
      std::cerr << "Failed to open VERSION file!" << std::endl;
      return 1;
  }

  std::string version;
  std::getline(versionFile, version); // stores the result in version variable
  versionFile.close();
  // Default output
  cout << ""\x1B[34mReasons,\033[0m\n"";
  cout << version;
  cout << "\x1B[92m by Aitzaz Imtiaz\033[0m\n";
  cout << "\n";
  cout << "Reasons first prototype was developed in late 2025 by Aitzaz Imtiaz under The Broke Consortium \n";
  cout << "of Mathematical Research, aiming to study a discourse on logic, and other non-trivial mathematical \n";
  cout << "fields to improvise upon philosophical developments. Much of its development took place around in \n";
  cout << "reformation of Broke Quarterly and deepening the legislation of consortium allegiance.";
  cout << "\n \n";
  cout << "The language was inspired by K-drama \"When Life Gives You Tangerines\" and named after the American \n";
  cout << "drama \"13 Reasons Why\" character Clay Jensen. This is why, Reasons intend to support both Korean and \n";
  cout << "English. \n";
  cout << "\n Type \"--help\" for further help.";
  return 0;
}
