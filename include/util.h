/*
  +----------------------------------------------------------------------+
  | Yasd                                                                 |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: codinghuang  <codinghuang@qq.com>                            |
  +----------------------------------------------------------------------+
*/

#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>

#include "main/php.h"

namespace yasd {
class Util {
  public:
    static std::vector<std::string> explode(const std::string &str, const std::string &delimiter);

    static HashTable *get_defined_vars();
    static zval *find_variable(std::string var_name);
    static void print_var(std::string var_name);
    static void print_property(std::string obj_name, std::string property_name);

    static void printf_info(int color, const char *format, ...);

    template <typename... Args>
    static void printfln_info(int color, const char *format, Args... args) {
        printf_info(color, format, args...);
        std::cout << std::endl;
    }

    static void show_breakpoint_hit_info();
    static const char *get_executed_filename();
    static int get_executed_file_lineno();
    static const char *get_prev_executed_filename();
    static int get_prev_executed_file_lineno();
    static bool is_match(std::string sub_str, std::string target_str);

    static void reload_cache_breakpoint();
    static void clear_breakpoint_cache_file();
    static std::string get_breakpoint_cache_filename();
    static void cache_breakpoint(std::string filename, int lineno);

    static bool is_variable_equal(zval *op1, zval *op2);
    static bool is_variable_smaller(zval *op1, zval *op2);
    static bool is_variable_greater(zval *op1, zval *op2);

    static bool is_hit_watch_point();

    static bool is_integer(const std::string & s);
};
}  // namespace yasd
