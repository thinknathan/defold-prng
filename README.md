<img src="_docs/def-mulberry32-x1.png" alt="Def-Mulberry32">

# Mulberry32 PRNG for Defold

This Defold native extension implements a seeded psuedo-random number generator using the Mulberry32 method.

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

## Installation

1. Edit game.project
2. Add dependency `https://github.com/thinknathan/defold-prng/archive/main.zip` for the current version
   - Or add a specific [release](https://github.com/thinknathan/defold-prng/releases)

### TypeScript Definitions

This extension includes types for use with [TypeScript + Defold](https://ts-defold.dev/).

1. Install these types

```bash
yarn add git+https://git@github.com/thinknathan/defold-prng.git#^1.0.0 -D
# or
npm install git+https://git@github.com/thinknathan/defold-prng.git#^1.0.0 --save-dev
```

2. Add `defold-prng` to `types` in `tsconfig.json`

```diff
{
	"compilerOptions": {
		"types": [
+			"defold-prng",
		],
	}
}
```

3. Add `node_modules/@types` to `typeRoots` in `tsconfig.json` if it's not already there

```diff
{
	"compilerOptions": {
		"typeRoots": [
+			"node_modules/@types",
		],
	}
}
```

## Alternatives

See [SplitMix64](https://github.com/indiesoftby/defold-splitmix64), [PCG Random](https://github.com/selimanac/defold-random) and [rand16](https://github.com/wmc7n/rand16). Compare [PRNG implementations](https://github.com/bryc/code/blob/master/jshash/PRNGs.md).
