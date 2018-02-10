// ProgrammingInterview.cpp : Defines the entry point for the console application.
//

#include "targetver.h"

#include <stdio.h>
#include <cstring>
#include <thread>
#include <mutex>

std::mutex myMutex;
bool locked = true;

class ClassOne
{
public:
    ClassOne()
    {
        printf("ClassOne Constructor\n");
    }

    ~ClassOne()
    {
        printf("ClassOne Destructor\n");
    }

    void Function()
    {
        printf("ClassOne Function\n");
    }
};

class ClassTwo : public ClassOne
{
public:
    ClassTwo()
    {
        printf("ClassTwo Constructor\n");
    }

    ~ClassTwo()
    {
        printf("ClassTwo Destructor\n");
    }

    void Function()
    {
        printf("ClassTwo Function\n");
    }
};

void InMemoryReverse(char* buffer, int length)
{
    for (int index = 0; index < length; ++index)
    {
        auto temp = buffer[index];
        buffer[index] = buffer[length - index];
        buffer[length - index] = temp;
    }
}

void Multithreaded(int count)
{
    while (locked);

    printf("Multi-threaded: %d", count);
}

int main(int argc, char* argv[])
{
    //- InMemoryReverse
    printf("--- InMemoryReverse ---\n");
    char reversableText[] = "This text should be reversed.";
    InMemoryReverse(reversableText, strlen(reversableText));

    printf("InMemoryReverse: %s\n", reversableText);

    //- Object Oriented
    printf("--- Object Oriented ---\n");
    ClassOne one;
    one.Function();

    //- Multi-threaded
    printf("--- Multi-threaded ---\n");
    std::thread threads[10];
    for (int count = 0; count <= 10; ++count)
        threads[count] = std::thread(Multithreaded, count);

    locked = false;

    for (int count = 0; count < 10; ++count)
        threads[count].join();

	return 0;
}

