#ifndef __MY_MMI_MPP_MEM_H__
#define __MY_MMI_MPP_MEM_H__

#include <stdlib.h>

#include "my_mmi_type.h"
#include "my_mmi_err.h"

#define mpp_malloc_with_caller(type, count, caller)  \
    (type*)mpp_osal_malloc(caller, sizeof(type) * (count))

#define mpp_malloc(type, count)  \
    (type*)mpp_osal_malloc(__FUNCTION__, sizeof(type) * (count))

#define mpp_malloc_size(type, size)  \
    (type*)mpp_osal_malloc(__FUNCTION__, size)

#define mpp_calloc_size(type, size)  \
    (type*)mpp_osal_calloc(__FUNCTION__, size)

#define mpp_calloc(type, count)  \
    (type*)mpp_osal_calloc(__FUNCTION__, sizeof(type) * (count))

#define mpp_realloc(ptr, type, count) \
    (type*)mpp_osal_realloc(__FUNCTION__, ptr, sizeof(type) * (count))

#define mpp_free(ptr) \
    mpp_osal_free(__FUNCTION__, ptr)

#define MPP_FREE(ptr)   do { if(ptr) mpp_free(ptr); ptr = NULL; } while (0)
#define MPP_FCLOSE(fp)  do { if(fp)  fclose(fp);     fp = NULL; } while (0)

#ifdef __cplusplus
extern "C" {
#endif

void *mpp_osal_malloc(const char *caller, size_t size);
void *mpp_osal_calloc(const char *caller, size_t size);
void *mpp_osal_realloc(const char *caller, void *ptr, size_t size);
void mpp_osal_free(const char *caller, void *ptr);

void mpp_show_mem_status();
RK_U32 mpp_mem_total_now();
RK_U32 mpp_mem_total_max();

/*
 * mpp memory usage snapshot tool
 *
 * usage:
 * call mpp_mem_get_snapshot on context init get one snapshot
 * call mpp_mem_get_snapshot on context deinit get another snapshot
 * call mpp_mem_diff_snapshot to show the difference between these two snapshot
 * call mpp_mem_put_snapshot twice to release these two snapshot
 */
typedef void* MppMemSnapshot;

MPP_RET mpp_mem_get_snapshot(MppMemSnapshot *hnd);
MPP_RET mpp_mem_put_snapshot(MppMemSnapshot *hnd);
MPP_RET mpp_mem_squash_snapshot(MppMemSnapshot hnd0, MppMemSnapshot hnd1);

int os_malloc(void **memptr, size_t alignment, size_t size);
int os_realloc(void *src, void **dst, size_t alignment, size_t size);
void os_free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif /*__MY_MMI_MPP_MEM_H__*/
