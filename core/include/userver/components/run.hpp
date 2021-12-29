#pragma once

/// @file userver/components/run.hpp
/// @brief Functions to start a service or tool with the specified
/// config and components::ComponentList.

#include <string>

#include <userver/utils/strong_typedef.hpp>

#include "component_list.hpp"

USERVER_NAMESPACE_BEGIN

/// Contains functions and types to start a userver based service/tool.
namespace components {

/// Data type to distinguish config path and in-memory config values in
/// components::Run() and components::RunOnce() functions.
struct InMemoryConfig : utils::StrongTypedef<InMemoryConfig, std::string> {
  using StrongTypedef::StrongTypedef;
};

/// Starts a server with the provided component list and config loaded from
/// file. Ropens the logging files on SIGUSR1.
///
/// @see utils::DaemonMain
void Run(const std::string& config_path, const ComponentList& component_list,
         const std::string& init_log_path = {});

/// Starts a server with the provided component list and config.
/// Ropens the logging files on SIGUSR1.
///
/// @see utils::DaemonMain
void Run(const InMemoryConfig& config, const ComponentList& component_list,
         const std::string& init_log_path = {});

/// Runs the component list once with the config loaded from file.
///
/// @see utils::DaemonMain
void RunOnce(const std::string& config_path,
             const ComponentList& component_list,
             const std::string& init_log_path = {});

/// Runs the component list once with the config.
///
/// @see utils::DaemonMain
void RunOnce(const InMemoryConfig& config, const ComponentList& component_list,
             const std::string& init_log_path = {});

}  // namespace components

USERVER_NAMESPACE_END
