//
// Created by Tomáš Petříček on 26.06.2023.
//

#ifndef LEET_CODE_FIZZ_BUZZ_MULTITHREADED_HPP
#define LEET_CODE_FIZZ_BUZZ_MULTITHREADED_HPP

#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>

namespace leet_code {
    class FizzBuzz {
        int n, i{1};
        std::mutex m;
        std::condition_variable cv;

    public:
        explicit FizzBuzz(int n)
                :n{n} { }

        // printFizz() outputs "fizz".
        void fizz(const std::function<void()>& printFizz)
        {
            std::unique_lock<std::mutex> lock(m);
            while (i<=n) {
                while ((i<=n) && !((i%3==0) && (i%5!=0))) {
                    cv.wait(lock);
                }
                if (i<=n) {
                    printFizz();
                    i++;
                }
                cv.notify_all();
            }
        }

        // printBuzz() outputs "buzz".
        void buzz(const std::function<void()>& printBuzz)
        {
            std::unique_lock<std::mutex> lock(m);
            while (i<=n) {
                while ((i<=n) && !((i%5==0) && (i%3!=0))) {
                    cv.wait(lock);
                }
                if (i<=n) {
                    printBuzz();
                    i++;
                }
                cv.notify_all();
            }
        }

        // printFizzBuzz() outputs "fizzbuzz".
        void fizzbuzz(const std::function<void()>& printFizzBuzz)
        {
            std::unique_lock<std::mutex> lock(m);
            while (i<=n) {
                while ((i<=n) && !((i%3==0) && (i%5==0))) {
                    cv.wait(lock);
                }
                if (i<=n) {
                    printFizzBuzz();
                    i++;
                }
                cv.notify_all();
            }
        }

        // printNumber(x) outputs "x", where x is an integer.
        void number(const std::function<void(int)>& printNumber)
        {
            std::unique_lock<std::mutex> lock(m);
            while (i<=n) {
                while ((i<=n) && !((i%3!=0) && (i%5!=0))) {
                    cv.wait(lock);
                }
                if (i<=n) {
                    printNumber(i);
                    i++;
                }
                cv.notify_all();
            }
        }
    };

    void test_fizz_buzz_multithreaded()
    {
        auto b = FizzBuzz(15);
        std::thread t1{[&b] { b.buzz([] { std::cout << "buzz, " << std::endl; }); }};
        std::thread t2{[&b] { b.fizz([] { std::cout << "fizz, " << std::endl; }); }};
        std::thread t3{[&b] { b.fizzbuzz([] { std::cout << "fizzbuzz, " << std::endl; }); }};
        std::thread t4{[&b] { b.number([](int num) { std::cout << num << ", " << std::endl; }); }};
        t1.join(), t2.join(), t3.join(), t4.join();
        std::cout.flush();
    }
}

#endif //LEET_CODE_FIZZ_BUZZ_MULTITHREADED_HPP
