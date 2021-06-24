#ifndef __MY_MMI_IMPL_H__
#define __MY_MMI_IMPL_H__

#include "my_mmi_mpp.h"

#define MPI_DBG_FUNCTION            (0x00000001)

#define mpi_dbg(flag, fmt, ...)     _mpp_dbg(mpi_debug, flag, fmt, ## __VA_ARGS__)
#define mpi_dbg_f(flag, fmt, ...)   _mpp_dbg_f(mpi_debug, flag, fmt, ## __VA_ARGS__)

#define mpi_dbg_func(fmt, ...)      mpi_dbg_f(MPI_DBG_FUNCTION, fmt, ## __VA_ARGS__)

typedef struct MpiImpl_t MpiImpl;

struct MpiImpl_t {
    MpiImpl         *check;
    MppCtxType      type;
    MppCodingType   coding;

    MppApi          *api;
    Mpp             *ctx;
};

extern RK_U32 mpi_debug;

#endif /*__MPI_IMPL_H__*/
