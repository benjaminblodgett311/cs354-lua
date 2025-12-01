% Lua Presentation
% [![](icons/home.png){.home-icon}](index.html){.home-link}

# Welcome

- CS 354 – Programming Languages
- Team project: Lua as an embedded language
- Goal: combine C performance with Lua expressiveness

---

# Our Problem

- Fast languages like C and C++ are powerful
- But high-level logic in C can be verbose and rigid
- We want:
    - Low-level speed
    - High-level expressiveness
    - A clean way to mix both

---

# Our Solution

- Keep C for performance-critical code
- Embed Lua as a scripting layer
- Lua handles:
    - Configuration
    - High-level logic
    - Rapid iteration
- Result: C + Lua together as one system

---

# What Is Lua?

- Lightweight, embeddable scripting language
- Designed in the early 1990s at PUC-Rio
- Small, portable implementation in C
- Used in games, tools, embedded systems, and more

---

# Why Lua?

- Simple core language, small standard library
- Easy to embed in C
- Dynamic types and flexible tables
- Fast enough for scripting and game logic
- Excellent balance of:
    - Implementation size
    - Speed
    - Expressiveness

---

# Key Features Overview

- Tables: one structure for arrays and maps
- Functions as first-class values
- Closures: functions that remember state
- Coroutines for cooperative multitasking
- Designed from the start to be embedded in C

---

# Tables

```lua
t = {}
t[1] = "hello"
t["name"] = "Ben"

print(t[1])
print(t.name)
```

- One flexible structure
- Act as arrays, maps or objects

---

# Closures

```lua
function make_counter()
    local n = 0
    return function()
        n = n + 1
        return n
    end
end

c = make_counter()
print(c())
print(c())
```

- Very compact way to express stateful objects

---

# Coroutines

```lua
co = coroutine.create(function()
    print("step 1")
    coroutine.yield()
    print("step 2")
end)

coroutine.resume(co)
coroutine.resume(co)
```

- Controlled pause and resume
- Great for scripting sequences, game events, and more

---

# C + Lua Together

- C handles:
    - Performance-critical code
    - System calls, memory, hardware
- Lua handles:
    - High-level logic
    - Config, scripting, behavior
- They communicate through the Lua C API

---

# Solution

- Create a Lua state in C
- Run Lua code from C
- Call Lua functions from C
- Expose C functions to Lua

---

# Embed Example

```c
#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static int c_add(lua_State *L) {
    double a = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;
}

int main(void) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dostring(L, "print('Hello from Lua!')");

    luaL_dostring(L,
        "function add(x, y)\n"
        "    return x + y\n"
        "end"
    );

    lua_getglobal(L, "add");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 32);
    lua_call(L, 2, 1);
    printf("Lua result: %.0f\n", lua_tonumber(L, -1));
    lua_pop(L, 1);

    lua_pushcfunction(L, c_add);
    lua_setglobal(L, "c_add");

    luaL_dostring(L,
        "print('C add result:', c_add(5, 7))"
    );

    lua_close(L);
    return 0;
}
```

---

# Compile and Run Instructions

```bash
# Install Lua and dev headers (Debian/Ubuntu):
sudo apt install lua5.4 liblua5.4-dev
# Find Lua headers:
dpkg -L liblua5.4-dev | grep lua.h
# Compile and link:
LUA_INCLUDE=/usr/include/lua5.4
gcc embed.c -I"$LUA_INCLUDE" -o embed -llua5.4 -lm -ldl
# Run:
./embed
```

---

## Our Team Program: Experience

- Learning curve:
    - Understanding the Lua C API
    - Stack-based value passing
- Wins:
    - Quick iteration by editing Lua scripts
    - C code stayed smaller and more focused
- Takeaway:
    - Embedding Lua directly addresses “fast but verbose” C

---

# Language Comparison

- C
    - Very fast, low-level, explicit memory management
    - More verbose for high-level logic
- Lua
    - Smaller, lighter, and easy to embed
    - Dynamic, concise syntax
- Python / JavaScript
    - Very expressive with large ecosystems
    - Heavier runtimes, not designed specifically for embedding

---

# Why Lua Works Here

- Designed to be a C library
- Small, predictable runtime
- C and Lua feel like one program:
    - C: “engine”
    - Lua: “scripted brain”
- Direct mapping to our project goal:
    - Keep speed
    - Reduce verbosity

---

# Installing Lua

- On Linux:
    - `sudo apt install lua5.4 liblua5.4-dev`
- On macOS:
    - `brew install lua`
- From source:
    - Download from `lua.org`
    - Build with standard tools

---

# Reveal.js Slides

- Slides written in Markdown
- Converted with Pandoc to Reveal.js
- Hosted as `slides.html` in the same directory
- Linked from the team website

---

# References

- Official Lua website  
  <https://www.lua.org/>

- Lua 5.4 Reference Manual  
  <https://www.lua.org/manual/5.4/>

- Programming in Lua (online edition)  
  <https://www.lua.org/pil/>

- About Lua (history and design)  
  <https://www.lua.org/about.html/>

---

# Questions?

[![](icons/home.png){.home-icon}](index.html){.home-link}
