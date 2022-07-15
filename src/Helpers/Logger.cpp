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

char* Logger::getGameTime() {
  long time = Timekeeper::getTime();
  long date = Timekeeper::getDate();
  long timestamp = date*86400 + time;

  time_t rawtime = (time_t) timestamp;
  struct tm * timeinfo = localtime(&rawtime);
  char *dt = (char*) malloc(sizeof(char) * (51));
  strftime(dt, 50, "%a %b %d %H:%M:%S %Y", timeinfo);

  return dt;
}

bool Logger::setFile(std::string filepath, int level) {
  bool retval = true;
  setLevel(level);
  writer.open(filepath, std::ios::out);

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
    writer << getGameTime() << " (" << strLevels[level] << ")" << ": " << message << std::endl;
  }
}

void Logger::debug(std::string message) {log(message, LVL_DEBUG);}
void Logger::info(std::string message) {log(message, LVL_INFO);}
void Logger::warn(std::string message) {log(message, LVL_WARN);}
void Logger::error(std::string message) {log(message, LVL_ERROR);}
void Logger::fatal(std::string message) {log(message, LVL_FATAL);}
