#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"

// Global variables for mock control
kern_return_t mock_host_statistics_result = KERN_SUCCESS;
host_cpu_load_info_data_t next_mock_load;

// Mock implementations
host_t mach_host_self() {
  return 123;
}

kern_return_t host_statistics(host_t host, int flavor, host_info_t info, mach_msg_type_number_t* count) {
  if (mock_host_statistics_result != KERN_SUCCESS) {
    return mock_host_statistics_result;
  }

  host_cpu_load_info_data_t* load_info = (host_cpu_load_info_data_t*)info;
  memcpy(load_info->cpu_ticks, next_mock_load.cpu_ticks, sizeof(next_mock_load.cpu_ticks));
  *count = HOST_CPU_LOAD_INFO_COUNT;

  return KERN_SUCCESS;
}

void test_cpu_update_calculation() {
  printf("Running test_cpu_update_calculation...\n");
  struct cpu cpu;
  cpu_init(&cpu);

  // First update
  next_mock_load.cpu_ticks[CPU_STATE_USER] = 100;
  next_mock_load.cpu_ticks[CPU_STATE_SYSTEM] = 50;
  next_mock_load.cpu_ticks[CPU_STATE_IDLE] = 850;
  next_mock_load.cpu_ticks[CPU_STATE_NICE] = 0;

  cpu_update(&cpu);
  assert(cpu.has_prev_load == true);

  // Second update: User +100, Sys +50, Idle +350. Total delta = 500.
  // User % = 100/500 = 20%
  // Sys % = 50/500 = 10%
  // Total % = 30%
  next_mock_load.cpu_ticks[CPU_STATE_USER] = 200;
  next_mock_load.cpu_ticks[CPU_STATE_SYSTEM] = 100;
  next_mock_load.cpu_ticks[CPU_STATE_IDLE] = 1200;

  cpu_update(&cpu);

  printf("User load: %d, Sys load: %d, Total load: %d\n", cpu.user_load, cpu.sys_load, cpu.total_load);
  assert(cpu.user_load == 20);
  assert(cpu.sys_load == 10);
  assert(cpu.total_load == 30);
  printf("test_cpu_update_calculation passed!\n");
}

void test_cpu_update_error() {
  printf("Running test_cpu_update_error...\n");
  struct cpu cpu;
  cpu_init(&cpu);

  mock_host_statistics_result = KERN_FAILURE;
  cpu_update(&cpu);

  assert(cpu.has_prev_load == false);
  mock_host_statistics_result = KERN_SUCCESS; // Reset for other tests
  printf("test_cpu_update_error passed!\n");
}

int main() {
  test_cpu_update_calculation();
  test_cpu_update_error();
  printf("All tests passed!\n");
  return 0;
}
