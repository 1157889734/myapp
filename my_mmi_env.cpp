#if defined(_WIN32)
#include <stdio.h>
#include <stdlib.h>
#include "my_mmi_env.h"

#define ENV_BUF_SIZE_WIN    1024

RK_S32 os_get_env_u32(const char *name, RK_U32 *value, RK_U32 default_value)
{
    char *ptr = getenv(name);
    if (NULL == ptr) {
        *value = default_value;
    } else {
        char *endptr;
        int base = (ptr[0] == '0' && ptr[1] == 'x') ? (16) : (10);
        errno = 0;
        *value = strtoul(ptr, &endptr, base);
        if (errno || (ptr == endptr)) {
            errno = 0;
            *value = default_value;
        }
    }
    return 0;
}

RK_S32 os_get_env_str(const char *name, const char **value, const char *default_value)
{
    *value = getenv(name);
    if (NULL == *value) {
        *value = default_value;
    }
    return 0;
}

RK_S32 os_set_env_u32(const char *name, RK_U32 value)
{
    char buf[ENV_BUF_SIZE_WIN];
    _snprintf(buf, sizeof(buf), "%s=%lu", name, value);
    return _putenv(buf);
}

RK_S32 os_set_env_str(const char *name, char *value)
{
    char buf[ENV_BUF_SIZE_WIN];
    _snprintf(buf, sizeof(buf), "%s=%s", name, value);
    return _putenv(buf);
}

// TODO: add previous value compare to save call times

RK_S32 mpp_env_get_u32(const char *name, RK_U32 *value, RK_U32 default_value)
{
    return os_get_env_u32(name, value, default_value);
}

RK_S32 mpp_env_get_str(const char *name, const char **value, const char *default_value)
{
    return os_get_env_str(name, value, default_value);
}

RK_S32 mpp_env_set_u32(const char *name, RK_U32 value)
{
    return os_set_env_u32(name, value);
}

RK_S32 mpp_env_set_str(const char *name, char *value)
{
    return os_set_env_str(name, value);
}
