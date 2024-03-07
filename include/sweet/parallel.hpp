/*--------------------------------------------------------------------------------*/
/*                                   MIT License                                  */
/*                          Copyright (c) 2024 Hato1125                           */
/*--------------------------------------------------------------------------------*/
/* Permission is hereby granted, free of charge, to any person obtaining a copy   */
/* of this software and associated documentation files (the "Software"), to deal  */
/* in the Software without restriction, including without limitation the rights   */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      */
/* copies of the Software, and to permit persons to whom the Software is          */
/* furnished to do so, subject to the following conditions:                       */
/*                                                                                */
/* The above copyright notice and this permission notice shall be included in all */
/* copies or substantial portions of the Software.                                */
/*                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/* SOFTWARE.                                                                      */
/*--------------------------------------------------------------------------------*/

#ifndef _LIBSWEET_COMMON_PARALLEL_HPP
#define _LIBSWEET_COMMON_PARALLEL_HPP

#include <vector>
#include <future>
#include <thread>
#include <functional>

namespace sweet {
template <typename ReturnType>
class parallel {
using rtype_function = std::function<ReturnType()>;
using rtype_future = std::future<ReturnType>;

public:
  parallel(
    const std::launch policy,
    const std::vector<rtype_function> &functions
  ) noexcept {
    for(auto &func : functions)
      _futures.push_back(std::async(policy, func));
  }

  std::vector<ReturnType> stand_by() noexcept {
    std::vector<ReturnType> result{ };
    for(auto &future : _futures)
      result.push_back(future.get());
    return result;
  }

private:
  std::vector<rtype_future> _futures;
};

template <>
class parallel<void> {
using rtype_function = std::function<void()>;

public:
  parallel(
    const std::vector<rtype_function> &functions
  ) noexcept {
    for(auto &func : functions)
      _threads.emplace_back(func);
  }

  void stand_by() noexcept {
    for(auto &thread: _threads)
      thread.join();
  }

private:
  std::vector<std::thread> _threads;
};
}

#endif
