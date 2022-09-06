#include "time.h"

class System
{
    public:
        System();
        ~System();
        void run();

    private:
        int option;
        double calcRuntime(clock_t start);
        int printBasicMenu();
        int printCompleteMenu();
        void evaluateMenuOption(int option);
};
