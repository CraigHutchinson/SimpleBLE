#pragma once

#include <simplebluez/Bluez.h>
#include <atomic>
#include <thread>

namespace SimpleBLE {

class Bluez {
  public:
    static Bluez* get();

    SimpleBluez::Bluez bluez;

  private:
    Bluez();
    ~Bluez();
    Bluez(Bluez& other) = delete;           // Remove the copy constructor
    void operator=(const Bluez&) = delete;  // Remove the copy assignment

    std::thread async_thread;
    std::atomic_bool async_thread_active;
    void async_thread_function();

    void start_async_thread();
    void stop_async_thread();

    static void set_fork_handlers();

};

}  // namespace SimpleBLE
