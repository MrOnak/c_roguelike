#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string.h>

#include "Timekeeper.h"

class Logger {
  private:
    static std::ofstream writer;
    static int loglevel;
    static std::string strLevels[6];

    Logger();
    ~Logger();

    static char* getSystemTime();
    static char* getGameTime();

  protected:
  public:
    static const int LVL_NONE = 0;
    static const int LVL_FATAL = 1;
    static const int LVL_ERROR = 2;
    static const int LVL_WARN = 3;
    static const int LVL_INFO = 4;
    static const int LVL_DEBUG = 5;

    static bool setFile(std::string filepath, int level);
    static void setLevel(int level);
    static void log(std::string message, int level);
    static void debug(std::string message);
    static void info(std::string message);
    static void warn(std::string message);
    static void error(std::string message);
    static void fatal(std::string message);
};

#endif
