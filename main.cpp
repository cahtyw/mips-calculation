#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <math.h>

using namespace std;

const char *ERROR_VALUE_MESSAGE = "The value inserted is invalid, please try again!";
const float POW_CONSTANT = pow(10, 6);
const int MAX_MACHINES = 2;
double payload[MAX_MACHINES][2];
int GERAL_COUNT = 0;

void drawMenu()
{
  system("cls");
  std::cout
      << "---------------------------" << std::endl;
  std::cout << "---------------------------" << std::endl;
  std::cout << "-V  WELCOME TO THE CU !  V-" << std::endl;
  std::cout << "---------------------------" << std::endl;
  std::cout << "---------------------------" << std::endl;
}

int inputInt(const char *e)
{
  int value = 0;
  while (true)
  {
    value = 0;

    try
    {

      std::cout << std::endl
                << std::endl
                << e;

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if ((std::cin >> value))
      {
        return value;
      }

      throw ERROR_VALUE_MESSAGE;
    }
    catch (const char *e)
    {
      throw e;
    }
  }
}

float inputFloat(const char *e)
{
  float value = 0;
  while (true)
  {
    value = 0;

    try
    {

      std::cout << std::endl
                << std::endl
                << e;

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if ((std::cin >> value))
      {
        return value;
      }

      throw ERROR_VALUE_MESSAGE;
    }
    catch (const char *e)
    {
      throw e;
    }
  }
}

int getOption()
{
  while (true)
  {
    try
    {
      const int option = inputInt(">> Choose an option: ");

      if (option > 0 && option < 4)
      {
        return option;
      }

      throw "The option inserted is invalid, please try again!";
    }
    catch (const char *e)
    {
      std::cout << std::endl
                << "ERROR: " << e;
    }
  }
}

void calculate(float instructions, float executionTimeInSeconds, float clock)
{
  const double mips = (instructions * POW_CONSTANT) / (executionTimeInSeconds * POW_CONSTANT);
  const double cpi = (clock * POW_CONSTANT) / (mips * POW_CONSTANT);

  payload[GERAL_COUNT][0] = mips;
  payload[GERAL_COUNT++][1] = cpi;
}

void exitProgram()
{
  std::cout << "See ya' anytime!" << std::endl;
  system("pause");
  exit(0);
}

int main()
{
  while (true)
  {
    try
    {
      drawMenu();

      int option = getOption();

      switch (option)
      {
      case 1:
      {
        int cont = 0;
        do
        {
          int instructions = 0;
          int executionTimeInSeconds = 0;
          float clock = 0;

          while (!instructions || !executionTimeInSeconds || !clock)
          {
            try
            {
              while (!instructions)
              {
                instructions = inputInt(">> Insert an number of instructions: ");
              }

              while (!executionTimeInSeconds)
              {
                executionTimeInSeconds = inputInt("> Insert an execution time in seconds: ");
              }

              while (!clock)
              {
                clock = inputFloat("> Insert an clock speed (MHz): ");
              }
            }
            catch (const char *e)
            {
              std::cout << std::endl
                        << "ERROR: " << e;
            }
          }
          calculate(static_cast<float>(instructions), static_cast<float>(executionTimeInSeconds), clock);
        } while (++cont < MAX_MACHINES);

        std::cout << std::endl
                  << std::endl
                  << ">>>>>>>>> CHECK YOUR RESULTS: ";

        for (int i = 0; i < MAX_MACHINES; i++)
        {
          std::cout << std::endl
                    << "== Machine (" << i << ") [MIPS] = " << payload[i][0];
          std::cout << std::endl
                    << "== Machine (" << i << ") [CPI] = " << payload[i][1]
                    << std::endl;
        }
        std::cout << std::endl;

        system("pause");

        break;
      }
      case 2:
      {
        std::cout << "SECOND OPTION" << std::endl;
        break;
      }
      case 3:
      {
        exitProgram();
        break;
      }
      default:
      {
        std::cout << "FOURTH OPTION" << std::endl;
        break;
      }
      }
    }
    catch (const char *e)
    {
      std::cout << "ERROR: " << std::endl;
    }

    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl;
  }
}