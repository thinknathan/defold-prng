# defold-prng
Defold psuedo-random number generator extension.

This PRNG is using Mulberry32. You may prefer [SplitMix64](https://github.com/indiesoftby/defold-splitmix64) instead. Learn more about [different PRNG implementations](https://github.com/bryc/code/blob/master/jshash/PRNGs.md).

## Installation

- Edit game.project
- Add dependency `https://github.com/thinknathan/defold-prng/archive/main.zip`

## Usage

```lua
-- Set the seed
prng.set_seed(12345)

-- Generate a random float between 0 and 1
local randomFloat = prng.rand_float()
print(randomFloat)

-- Generate a random integer between 0 and the maximum you provide
local randomInt = prng.rand_int(5)
print(randomInt)
```

## Background

This project is an experiment with generating a Defold extension using Chat-GPT. The prompt was as follows:

```
create a defold extension that exposes a module to lua, use c++ that does not use any features newer than 2009, and does not use the standard library. the name of the module is prng. it should have a function exposed to lua that generates a float using mulberry32 called rand_float. it should also have a function exposed to lua that generates an integer using mulberry32 called rand_int. it should have a function exposed to lua that allows setting the seed. optimize to avoid allocations

modify the RandInt and rand_int functions so that the function outputs an integer using mulberry32 between 0 and an integer from lua
```
