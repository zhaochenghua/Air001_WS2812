#ifndef Air001_WS2812_H
#define Air001_WS2812_H

#include <Arduino.h>
#include <SPI.h>

class Air001_WS2812 {
public:
    // 初始化LED控制器
    static void begin();
    
    // 设置LED颜色 (0xRRGGBB格式)
    static void setColor(uint32_t rgb);
    
    // 设置RGB分量颜色 (0-255)
    static void setColor(uint8_t r, uint8_t g, uint8_t b);
    
    // 关闭LED
    static void off();
    
    // 预定义颜色常量
    static const uint32_t RED = 0xFF0000;
    static const uint32_t GREEN = 0x00FF00;
    static const uint32_t BLUE = 0x0000FF;
    static const uint32_t YELLOW = 0xFFFF00;
    static const uint32_t PURPLE = 0xFF00FF;
    static const uint32_t WHITE = 0xFFFFFF;
    static const uint32_t BLACK = 0x000000;
    static const uint32_t ORANGE = 0xFFA500;
    static const uint32_t CYAN = 0x00FFFF;

private:
    // 发送GRB格式数据
    static void sendGRB(uint8_t g, uint8_t r, uint8_t b);
};

#endif