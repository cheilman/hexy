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

## Other Rules
- ABSOLUTELY NEVER run destructive git operations (e.g., git reset --hard, rm, git checkout/git restore to an older commit) unless the user gives an explicit, written instruction in this conversation. Treat these commands as catastrophic; if you are even slightly unsure, stop and ask before touching them. (When working within Cursor or Codex Web, these git limitations do not apply; use the tooling's capabilities as needed.)
- Delete unused or obsolete files when your changes make them irrelevant (refactors, feature removals, etc.), and revert files only when the change is yours or explicitly requested. If a git operation leaves you unsure about other agents' in-flight work, stop and coordinate instead of deleting.
- Before attempting to delete a file to resolve a local type/lint failure, stop and ask the user. Other agents are often editing adjacent files; deleting their work to silence an error is never acceptable without explicit approval.
- Moving/renaming and restoring files is allowed.
- Always double-check git status before any commit
- Keep commits atomic: commit only the files you touched and list each path explicitly. For tracked files run git commit -m "<scoped message>" -- path/to/file1 path/to/file2. For brand-new files, use the one-liner git restore --staged :/ && git add "path/to/file1" "path/to/file2" && git commit -m "<scoped message>" -- path/to/file1 path/to/file2.
- Quote any git paths containing brackets or parentheses (e.g., src/app/[candidate]/**) when staging or committing so the shell does not treat them as globs or subshells.
- Never amend commits unless you have explicit written approval in the task thread.
