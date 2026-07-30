# StoryForge – Phase 3

## Overview

In Phase 3, I implemented the core backend logic responsible for organizing the story and managing the pitch approval workflow. The main objective was to ensure that story paragraphs are always displayed in chronological order and that accepting a pitch automatically updates the story while rejecting competing pitches for the same position.

This phase builds on the models and database created in the previous phases and introduces a new `BookCore` module to handle the application's business logic.

---

## Features

* Implemented a chronological sorting engine using the C++ STL `sort()` function with a lambda expression.
* Created the `BookCore` service to manage the application's core workflow.
* Added an automated pitch approval pipeline.
* Automatically creates a new paragraph when a pitch is accepted.
* Automatically rejects all other pitches targeting the same order number.
* Saves all updates to the database after processing.

---

## Project Structure

```text

Phase-3
│
├── models
│   ├── Pitch.h
│   └── Pitch.cpp
│
├── services
│   ├── Database.h
│   ├── Database.cpp
│   ├── BookCore.h
│   └── BookCore.cpp
│
├── manual_test.cpp
├── story_db.json
└── README.md

```

## BookCore

`BookCore` is the main component introduced in this phase. It contains the application's core logic instead of placing it inside `main()` or the database class.

Its responsibilities include:

* Sorting paragraphs by their order number.
* Accepting a selected pitch.
* Creating a paragraph from the accepted pitch.
* Rejecting competing pitches for the same story position.
* Saving the updated data.

---

## Chronological Sorting

Story paragraphs are organized using the C++ Standard Library `sort()` function with a lambda expression.

```cpp
sort(paragraphs.begin(), paragraphs.end(),
[](Paragraph& a, Paragraph& b)
{
    return a.getOrderNum() < b.getOrderNum();
});
```

This ensures that paragraphs are always displayed in the correct sequence based on their `order_num`.

---

## Pitch Processing Workflow

When a pitch is accepted, the workflow performs the following steps:

1. Finds the selected pitch.
2. Verifies that its status is `Pending`.
3. Changes its status to `Accepted`.
4. Creates a new paragraph using the accepted pitch's information.
5. Adds the paragraph to the database.
6. Rejects all other pitches targeting the same order number.
7. Saves the updated data.

This guarantees that only one pitch can become part of the story for a particular position.

---

## Manual Testing

The manual test demonstrates:

* Paragraph sorting before and after applying the sorting algorithm.
* Successful acceptance of a selected pitch.
* Automatic rejection of competing pitches.
* Creation of a new paragraph from the accepted pitch.
* Updated data stored in the JSON database.

---

## Concepts Used

* Object-Oriented Programming (OOP)
* Classes and Objects
* STL Vector
* STL Sort
* Lambda Expressions
* File Handling
* JSON Data Storage

---

## How to Run

Compile the project:

Open a terminal in the Phase-3 folder and run:

```bash
g++ manual_test.cpp services/BookCore.cpp services/Database.cpp models/Pitch.cpp ../Phase-1/models/Paragraph.cpp ../Phase-2/models/User.cpp -o test
```

Run the program:

```bash
.\test.exe
```


## Conclusion

Phase 3 successfully implements the core workflow engine for StoryForge. The application can organize story paragraphs chronologically, process pitch approvals, automatically generate new paragraphs, reject competing proposals, and save the updated story state. This provides a structured and consistent workflow for collaborative story creation.
