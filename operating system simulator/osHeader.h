#ifndef OS_HEADER_H
#define OS_HEADER_H

#define OSVERSION 1.0

enum command{quit, version, date, help};

//command hashIt (string const& input);
command hashIt (std::string const& input);
void printfOSVersion(void);
void printStartUp(void);
bool exitSimulator();
void getDate(void);


#endif
