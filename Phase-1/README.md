# StoryForge – Phase 1

## Project Overview

StoryForge is a collaborative command-line storytelling application where users build a single story together. This phase focuses on designing the core data models and implementing serialization and deserialization for future file storage.

---

## Features Implemented

### Paragraph Model
- Stores paragraph ID
- Stores paragraph text
- Stores author name
- Stores paragraph order number
- Implements `to_dict()` for serialization
- Implements `from_dict()` for deserialization

### Pitch Model
- Stores pitch ID
- Stores target order number
- Stores pitch text
- Stores author name
- Stores pitch status (Pending, Accepted, Rejected)
- Implements `to_dict()` for serialization
- Implements `from_dict()` for deserialization

---

## Manual Testing

The `manual_test.cpp` file verifies:

- Paragraph object creation
- Paragraph serialization (`to_dict()`)
- Paragraph deserialization (`from_dict()`)
- Pitch object creation
- Pitch serialization (`to_dict()`)
- Pitch deserialization (`from_dict()`)

---

## Project Structure

```
Phase-1
│
├── models
│   ├── Paragraph.h
│   ├── Paragraph.cpp
│   ├── Pitch.h
│   └── Pitch.cpp
│
├── manual_test.cpp
├── README.md
└── output
```

---

## How to Compile

```bash
g++ manual_test.cpp models/Paragraph.cpp models/Pitch.cpp -o test
```

---

## How to Run

On Windows PowerShell:

```powershell
.\test
```

---

## Output

The `output` folder contains screenshots demonstrating successful execution of the manual tests.