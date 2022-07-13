#include "Logger.h"

std::ofstream Logger::writer;
int Logger::loglevel = Logger::LVL_NONE;
std::string Logger::strLevels[6] = {"NONE", "FATAL", "ERROR", "WARN", "INFO", "DEBUG"};

Logger::Logger() {
}

Logger::~Logger() {
  writer.close();
}

char* Logger::getSystemTime() {
  time_t now = time(0);
  char* dt = strtok(ctime(&now), "\n");

  return dt;
}

bool Logger::setFile(std::string filepath, int level) {
  bool retval = true;
  setLevel(level);
  writer.open(filepath, std::ios::out | std::ios::app);

  if (!writer) {
    retval = false;
  }

  return retval;
}

void Logger::setLevel(int level) {
  if (level >= LVL_NONE && level <= LVL_DEBUG) {
    loglevel = level;
  }
}

void Logger::log(std::string message, int level) {
  if (writer && loglevel >= level) {
    writer << getSystemTime() << " (" << strLevels[level] << ")" << ": " << message << std::endl;
  }
}
