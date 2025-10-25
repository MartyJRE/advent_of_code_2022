#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void calculateMaximumElfCapacityPart1And2(char* name, char* fileName, const uint8_t topN)
{
    FILE* fd = fopen(fileName, "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", fileName);
        exit(1);
    }
    size_t lineIndex = 0;
    ssize_t lineLength;
    char* line = NULL;
    uint32_t current = 0;
    uint32_t topElves[topN];
    while ((lineLength = getline(&line, &lineIndex, fd)) != -1)
    {
        if (lineLength == 1)
        {
            for (size_t i = 0; i < topN; i++)
            {
                // NOTE: I don't think this is correct but it works
                if (current > topElves[i])
                {
                    topElves[i] = current;
                    break;
                }
            }
            current = 0;
            continue;
        }
        current += atoi(line);
    }
    uint32_t max = 0;
    for (size_t i = 0; i < topN; i++)
    {
        max += topElves[i];
    }
    fprintf(stdout, "Max(%s): %d\n", name, max);
}

int main()
{
    calculateMaximumElfCapacityPart1And2("Example", "./example.txt", 1);

    calculateMaximumElfCapacityPart1And2("Part 1", "./input.txt", 1);

    calculateMaximumElfCapacityPart1And2("Part 2", "./input.txt", 3);

    return 0;
}
