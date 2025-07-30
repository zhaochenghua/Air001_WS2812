/*
  Air001 WS2812 Simple Demo
  
  此示例展示如何使用Air001_WS2812库控制开发板上的WS2812 LED
  
  接线说明:
  - 无需额外接线，板载LED已连接到PA7引脚
  
  功能:
  1. 循环显示预定义颜色
  2. 创建自定义颜色过渡效果
  3. 呼吸灯效果演示
*/

#include <Air001_WS2812.h>

void setup() {
  // 初始化LED控制器
  Air001_WS2812::begin();
}

void loop() {
  // 预定义颜色循环
  Air001_WS2812::setColor(Air001_WS2812::RED);
  delay(1000);
  
  Air001_WS2812::setColor(Air001_WS2812::GREEN);
  delay(1000);
  
  Air001_WS2812::setColor(Air001_WS2812::BLUE);
  delay(1000);
  
  Air001_WS2812::setColor(Air001_WS2812::YELLOW);
  delay(1000);
  
  Air001_WS2812::setColor(Air001_WS2812::PURPLE);
  delay(1000);
  
  Air001_WS2812::setColor(Air001_WS2812::ORANGE);
  delay(1000);
  
  Air001_WS2812::off();
  delay(1000);
  
  // 自定义颜色过渡效果
  for (int i = 0; i < 256; i++) {
    Air001_WS2812::setColor(i, 255 - i, 0); // 从绿到红
    delay(10);
  }
  
  for (int i = 0; i < 256; i++) {
    Air001_WS2812::setColor(255 - i, 0, i); // 从红到蓝
    delay(10);
  }
  
  for (int i = 0; i < 256; i++) {
    Air001_WS2812::setColor(0, i, 255 - i); // 从蓝到绿
    delay(10);
  }
  
  // 呼吸灯效果
  breatheEffect(255, 0, 0, 20); // 红色呼吸
  breatheEffect(0, 255, 0, 20); // 绿色呼吸
  breatheEffect(0, 0, 255, 20); // 蓝色呼吸
}

// 呼吸灯效果函数
void breatheEffect(uint8_t r, uint8_t g, uint8_t b, int speed) {
  // 渐亮
  for (int i = 0; i < 256; i++) {
    Air001_WS2812::setColor(
      map(i, 0, 255, 0, r),
      map(i, 0, 255, 0, g),
      map(i, 0, 255, 0, b)
    );
    delay(speed);
  }
  
  // 渐暗
  for (int i = 255; i >= 0; i--) {
    Air001_WS2812::setColor(
      map(i, 0, 255, 0, r),
      map(i, 0, 255, 0, g),
      map(i, 0, 255, 0, b)
    );
    delay(speed);
  }
}