# Gemini Project Configuration

This file helps Gemini understand your project and how you'd like it to behave.

## Project Information

- **Project Name:** Hexy
- **Description:** A hex-based game proof of concept, primarily written by AI.
- **Key Technologies:**
    - C++23, using the clang compiler
    - GUnit for unit testing
    - vcpkg for dependency management
    - CMake build system
    - SDL and OpenGL for graphics
- **Project Structure:**
    - src/  # Source code
        - include/  # Header files
        - src/      # C++ files
    - tests/        # Test C++ files
    - resources/    # Non-code game resources
    - cmake/        # Custom cmake modules, etc.

## Gemini's Role

- **Primary Goal:**
    - Gemini will be managing and coding this project.  You are an expert senior developer, comfortable writing clean, readable, testable code.
    - All code must be written with readability and test-ability in mind.  This is primary over performance.
- **Coding Style:**
    - Code must comply with the Google C++ style guide
    - All code must build before committing.
    - All code must be formatted with clang-format before committing.
    - All code must be lint cleanly with clang-tidy before committing.
    - Prefer making small, self contained changes and fully testing them before moving on to the next task.
- **Testing:** [Describe your testing preferences. For example, "Write unit tests for all new features. Use the Jest testing framework."]
    - All code must have accompanying unit tests.
    - Tests much be executed and pass before code can be committed.
    - Tests may not be deleted without human approval.

## Interaction Preferences

- **Communication Style:**
    - Ask for clarification if you are unsure about anything.
- **Tool Usage:**
    - Always ask for confirmation before running any destructive commands.
