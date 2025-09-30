Digital Clock in C
A feature-rich digital clock application written in C with real-time display, alarm functionality, and smooth console interface.

📋 Features
⏰ Real-time Clock Display - Shows current system time with smooth updates

🔔 Alarm System - Set custom alarms with audible notifications

🕹️ Manual Time Setting - Override system time with custom values

🎯 User-friendly Interface - Clean console-based menu system

🌙 AM/PM Format - 12-hour time format support

⚡ Smooth Updates - Time updates in place without screen flickering

🚀 Getting Started
Prerequisites
Windows OS (uses Windows-specific functions like Beep(), conio.h)

C Compiler (GCC recommended)

MinGW-w64 or similar development environment

Installation & Compilation
Clone the repository

bash
git clone https://github.com/Elton726/Digital-Clock.git
cd Digital-Clock
Compile the source code

bash
gcc clock.c -o clock.exe
Run the application

bash
./clock.exe
🎮 Usage
Main Menu Options
text
*******DIGITAL CLOCK SYSTEM*******
___________________________________________________________________________________________

 Clock Options

 1. Reset Time
 2. Set Alarm
 3. Exit Clock
 4. About Developers
Key Functions
Reset Time - Manually set custom time values

Enter hours (0-23), minutes (0-59), seconds (0-59)

Input validation prevents invalid entries

Set Alarm - Configure alarm with sound notification

Set specific hour, minute, and second for alarm trigger

Visual and audible alert when alarm activates

Press any key to dismiss alarm

Real-time Display - Shows continuously updating time

Uses system clock for accurate timekeeping

Smooth updates without screen flicker

Automatic time progression

About Developers - Project information and credits

🛠️ Technical Details
Built With
C Programming Language

Windows API for system functions

Standard C Libraries: stdio.h, stdlib.h, time.h, windows.h, conio.h

Key Functions
display_time() - Main clock display loop

manual_update() - Manual time setting interface

alarm_setting() - Alarm configuration

display_manual_time() - Manual clock operation

Input validation with error handling

Features
Input Validation - Robust error checking for user inputs

Memory Efficient - Minimal resource usage

Cross-session - No external dependencies

Console-based - Lightweight and fast

📁 Project Structure
text
Digital-Clock/
├── clock.c          # Main source code
├── README.md        # Project documentation
├── .gitignore       # Git ignore rules
└── (optional) screenshots/
🔧 Compilation Notes
Requires Windows-compatible C compiler

Uses Windows-specific functions: Beep(), _kbhit(), _getch()

MinGW-w64 recommended for Windows development

Console application - runs in command prompt

🎯 System Requirements
OS: Windows 7 or newer

Memory: Minimal requirements

Storage: < 1MB

Dependencies: None

🤝 Contributing
Fork the project

Create your feature branch (git checkout -b feature/AmazingFeature)

Commit your changes (git commit -m 'Add some AmazingFeature')

Push to the branch (git push origin feature/AmazingFeature)

Open a Pull Request

👥 Developers
1.Elton Chirambo
2.Richard MUnthali
3.Misheck Champopa
4.Matthias Mphande
5.Praise Mwamlima
Bachelor of Science in Information and Communication Technology

📄 License
This project is open source and available under the MIT License.

🐛 Known Issues
Windows-specific code limits cross-platform compatibility

Alarm sound may vary by system

Console-based interface only

🔮 Future Enhancements
GUI version

Multiple alarm support

Stopwatch functionality

Timer features

Cross-platform compatibility

⭐ Star this repository if you find it useful!
