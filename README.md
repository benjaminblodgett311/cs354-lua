# Programming Languages Lua Website Assignment

## Problem
### (we need verbose languages for performance)

We want to use Lua in our C/C++ programs because it provides higher level abstractions.

### Examples of where Lua shines

1. Dynamic Tables (Arrays + Maps in one)

```lua
t = {}
t[1] = "hello"      -- array-style
t["name"] = "Ben"   -- map-style

print(t[1])
print(t.name)
```

2. Closures (Functions remembering variables)

```lua
function make_counter()
    local n = 0
    return function()
        n = n + 1
        return n
    end
end

c = make_counter()
print(c())  -- 1
print(c())  -- 2
```

3. Coroutines (Pause and resume code)

```lua
co = coroutine.create(function()
    print("step 1")
    coroutine.yield()
    print("step 2")
end)

coroutine.resume(co)
coroutine.resume(co)
```

## Solution
### (embed Lua inside of verbose languages)

1. Install dependencies

```bash
sudo apt install lua5.4 liblua5.4-dev
```

2. Locate ``lua.h`` include for C

```bash
dpkg -L liblua5.4-dev | grep lua.h
```

3. Compile with Lua library file from step 2

```bash
$LUA_INCLUDE=/usr/include/lua5.4
gcc embed.c -I$LUA_INCLUDE -o embed -llua5.4 -lm -ldl
```

## Reveal.js Slides

Reveal resources taken from [https://github.com/hakimel/reveal.js/releases/tag/5.2.1](this Reveal.js release)

Get local Reveal.js for generating slides:

```bash
curl -L https://github.com/hakimel/reveal.js/archive/refs/heads/master.zip -o reveal.zip
unzip reveal.zip
mv reveal.js-master reveal-local
rm reveal.zip
```

Generate slides.html with pandoc:

```bash
pandoc slides.md \
    -t revealjs \
    -s \
    -o slides.html \
    --template=reveal-template.html \
    -V revealjs-url=./reveal-local
```

## Animate.css Animations

The project uses [Animate.css](https://animate.style/) to draw attention to our slides presentation button:

```bash
curl -o animatecss/animate.min.css \
    https://cdnjs.cloudflare.com/ajax/libs/animate.css/4.1.1/animate.min.css
```
