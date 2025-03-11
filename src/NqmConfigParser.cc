#include <NqmConfigParser.hh>
#include <filesystem>
#include <yaml-cpp/yaml.h>

NqmConfigParser::NqmConfigParser(const std::string &configFilePath)
    : configFilePath_(configFilePath) {}

NqmConfigParser::~NqmConfigParser() {}

bool NqmConfigParser::parse() {
  if (!std::filesystem::exists(configFilePath_)) {
    fmt::print("Invalid configuration file: {} does not exist\n",
               configFilePath_);
    return false;
  }
  config_ = YAML::LoadFile(configFilePath_);
  if (config_["instances"].Type() != YAML::NodeType::Sequence) {
    fmt::print("Invalid configuration file: 'instances' must be a list\n");
    return false;
  }
  iter_ = config_["instances"].begin();
  return true;
}

NqmInstance *NqmConfigParser::getNextNqmInstance() {
  if (iter_ == config_["instances"].end()) {
    return nullptr;
  }
  auto instance = *iter_;
  auto nqm_instance = new NqmInstance(instance["name"].as<std::string>(),
                                      instance["interval"].as<int64_t>(),
                                      instance["dst_ip"].as<std::string>());
  ++iter_;
  return nqm_instance;
}