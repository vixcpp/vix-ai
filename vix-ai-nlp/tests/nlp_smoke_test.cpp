#include <cstdlib>
#include <vector>
#include <string>
#include <vix/ai/nlp/Tokenizer.hpp>
#include <vix/ai/nlp/Embedding.hpp>
#include <vix/ai/nlp/Pipeline.hpp>
#include <vix/ai/nlp/ModelLoader.hpp>

int main()
{
    using namespace vix::ai::nlp;

    Tokenizer tok;
    auto t = tok.tokenize("hello");
    if (t.size() != 1)
        return EXIT_FAILURE;
    Embedding emb;
    auto v = emb.encode("hello");
    if (v.empty())
        return EXIT_FAILURE;
    Pipeline pipe;
    if (pipe.summarize("x") != "x")
        return EXIT_FAILURE;
    ModelLoader loader;
    if (!loader.load("/dev/null"))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}