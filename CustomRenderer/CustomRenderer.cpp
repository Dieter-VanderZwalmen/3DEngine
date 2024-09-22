#include "../IRenderer.h"

class CustomRenderer : public IRenderer {
public:
    void Initialize() override {
        // Your custom initialization code
    }

    void Clear() override {
        // Your custom clear screen code
    }

    void Render() override {
        // Your custom rendering code
    }

    void Shutdown() override {
        // Your custom cleanup code
    }
};