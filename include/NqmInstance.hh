#pragma once

#include <fmt/format.h>
#include <string>

/**
 * @brief ID生成器类，用于为NqmInstance实例分配唯一标识符
 *
 * 该类通过静态计数器实现单调递增的ID生成，确保每个NqmInstance
 * 实例在程序运行期间拥有唯一标识符。
 */
class NqmInstanceIdGenerator {
public:
  /** @brief 默认构造函数 */
  NqmInstanceIdGenerator() = default;

  /**
   * @brief 生成新的唯一ID
   * @return int64_t 递增的唯一标识符
   */
  int64_t generate() { return id_counter_++; }

private:
  /** @brief 静态计数器，用于跟踪已分配的ID数量 */
  static int64_t id_counter_;
};

/**
 * @brief NQM(Network Quality Monitoring)实例类
 *
 * 该类表示一个网络质量监控实例，负责以指定的时间间隔向目标IP地址
 * 发送监控数据包，用于评估网络连接质量。每个实例都有唯一标识符和
 * 用户定义的名称，便于区分和管理多个监控任务。
 */
class NqmInstance {
public:
  /**
   * @brief 构造一个新的NQM监控实例
   *
   * @param name 实例名称，用于用户识别
   * @param interval 发送监控数据包的时间间隔(毫秒)
   * @param dst_ip 目标IP地址，监控数据包将发送到此地址
   */
  NqmInstance(const std::string name, int64_t interval,
              const std::string &dst_ip)
      : name_(name), interval_(interval), dst_ip_(dst_ip) {
    id_ = id_generator.generate();
  }

  /**
   * @brief 字符串转换运算符，用于输出实例信息
   * @return std::string 格式化的实例信息字符串
   */
  operator std::string() const;

private:
  /** @brief 静态ID生成器，为所有NqmInstance实例提供唯一ID */
  static NqmInstanceIdGenerator id_generator;

  /** @brief 实例的唯一标识符 */
  int64_t id_;

  /** @brief 实例名称，由用户指定，用于识别监控任务 */
  std::string name_;

  /** @brief 发送监控数据包的时间间隔，单位为毫秒 */
  int64_t interval_;

  /** @brief 监控数据包的目标IP地址 */
  std::string dst_ip_;
};