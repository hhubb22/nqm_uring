#pragma once
#include <NqmInstance.hh>
#include <yaml-cpp/yaml.h>

class NqmConfigParser {
public:
  NqmConfigParser(const std::string &configFilePath);
  ~NqmConfigParser();

  bool parse();
  NqmInstance *getNextNqmInstance();

private:
  std::string configFilePath_;
  YAML::Node::iterator iter_;
  YAML::Node config_;
};