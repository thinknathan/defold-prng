#include <dmsdk/sdk.h>

// Mulberry32 PRNG implementation
static uint32_t s_seed;

static uint32_t mulberry32()
{
    uint32_t z = (s_seed += 0x6D2B79F5);
    z = (z ^ (z >> 15)) * (z | 1);
    z ^= z + (z ^ (z >> 7)) * (z | 61);
    return z ^ (z >> 14);
}

static int SetSeed(lua_State* L)
{
    s_seed = luaL_checkinteger(L, 1);
    return 0;
}

static int RandFloat(lua_State* L)
{
    float randValue = static_cast<float>(mulberry32()) / static_cast<float>(0xFFFFFFFF);
    lua_pushnumber(L, randValue);
    return 1;
}

static int RandInt(lua_State* L)
{
    int maxValue = luaL_checkinteger(L, 1);  // Get the maximum value from Lua
    int randValue = static_cast<int>(mulberry32() % (maxValue + 1));  // Generate a random value between 0 and maxValue
    lua_pushinteger(L, randValue);
    return 1;
}

static const luaL_Reg prng_functions[] =
{
    { "set_seed", SetSeed },
    { "rand_float", RandFloat },
    { "rand_int", RandInt },
    { 0, 0 }
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
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
