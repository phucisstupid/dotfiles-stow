#ifndef MOCK_MACH_H
#define MOCK_MACH_H

#include <stdint.h>

typedef int kern_return_t;
#define KERN_SUCCESS 0
#define KERN_FAILURE 1

typedef int host_t;
typedef uint32_t mach_msg_type_number_t;
typedef int* host_info_t;

#define HOST_CPU_LOAD_INFO 3
#define HOST_CPU_LOAD_INFO_COUNT 4

#define CPU_STATE_USER 0
#define CPU_STATE_SYSTEM 1
#define CPU_STATE_IDLE 2
#define CPU_STATE_NICE 3
#define CPU_STATE_MAX 4

typedef struct host_cpu_load_info {
  uint32_t cpu_ticks[CPU_STATE_MAX];
} host_cpu_load_info_data_t;

host_t mach_host_self();
kern_return_t host_statistics(host_t host, int flavor, host_info_t info, mach_msg_type_number_t* count);

#endif
