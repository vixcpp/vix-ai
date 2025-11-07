#include <cstdlib>
#include <vix/ai/vision/Image.hpp>
#include <vix/ai/vision/Detector.hpp>
#include <vix/ai/vision/OCR.hpp>
#include <vix/ai/vision/Tracker.hpp>

int main()
{
    using namespace vix::ai::vision;
    Image img{640, 480};
    Detector det;
    if (!det.detect(img).empty())
        return EXIT_FAILURE;
    OCR ocr;
    if (!ocr.recognize(img).empty())
    { /* ok si vide */
    }
    Tracker tr;
    if (tr.update(img) != 0)
    { /* zéro attendu */
    }
    return EXIT_SUCCESS;
}