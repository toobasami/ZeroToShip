# StoryForge - Phase 2

## Overview

Phase 2 focuses on building the backend system of StoryForge. This phase implements user authentication, session management, local file storage, and editor authorization without a terminal interface.

---

## Features Implemented

### User Authentication

Created a User model that stores:

- User ID
- Username
- Email
- Password

The User class supports object creation, displaying user data, and serialization/deserialization using `to_dict()` and `from_dict()`.

---

### Identity Session Manager

The Auth service manages the active user session.

Implemented features:

- Login
- Logout
- Check login status
- Get current user
- Verify editor permissions

---

### Database Persistence

Implemented a Database service for storing application data in:
story_db.json

The database stores:

- Users
- Paragraphs
- Pitches

Objects are converted into serialized data before saving and restored when loading.

---

### Editor Authorization

The system checks whether the logged-in user is the author of the latest paragraph before allowing moderation access.

Example:
Logged-in User == Latest Paragraph Author

If the condition is true, editor access is granted.

---

## Project Structure

Phase-2
│
├── models
│ └── User.h
│ └── User.cpp
│
├── services
│ ├── Auth.h
│ ├── Auth.cpp
│ ├── Database.h
│ └── Database.cpp
│
├── story_db.json
├── manual_test.cpp
└── README.md

---

## Compilation

Run inside the Phase-2 folder:

```bash
g++ -std=c++17 models/User.cpp ../Phase-1/models/Paragraph.cpp ../Phase-1/models/Pitch.cpp services/Auth.cpp services/Database.cpp manual_test.cpp -o test.exe
```

---

## Running the Program

Run:

```powershell
.\test.exe
```