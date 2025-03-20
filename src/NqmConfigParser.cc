#include <NqmConfigParser.hh>

NqmConfigParser::NqmConfigParser(const std::string &configFilePath)
    : configFilePath_(configFilePath) {}

NqmConfigParser::~NqmConfigParser() {}

bool NqmConfigParser::parse() { return true; }

NqmInstance *NqmConfigParser::getNextNqmInstance() { return nullptr; }