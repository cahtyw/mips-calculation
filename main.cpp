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
  std::cout << "*** WELCOME TO THE MIPS CALCULATOR, by: Gabriel Santos ***" << std::endl
            << std::endl
            << std::endl
            << std::endl
            << std::endl;
}

int inputInt(const char *e)
{
  int value = 0;
  while (true)
  {
    value = 0;

    try
    {

      std::cout
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

      std::cout
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
      std::cout << "*** Choose one of these options" << std::endl
                << "1. Calculate MIPS average" << std::endl
                << "2. Compare last " << MAX_MACHINES << " MIPS results" << std::endl
                << "3. Exit" << std::endl
                << std::endl;

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
                << "ERROR: " << e << std::endl
                << std::endl;
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
        GERAL_COUNT = 0;
        int cont = 0;
        do
        {
          int instructions = 0;
          int executionTimeInSeconds = 0;
          float clock = 0;

          std::cout << std::endl
                    << "++ Machine code #[0000x" << (cont + 1) << "], follow the instructions: " << std::endl;

          while (!instructions || !executionTimeInSeconds || !clock)
          {
            try
            {
              while (!instructions)
              {
                instructions = inputInt("> Insert an number of instructions: ");
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
                    << "== Machine code #[0000x" << i << "] [MIPS] = " << payload[i][0];
          std::cout << std::endl
                    << "== Machine code #[0000x" << i << "] [CPI] = " << payload[i][1]
                    << std::endl;
        }
        std::cout << std::endl;

        system("pause");

        break;
      }
      case 2:
      {

        double bestMips = 0;
        double bestCPI = 0;
        int bestMachineMips = 0;
        int bestMachineCPI = 0;

        for (int i = 0; i < MAX_MACHINES; i++)
        {
          if (payload[i][0] > bestMips || !i)
          {
            bestMachineMips = i + 1;
            bestMips = payload[i][0];
          }

          if (payload[i][1] < bestCPI || !i)
          {
            bestMachineCPI = i + 1;
            bestCPI = payload[i][1];
          }
        }

        std::cout << std::endl
                  << ">>>>> Follow the comparation results:";

        std::cout << std::endl
                  << "== Best Machine in MIPS category = " << bestMachineMips << std::endl
                  << "\tWith value: " << bestMips;

        std::cout << std::endl
                  << std::endl
                  << "== Best Machine in CPI category = " << bestMachineCPI << std::endl
                  << "\tWith value: " << bestCPI
                  << std::endl
                  << std::endl
                  << std::endl
                  << std::endl;

        system("pause");

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