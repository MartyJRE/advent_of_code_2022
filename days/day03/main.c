#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prioritize(char* name, char* fileName)
{
    FILE* fd = fopen(fileName, "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", fileName);
        exit(1);
    }
    size_t lineIndex = 0;
    char* line = NULL;
    char found[10000] = {0};
    size_t idx = 0;
    while (getline(&line, &lineIndex, fd) != -1)
    {
        line[strcspn(line, "\n")] = '\0';
        const size_t len = strlen(line);
        const size_t first = len / 2;
        const size_t second = len - first;
        assert(first == second);
        bool done = false;


        for (size_t i = 0; i < first; ++i)
        {
            if (done)
            {
                break;
            }
            const char x = line[i];
            for (size_t j = 0; j < second; j++)
            {
                const char y = line[first + j];
                if (x == y)
                {
                    found[idx] = x;
                    done = true;
                    break;
                }
            }
        }
        idx++;
    }
    int sum = 0;
    for (size_t i = 0; i < idx; ++i)
    {
        int prio = found[i] - 96;
        if (prio < 1)
        {
            prio += 58;
        }
        sum += prio;
    }

    fprintf(stdout, "Sum (%s): %d\n", name, sum);
}

void findBadges(char* name, char* fileName)
{
    FILE* fd = fopen(fileName, "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", fileName);
        exit(1);
    }
    size_t lineIndex = 0;
    char* line = NULL;
    size_t idx = 0;
    char* lines[10000];
    while (getline(&line, &lineIndex, fd) != -1)
    {
        lines[idx++] = strdup(line);
    }
    char badges[10000];
    size_t badgesIdx = 0;
    for (size_t i = 0; i < idx; i += 3)
    {
        bool done = false;
        const size_t aLen = strlen(lines[i]);
        const size_t bLen = strlen(lines[i + 1]);
        const size_t cLen = strlen(lines[i + 2]);
        for (size_t a = 0; a < aLen; a++)
        {
            if (done)
            {
                break;
            }
            const char aChar = lines[i][a];
            for (size_t b = 0; b < bLen; b++)
            {
                if (done)
                {
                    break;
                }
                const char bChar = lines[i + 1][b];
                for (size_t c = 0; c < cLen; c++)
                {
                    const char cChar = lines[i + 2][c];
                    if (aChar == bChar && bChar == cChar)
                    {
                        badges[badgesIdx++] = lines[i][a];
                        done = true;
                        break;
                    }
                }
            }
        }
    }
    int sum = 0;
    for (size_t i = 0; i < badgesIdx; ++i)
    {
        int prio = badges[i] - 96;
        if (prio < 1)
        {
            prio += 58;
        }
        sum += prio;
    }

    fprintf(stdout, "Sum (%s): %d\n", name, sum);
}

int main()
{
    prioritize("Example 1", "./example.txt");

    prioritize("Part 1", "./input.txt");

    findBadges("Example 2", "./example.txt");

    findBadges("Part 2", "./input.txt");

    return 0;
}
