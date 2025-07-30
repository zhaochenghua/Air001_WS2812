#include "Air001_WS2812.h"

void Air001_WS2812::begin() {
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE1);
    SPI.setClockDivider(SPI_CLOCK_DIV2); // 8MHz时钟
    
    // 初始化时关闭LED
    off();
}

void Air001_WS2812::setColor(uint32_t rgb) {
    // 提取RGB分量 (0xRRGGBB格式)
    uint8_t r = (rgb >> 16) & 0xFF;
    uint8_t g = (rgb >> 8) & 0xFF;
    uint8_t b = rgb & 0xFF;
    
    // 以GRB顺序发送数据
    sendGRB(g, r, b);
}

void Air001_WS2812::setColor(uint8_t r, uint8_t g, uint8_t b) {
    // 以GRB顺序发送数据
    sendGRB(g, r, b);
}

void Air001_WS2812::off() {
    sendGRB(0, 0, 0); // 发送全零关闭LED
}

void Air001_WS2812::sendGRB(uint8_t g, uint8_t r, uint8_t b) {
    // 组合GRB数据 (24位)
    uint32_t grbData = ((uint32_t)g << 16) | ((uint32_t)r << 8) | b;
    
    // 发送24位颜色数据
    noInterrupts(); // 禁用中断保证时序精确
    for (int i = 0; i < 24; i++) {
        if (grbData & 0x800000) {  // 1码
            SPI.transfer(0xF8);    // 11111000
        } else {                   // 0码
            SPI.transfer(0xC0);    // 11000000
        }
        grbData <<= 1;  // 左移处理下一位
    }
    interrupts(); // 重新启用中断
    
    // 发送复位信号 (延时替代)
    delayMicroseconds(60);
}