#include <fff.h>
DEFINE_FFF_GLOBALS;

#include <unity.h>

#include "driver.h"
#include "hardware_abstraction.h"
#include "registers.h"

FAKE_VALUE_FUNC(uint8_t, IO_MEM_RD8, uint32_t);
FAKE_VOID_FUNC(IO_MEM_WR8, uint32_t, uint8_t);

void setUp() {
  RESET_FAKE(IO_MEM_WR8);
  RESET_FAKE(IO_MEM_RD8);
  FFF_RESET_HISTORY();
}

void tearDown() {}

void test_driver_When_writing_Then_writes_data_to_DRIVER_OUTPUT_REGISTER(void) {
  driver_write(0x34);
  TEST_ASSERT_EQUAL_UINT32(1u, IO_MEM_WR8_fake.call_count);
  TEST_ASSERT_EQUAL_UINT32(0x34u, IO_MEM_WR8_fake.arg1_val);
  TEST_ASSERT_EQUAL_UINT32(DRIVER_OUTPUT_REGISTER, IO_MEM_WR8_fake.arg0_val);
}

void test_driver_When_reading_data_Then_reads_from_DRIVER_INPUT_REGISTER(void) {
  IO_MEM_RD8_fake.return_val = 0x55;
  uint8_t returnedValue = driver_read();
  TEST_ASSERT_EQUAL_UINT32(1u, IO_MEM_RD8_fake.call_count);
  TEST_ASSERT_EQUAL_UINT8(0x55u, returnedValue);
  TEST_ASSERT_EQUAL_UINT32(IO_MEM_RD8_fake.arg0_val, DRIVER_INPUT_REGISTER);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_driver_When_writing_Then_writes_data_to_DRIVER_OUTPUT_REGISTER);
  RUN_TEST(test_driver_When_reading_data_Then_reads_from_DRIVER_INPUT_REGISTER);

  return UNITY_END();
}
