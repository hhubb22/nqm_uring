#include <NqmConfigParser.hh>
#include <NqmInstance.hh>
#include <fmt/base.h>
#include <fmt/core.h>
#include <memory>

int main(int argc, char **argv) {
  if (argc != 2) {
    fmt::print("Usage: {} <config_file_path>\n", argv[0]);
    return 1;
  }
  std::string configFilePath = argv[1];

  NqmConfigParser parser(configFilePath);
  if (!parser.parse()) {
    fmt::print("Failed to parse config file {}\n", configFilePath);
    return 1;
  }

  while (std::unique_ptr<NqmInstance> instance{parser.getNextNqmInstance()}) {
    fmt::print("{}\n", static_cast<std::string>(*instance));
  }
  return 0;
}