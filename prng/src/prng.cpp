#include <dmsdk/sdk.h>

static uint32_t mSeed;

static uint32_t mulberry32()
{
	uint32_t z = (mSeed += 0x6D2B79F5);
	z = (z ^ (z >> 15)) * (z | 1);
	z ^= z + (z ^ (z >> 7)) * (z | 61);
	return z ^ (z >> 14);
}

static int SetSeed(lua_State* L)
{
	mSeed = luaL_checkinteger(L, 1);
	return 0;
}

static int RandFloat(lua_State* L)
{
	float randValue = static_cast<float>(mulberry32()) / 0xFFFFFFFF;
	lua_pushnumber(L, randValue);
	return 1;
}

static int RandInt(lua_State* L)
{
	int maxValue = luaL_checkinteger(L, 1);
	int randValue = mulberry32() % (maxValue + 1);
	lua_pushinteger(L, randValue);
	return 1;
}

static int Coin(lua_State* L)
{
	int result = mulberry32() % 2;
	lua_pushinteger(L, result);
	return 1;
}

static int Suit(lua_State* L)
{
	int result = mulberry32() % 4;
	lua_pushinteger(L, result);
	return 1;
}

static int Dice(lua_State* L)
{
	int numDice = luaL_checkinteger(L, 1);
	int numSides = luaL_checkinteger(L, 2);
	int modifier = 0;

	if (lua_gettop(L) >= 3) {
		modifier = luaL_checkinteger(L, 3);
	}

	int result = 0;
	for (int i = 0; i < numDice; ++i) {
		result += (mulberry32() % numSides) + 1;
	}

	result += modifier;

	lua_pushinteger(L, result);
	return 1;
}

static int Advantage(lua_State* L)
{
	int n1 = mulberry32() % 101;
	int n2 = mulberry32() % 101;
	int result = n1 > n2 ? n1 : n2;

	lua_pushinteger(L, result >= 50 ? 1 : 0);
	return 1;
}

static int Disadvantage(lua_State* L)
{
	int n1 = mulberry32() % 101;
	int n2 = mulberry32() % 101;
	int result = n1 < n2 ? n1 : n2;

	lua_pushinteger(L, result >= 50 ? 1 : 0);
	return 1;
}

static const luaL_Reg prng_functions[] =
{
	{ "set_seed", SetSeed },
	{ "rand_float", RandFloat },
	{ "rand_int", RandInt },
	{ "coin", Coin },
	{ "suit", Suit },
	{ "dice", Dice },
	{ "advantage", Advantage },
	{ "disadvantage", Disadvantage },
	{ 0, 0 }
};

static void LuaInit(lua_State* L)
{
	luaL_register(L, "prng", prng_functions);
	lua_pop(L, 1);
}

static dmExtension::Result Initialize(dmExtension::Params* params)
{
	LuaInit(params->m_L);
	dmLogInfo("Registered %s Extension\n", "prng");
	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(prng, "prng", 0, 0, Initialize, 0, 0, 0)
