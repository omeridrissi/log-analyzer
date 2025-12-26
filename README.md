# Logalyzer - Log File Analyzer

A fast, lightweight log analysis tool written in C for processing system and application logs. Provides instant visibility into error frequency and message patterns.

## Features

- **High-performance parsing** using optimized C file I/O
- **Real-time severity counting** (ERROR, WARNING, INFO, DEBUG, OTHER)
- **Dual output streams** - terminal display and file report
- **Command-line ready** for scripting and automation
- **Memory efficient** - processes files of any size via streaming

## Installation

```bash
# Clone repository
git clone https://github.com/yourusername/logalyzer.git
cd logalyzer

# Compile
gcc -o logalyzer analyzer.c

# Make executable
chmod +x logalyzer
