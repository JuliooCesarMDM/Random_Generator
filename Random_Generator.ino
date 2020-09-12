/******************************INFO**********************************/
//AUTOR:JULIO CESAR MATIAS
//DATA:AGOSTO DE 2020
/********************************************************************/


void setup() {
  Serial.begin(115200);
}

//http://en.wikipedia.org/wiki/Random_number_generation
uint16_t RandomGenerator() {
  static uint32_t m_z = 1234;
  static uint32_t m_w = 76542;
  m_z = 36969 * (m_z & 65535) + (m_z >> 16);
  m_w = 18000 * (m_w & 65535) + (m_w >> 16);
  return ((m_z << 16) + m_w) & 0xFFFF;
}

uint32_t RandomFunction(uint32_t MinValue, uint32_t MaxValue) {
  uint32_t Difference = MaxValue - MinValue;
  return (RandomGenerator() % Difference) + MinValue;
}

void loop() {
  Serial.println(RandomFunction(1, 100));
}
