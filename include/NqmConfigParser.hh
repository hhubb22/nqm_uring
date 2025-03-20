#pragma once
#include <NqmInstance.hh>

class NqmConfigParser {
public:
  NqmConfigParser(const std::string &configFilePath);
  ~NqmConfigParser();

  bool parse();
  NqmInstance *getNextNqmInstance();

private:
  std::string configFilePath_;
};