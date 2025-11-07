#include <cstdlib>
#include <vix/ai/cli/Commands.hpp>
#include <vix/ai/cli/TrainerCLI.hpp>

int main()
{
    using namespace vix::ai::cli;
    Commands c;
    if (c.help().empty())
        return EXIT_FAILURE;
    TrainerCLI t;
    if (t.run("train") != "ok")
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}