#include <iostream>
#include "byfolder_calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"

void calculate(const QString &path, CalculationStrategy *strategy)
{
    auto result = strategy->calculate(path);
    for (const auto &p : result) {
        if (p.second == 0.0)
            continue;

        printf(p.first.toStdString().data());

        if (p.second < 0.01) {
            printf(": < 0.01%%\n");
        } else {
            printf(": %5.2f%%\n", p.second);
        }
    }
}

int main()
{
    ByFolder_CalculationStrategy byFolder;
    calculate(".", &byFolder);
    printf("\n\n");
    ByFileType_CalculationStrategy byFileType;
    calculate(".", &byFileType);
    return 0;
}
