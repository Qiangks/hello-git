//
// Created by chnvideo on 2016/2/2.
//

#ifndef F4V_PARSEER_HPP
#define F4V_PARSEER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <stdint.h>
#include "f4v_box.hpp"

class IF4vParser
{
public:
    IF4vParser();
    virtual ~IF4vParser();
private:
    virtual int read(uint64_t start, uint64_t end) = 0;
    virtual int parse() = 0;
public:
    virtual void show_box() = 0;
};

class F4vFileParser : virtual public IF4vParser
{
private:
    FILE * fp;
    std::string name;
    bool is_eof;
    std::vector<F4vBoxAtom*> f4v_atomes;
public:
    F4vFileParser(std::string str);
    virtual ~F4vFileParser();
public:
    int initialize();
    
    int start();
// IF4vParser
private:
    int read(uint64_t start, uint64_t end);
    int parse();
public:
    void show_box();
private:
    int64_t get_filesize();
private:
    void parse_ftyp(F4vBoxAtom** ppfb);
    void parse_moov(F4vBoxAtom** ppfb);
};

#endif //F4V_PARSEER_F4V_READ_HPP
