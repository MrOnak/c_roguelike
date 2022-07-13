#include <iostream>
#include <time.h>
#include <filesystem>

#include "../src/Helpers/Logger.h"

int main(int argc, char* argv[]) {
  std::string path = std::filesystem::canonical(argv[0]).parent_path().c_str();
  std::string logfile = std::filesystem::canonical(path + "/../log/testlog.log");
  Logger::setFile(logfile, Logger::LVL_DEBUG);

  std::cout << "logging to " << logfile << "\n\n";

  // testing log level NONE
  Logger::setLevel(Logger::LVL_DEBUG);
  Logger::log("--- setting log level to NONE", Logger::LVL_DEBUG);
  Logger::setLevel(Logger::LVL_NONE);
  Logger::log("logging at FATAL level", Logger::LVL_FATAL);
  Logger::log("logging at ERROR level", Logger::LVL_ERROR);
  Logger::log("logging at WARN level", Logger::LVL_WARN);
  Logger::log("logging at INFO level", Logger::LVL_INFO);
  Logger::log("logging at DEBUG level", Logger::LVL_DEBUG);
  // testing log level FATAL
  Logger::setLevel(Logger::LVL_DEBUG);
  Logger::log("--- setting log level to FATAL", Logger::LVL_DEBUG);
  Logger::setLevel(Logger::LVL_FATAL);
  Logger::log("logging at FATAL level", Logger::LVL_FATAL);
  Logger::log("logging at ERROR level", Logger::LVL_ERROR);
  Logger::log("logging at WARN level", Logger::LVL_WARN);
  Logger::log("logging at INFO level", Logger::LVL_INFO);
  Logger::log("logging at DEBUG level", Logger::LVL_DEBUG);
  // testing log level ERROR
  Logger::setLevel(Logger::LVL_DEBUG);
  Logger::log("--- setting log level to ERROR", Logger::LVL_DEBUG);
  Logger::setLevel(Logger::LVL_ERROR);
  Logger::log("logging at FATAL level", Logger::LVL_FATAL);
  Logger::log("logging at ERROR level", Logger::LVL_ERROR);
  Logger::log("logging at WARN level", Logger::LVL_WARN);
  Logger::log("logging at INFO level", Logger::LVL_INFO);
  Logger::log("logging at DEBUG level", Logger::LVL_DEBUG);
  // testing log level WARN
  Logger::setLevel(Logger::LVL_DEBUG);
  Logger::log("--- setting log level to WARN", Logger::LVL_DEBUG);
  Logger::setLevel(Logger::LVL_WARN);
  Logger::log("logging at FATAL level", Logger::LVL_FATAL);
  Logger::log("logging at ERROR level", Logger::LVL_ERROR);
  Logger::log("logging at WARN level", Logger::LVL_WARN);
  Logger::log("logging at INFO level", Logger::LVL_INFO);
  Logger::log("logging at DEBUG level", Logger::LVL_DEBUG);
  // testing log level INFO
  Logger::setLevel(Logger::LVL_DEBUG);
  Logger::log("--- setting log level to INFO", Logger::LVL_DEBUG);
  Logger::setLevel(Logger::LVL_INFO);
  Logger::log("logging at FATAL level", Logger::LVL_FATAL);
  Logger::log("logging at ERROR level", Logger::LVL_ERROR);
  Logger::log("logging at WARN level", Logger::LVL_WARN);
  Logger::log("logging at INFO level", Logger::LVL_INFO);
  Logger::log("logging at DEBUG level", Logger::LVL_DEBUG);
  // testing log level DEBUG
  Logger::setLevel(Logger::LVL_DEBUG);
  Logger::log("--- setting log level to DEBUG", Logger::LVL_DEBUG);
  Logger::setLevel(Logger::LVL_DEBUG);
  Logger::log("logging at FATAL level", Logger::LVL_FATAL);
  Logger::log("logging at ERROR level", Logger::LVL_ERROR);
  Logger::log("logging at WARN level", Logger::LVL_WARN);
  Logger::log("logging at INFO level", Logger::LVL_INFO);
  Logger::log("logging at DEBUG level", Logger::LVL_DEBUG);

  return EXIT_SUCCESS;
}
