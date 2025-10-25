#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define ROCK_VALUE 1
#define ROCK_LEFT 'A'
#define ROCK_RIGHT 'X'
#define LOSE 'X'
#define LOSE_VALUE 0
#define PAPER_VALUE 2
#define PAPER_LEFT 'B'
#define PAPER_RIGHT 'Y'
#define DRAW 'Y'
#define DRAW_VALUE 3
#define SCISSORS_VALUE 3
#define SCISSORS_LEFT 'C'
#define SCISSORS_RIGHT 'Z'
#define WIN 'Z'
#define WIN_VALUE 6

void considerPlanPart2(char* name, char* fileName)
{
    FILE* fd = fopen(fileName, "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", fileName);
        exit(1);
    }
    size_t lineIndex = 0;
    char* line = NULL;
    int myScore = 0;
    while (getline(&line, &lineIndex, fd) != -1)
    {
        const char opponent = line[0];
        const char resolution = line[2];
        switch (opponent)
        {
        case ROCK_LEFT:
            {
                switch (resolution)
                {
                case LOSE:
                    {
                        myScore += SCISSORS_VALUE;
                        myScore += LOSE_VALUE;
                        break;
                    }
                case DRAW:
                    {
                        myScore += ROCK_VALUE;
                        myScore += DRAW_VALUE;
                        break;
                    }
                case WIN:
                    {
                        myScore += PAPER_VALUE;
                        myScore += WIN_VALUE;
                        break;
                    }
                default:
                    {
                        fprintf(stderr, "Invalid character %c\n", opponent);
                        exit(1);
                    }
                }
                break;
            }
        case PAPER_LEFT:
            {
                switch (resolution)
                {
                case LOSE:
                    {
                        myScore += ROCK_VALUE;
                        myScore += LOSE_VALUE;
                        break;
                    }
                case DRAW:
                    {
                        myScore += PAPER_VALUE;
                        myScore += DRAW_VALUE;
                        break;
                    }
                case WIN:
                    {
                        myScore += SCISSORS_VALUE;
                        myScore += WIN_VALUE;
                        break;
                    }
                default:
                    {
                        fprintf(stderr, "Invalid character %c\n", opponent);
                        exit(1);
                    }
                }
                break;
            }
        case SCISSORS_LEFT:
            {
                switch (resolution)
                {
                case LOSE:
                    {
                        myScore += PAPER_VALUE;
                        myScore += LOSE_VALUE;
                        break;
                    }
                case DRAW:
                    {
                        myScore += SCISSORS_VALUE;
                        myScore += DRAW_VALUE;
                        break;
                    }
                case WIN:
                    {
                        myScore += ROCK_VALUE;
                        myScore += WIN_VALUE;
                        break;
                    }
                default:
                    {
                        fprintf(stderr, "Invalid character %c\n", opponent);
                        exit(1);
                    }
                }
                break;
            }
        default:
            {
                fprintf(stderr, "Invalid character %c\n", opponent);
                exit(1);
            }
        }
    }
    fprintf(stdout, "My score (%s): %d\n", name, myScore);
}

void considerPlanPart1(char* name, char* fileName)
{
    FILE* fd = fopen(fileName, "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", fileName);
        exit(1);
    }
    size_t lineIndex = 0;
    char* line = NULL;
    int myScore = 0;
    while (getline(&line, &lineIndex, fd) != -1)
    {
        const char opponent = line[0];
        const char me = line[2];
        switch (me)
        {
        case ROCK_RIGHT:
            {
                myScore += ROCK_VALUE;
                switch (opponent)
                {
                case ROCK_LEFT:
                    {
                        myScore += DRAW_VALUE;
                        break;
                    }
                case PAPER_LEFT:
                    {
                        myScore += LOSE_VALUE;
                        break;
                    }
                case SCISSORS_LEFT:
                    {
                        myScore += WIN_VALUE;
                        break;
                    }
                default:
                    {
                        fprintf(stderr, "Invalid character %c\n", me);
                        exit(1);
                    }
                }
                break;
            }
        case PAPER_RIGHT:
            {
                myScore += PAPER_VALUE;
                switch (opponent)
                {
                case ROCK_LEFT:
                    {
                        myScore += WIN_VALUE;
                        break;
                    }
                case PAPER_LEFT:
                    {
                        myScore += DRAW_VALUE;
                        break;
                    }
                case SCISSORS_LEFT:
                    {
                        myScore += LOSE_VALUE;
                        break;
                    }
                default:
                    {
                        fprintf(stderr, "Invalid character %c\n", me);
                        exit(1);
                    }
                }
                break;
            }
        case SCISSORS_RIGHT:
            {
                myScore += SCISSORS_VALUE;
                switch (opponent)
                {
                case ROCK_LEFT:
                    {
                        myScore += LOSE_VALUE;
                        break;
                    }
                case PAPER_LEFT:
                    {
                        myScore += WIN_VALUE;
                        break;
                    }
                case SCISSORS_LEFT:
                    {
                        myScore += DRAW_VALUE;
                        break;
                    }
                default:
                    {
                        fprintf(stderr, "Invalid character %c\n", me);
                        exit(1);
                    }
                }
                break;
            }
        default:
            {
                fprintf(stderr, "Invalid character %c\n", me);
                exit(1);
            }
        }
    }
    fprintf(stdout, "My score (%s): %d\n", name, myScore);
}

int main()
{
    considerPlanPart1("Example 1", "./example.txt");

    considerPlanPart1("Part 1", "./input.txt");

    considerPlanPart2("Example 2", "./example.txt");

    considerPlanPart2("Part 2", "./input.txt");

    return 0;
}
