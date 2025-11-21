#pragma pack(push, 1)
typedef struct {
    uint16_t    packet_id;
    uint32_t    timestamp;
    float       temperature;
    float       humidity;
    uint16_t    soil_moisture;
    uint16_t    light_intensity;
    uint8_t     battery_level;
    uint16_t    crc;
} sensor_data_packet_t;
#pragma pack(pop)