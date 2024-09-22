#pragma once

class IRenderer {
public:
    virtual void Initialize() = 0;  // Initialize the renderer
    virtual void Clear() = 0;       // Clear the screen
    virtual void Render() = 0;      // Render the scene
    virtual void Shutdown() = 0;    // Clean up resources
    virtual ~IRenderer() = default; //  destructor for the class
};