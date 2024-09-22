#include "../IRenderer.h"

class DirectXRenderer : public IRenderer {
public:
    void Initialize() override {
        // DirectX initialization code
    }

    void Clear() override {
        // DirectX clear screen code
    }

    void Render() override {
        // DirectX rendering code
    }

    void Shutdown() override {
        // DirectX cleanup code
    }
};