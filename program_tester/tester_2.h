#ifndef PERFORMANCE_MONITOR_H
#define PERFORMANCE_MONITOR_H

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <psapi.h>

class PerformanceMonitor
{
public:
    PerformanceMonitor() {} 

    void start()
    {
        start_time_ = std::chrono::high_resolution_clock::now();    // 获取开始时间
        start_memory_ = get_current_memory_usage().PrivateUsage;    // 获取开始内存使用量
    }

    void stop(const std::string &function_name)
    {
        auto end_time = std::chrono::high_resolution_clock::now();  // 获取结束当前时间
        auto end_memory = get_current_memory_usage().PrivateUsage;  // 结束内存使用量

        auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time_);  // 计算耗时
        auto memory_usage = (end_memory - start_memory_);           // 计算内存使用量 (单位: byte)    

        std::cout << "Function " << function_name << " took " << elapsed_time.count() << " microseconds and used " << memory_usage << " bytes of memory." << std::endl;

        function_names_.push_back(function_name);
        elapsed_times_.push_back(elapsed_time.count());
        memory_usages_.push_back(memory_usage);
        total_memory_usage_ += memory_usage;                        // 计算总内存使用量 (单位: byte)
    }

    void stop_without_output(const std::string &function_name)
    {
        auto end_time = std::chrono::high_resolution_clock::now();  // 获取结束当前时间
        auto end_memory = get_current_memory_usage().PrivateUsage;  // 结束内存使用量

        auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time_);  // 计算耗时
        auto memory_usage = (end_memory - start_memory_);           // 计算内存使用量 (单位: byte)    

        function_names_.push_back(function_name);
        elapsed_times_.push_back(elapsed_time.count());
        memory_usages_.push_back(memory_usage);
        total_memory_usage_ += memory_usage;                        // 计算总内存使用量 (单位: byte)
    }

    void print_summary()
    {
        std::cout << "Summary of function performance:" << std::endl;
        // for (int i = 0; i < function_names_.size(); ++i)
        // {
        //     std::cout << "Function " << function_names_[i] << " took " << elapsed_times_[i] << " microseconds and used " << memory_usages_[i] << " bytes of memory." << std::endl;
        // }
        std::cout << "Total time usage: " << elapsed_times_[0] / (1e6) << " seconds." << std::endl;
        std::cout << "Total memory usage: " << total_memory_usage_ / (1024 * 1024.0) << " megabytes " << std::endl;
    }

private:
    std::chrono::high_resolution_clock::time_point start_time_;
    SIZE_T start_memory_;
    std::vector<std::string> function_names_;
    std::vector<long long> elapsed_times_;
    std::vector<SIZE_T> memory_usages_;
    SIZE_T total_memory_usage_ = 0;

    PROCESS_MEMORY_COUNTERS_EX get_current_memory_usage()
    {
        PROCESS_MEMORY_COUNTERS_EX pmc;                                      // 用于获取内存信息
        GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc)); // 获取内存信息

        return pmc;
    }
};

PerformanceMonitor performance_monitor;

#define MONITOR_FUNCTION_BEGIN() performance_monitor.start()
#define MONITOR_FUNCTION_END() performance_monitor.stop(__FUNCTION__)
#define MONITOR_FUNCTION_END_WITHOUT_OUTPUT() performance_monitor.stop_without_output(__FUNCTION__)

#endif // PERFORMANCE_MONITOR_H

#ifndef ARRAYS_TOOL_H
#define ARRAYS_TOOL_H
#include <chrono>
#include <random>
#include <vector>

void Fill(std::vector<int> &nums, long long border, std::pair<int, int> range, std::string order = "rand")
{
    std::random_device rd;
    std::mt19937 gen(rd());
    if (order == "rand")
    {
        std::uniform_int_distribution<> dis(range.first, range.second);
        for (long long i = 0; i < border; i++)
        {
            nums.push_back(dis(gen));
        }
    }
    else if (order == "normal")
    {
        std::normal_distribution<> dis(range.first, range.second);
        for (long long i = 0; i < border; i++)
        {
            nums.push_back(dis(gen));
        }
    }
    else if (order == "asc")
    {
        for (long long i = 0; i < border; i++)
        {
            nums.push_back(i);
        }
    }
    else if (order == "desc")
    {
        for (long long i = border; i > 0; i--)
        {
            nums.push_back(i);
        }
    }
    else
    {
        std::cout << "Wrong order!" << std::endl;
    }
}

bool isSorted(std::vector<int> &nums)
{
    for (unsigned int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return false;
    }
    return true;
}

#endif // ARRAYS_TOOL_H