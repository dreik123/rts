//
// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const asio::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

int main()
{
  asio::io_context io;

  asio::deadline_timer t(io, boost::posix_time::seconds(5));
  t.async_wait(&print);

  io.run();

  return 0;
}
