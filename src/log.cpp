#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>

void log(const std::string& message) {
    // Get the current time
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::chrono::milliseconds ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()) %
        1000;

    // Convert the time to a string
    char buffer[20];
    std::strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", std::localtime(&time));

    // Print the log message with the current time
    std::cout << "[" << buffer << "," << std::setfill('0') << std::setw(3)
              << ms.count() << "] " << message << std::endl;
}
