#include <mbed.h>

asm(".global _printf_float");
using ThisThread::sleep_for;

void print_binary(uint8_t data) {
  for (int i = 7; i >= 0; i--) {
    printf("%d", (data >> i) & 0x1);
  }
}

SPI spi(A6, A5, A4);
DigitalOut cs(D9, 1);

void spi_write(uint8_t address, uint8_t data, uint8_t& status) {
  cs = 0;
  // status = spi.write(address);
  // spi.write(data);
  uint8_t buf[2] = {address, data};
  spi.write((const char*)buf, 2, NULL, 0);
  cs = 1;
}

void spi_read(uint8_t address, uint8_t& data, uint8_t& status) {
  cs = 0;
  status = spi.write(address | (0x1 << 6));
  data = spi.write(0x00);
  cs = 1;
}

int main() {
  // put your setup code here, to run once:
  DigitalOut phase(A0);
  PwmOut enable(A1);
  AnalogIn current(A2);
  current.set_reference_voltage(3.3);
  enable.period_us(100);
  enable = 0.5;
  phase = 1;

  uint8_t status;

  spi.format(8, 1);
  spi_write(0x08, 0x80, status);  // Faultクリア
  sleep_for(10ms);
  spi_write(0x0a, 0b01111111, status);  // 安全機能ロックOFF
  sleep_for(10ms);
  spi_write(0x0b, 0b1, status);  // 電流制限ON

  while (1) {
    printf("Current: %f\n", current.read_voltage() / 750 * 4750);
    sleep_for(1);
  }
}