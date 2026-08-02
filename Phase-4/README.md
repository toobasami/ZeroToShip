# StoryForge – Phase 4: Presentation Layer

## Overview

Phase 4 focuses on building the presentation layer for the StoryForge CLI application. The objective is to display story content and candidate pitches in a clean, organized terminal interface using mock data. No database or live data is used in this phase.

## Features

* Terminal screen clearing before displaying content.
* Story Canvas that prints all story paragraphs as one continuous story.
* Pitch Registry that displays candidate pitches inside an ASCII table.
* Uses hardcoded mock data for testing.
* Separate presentation module for terminal rendering.

## Files

* `services/Presentation.h` – Declaration of the Presentation class.
* `services/Presentation.cpp` – Implementation of terminal rendering functions.
* `manual_test.cpp` – Creates mock Paragraph and Pitch objects and tests the presentation layer.

## Functions

### `clearScreen()`

Clears the terminal screen before displaying the interface.

### `displayStory()`

Displays all story paragraphs in order with the paragraph number and author.

### `displayPitchRegistry()`

Displays all candidate pitches in a formatted ASCII table containing:

* Pitch ID
* Target Order Number
* Status
* Pitch Text

## Mock Data

The application uses hardcoded `Paragraph` and `Pitch` objects to simulate story data. This allows the presentation layer to be tested independently before integrating the database in later phases.

## How to Compile

```bash
g++ manual_test.cpp services/Presentation.cpp ../Phase-1/models/Paragraph.cpp ../Phase-3/models/Pitch.cpp -o phase4.exe
```

## How to Run

```bash
.\phase4.exe
```
