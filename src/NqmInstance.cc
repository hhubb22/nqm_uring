#include <NqmInstance.hh>

int64_t NqmInstanceIdGenerator::id_counter_ = 0;
NqmInstanceIdGenerator NqmInstance::id_generator;

NqmInstance::operator std::string() const {
  return fmt::format("NqmInstance(\n"
                     "  id      = {},\n"
                     "  name    = \"{}\",\n"
                     "  interval = {} ms,\n"
                     "  dst_ip  = \"{}\"\n"
                     ")",
                     id_, name_, interval_, dst_ip_);
}