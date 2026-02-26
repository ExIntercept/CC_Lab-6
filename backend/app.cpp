#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main() {
    char hostname[1024];
    gethostname(hostname, 1024);

    std::cout << "Content-type: text/plain\r\n\r\n";
    std::cout << "Served by backend: " << hostname << std::endl;
    return 0;
}
