/**
 * @file    flash_blob.c
 * @brief   Flash algorithm for the kl43z
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flash_blob.h"

static const uint32_t mkl43z4_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x4937b510, 0x60082000, 0x78414836, 0x0f890649, 0xd0152902, 0x4a342100, 0x444a2900, 0xd0077011,
    0x229f7841, 0x70414011, 0x06497841, 0xd1fb0f89, 0x4448482e, 0xf85ef000, 0xd0002800, 0xbd102001,
    0xe7e82101, 0x44484828, 0x28007800, 0x4825d00a, 0x229f7841, 0x31404011, 0x78417041, 0x0f890649,
    0xd1fa2902, 0x47702000, 0xb5104820, 0x44484920, 0xf885f000, 0xd1042800, 0x2100481c, 0xf0004448,
    0xbd10f93e, 0x4c19b570, 0x444c4605, 0x4b184601, 0x68e24620, 0xf8abf000, 0xd1052800, 0x46292300,
    0x68e24620, 0xf935f000, 0xb570bd70, 0x460b460c, 0x46014606, 0xb084480d, 0x44484615, 0xf8daf000,
    0xd10a2800, 0x90029001, 0x48082101, 0x462b9100, 0x46314622, 0xf0004448, 0xb004f963, 0x0000bd70,
    0x40048100, 0x4007e000, 0x00000004, 0x00000008, 0x6b65666b, 0xd0182800, 0x68c949d7, 0x0f090109,
    0xd014290f, 0x00494ad5, 0x5a51447a, 0x22000289, 0x60416002, 0x60812102, 0x61826142, 0x62026102,
    0x62420249, 0x461060c1, 0x20044770, 0x21014770, 0xe7ec0489, 0xd0022800, 0x20006101, 0x20044770,
    0x46024770, 0x68c048c6, 0x02892101, 0x49c44308, 0x477060c8, 0x217048c3, 0x21807001, 0x78017001,
    0xd5fc0609, 0x06817800, 0x2067d501, 0x06c14770, 0x2068d501, 0x07c04770, 0x2069d0fc, 0x28004770,
    0x2004d101, 0xb5104770, 0x4ab64604, 0x605048b6, 0x428148b6, 0x206bd001, 0x2000e000, 0xd1072800,
    0xf7ff4620, 0x4603ffd7, 0xf7ff4620, 0x4618ffca, 0x2800bd10, 0x2004d101, 0xb5104770, 0x22004614,
    0x60a26062, 0x612260e2, 0x61a26162, 0x602161e2, 0x606168c1, 0x68406881, 0xf94ef000, 0x200460a0,
    0x612060e0, 0x61a06160, 0x200061e0, 0xb5ffbd10, 0x4615b089, 0x466a460c, 0xf7ff9809, 0x462affda,
    0x9b044621, 0xf0009809, 0x0007f90c, 0x9c00d130, 0x19659e01, 0x46311e6d, 0xf0004628, 0x2900f92d,
    0x1c40d002, 0x1e454370, 0xd81d42ac, 0x20090221, 0x06000a09, 0x488b1809, 0x498c6041, 0x4288980c,
    0x206bd001, 0x2000e000, 0xd1112800, 0xf7ff9809, 0x4607ff81, 0x69009809, 0xd0002800, 0x2f004780,
    0x19a4d102, 0xd9e142ac, 0xf7ff9809, 0x4638ff6a, 0xbdf0b00d, 0xd1012a00, 0x47702004, 0xb089b5ff,
    0x461e4614, 0x466a460d, 0xf7ff9809, 0x4632ff92, 0x9b034629, 0xf0009809, 0x0007f8c4, 0x9d00d12d,
    0xd0262e00, 0x486fcc02, 0x99036081, 0xd0022904, 0xd0072908, 0x022ae00e, 0x0a122103, 0x18510649,
    0xe0076041, 0x60c1cc02, 0x2107022a, 0x06090a12, 0x60411851, 0xf7ff9809, 0x4607ff3d, 0x69009809,
    0xd0002800, 0x2f004780, 0x9803d103, 0x1a361945, 0x9809d1d8, 0xff25f7ff, 0xb00d4638, 0x2800bdf0,
    0x4a5bd005, 0x18890409, 0x60514a56, 0x2004e722, 0xb5ff4770, 0x4614b08b, 0x460d461e, 0x980b466a,
    0xff47f7ff, 0x46294622, 0x980b9b05, 0xf879f000, 0xd1332800, 0x4629466a, 0xf7ff980b, 0x9d00ff3a,
    0x90089802, 0x42404269, 0x424f4001, 0xd10142af, 0x183f9808, 0xd0202c00, 0x90090230, 0x42a61b7e,
    0x4626d900, 0x99054630, 0xf886f000, 0x2101022a, 0x06090a12, 0x493b1852, 0x9a09604a, 0x43100400,
    0x608830ff, 0xf7ff980b, 0x2800fee5, 0x9808d106, 0x19ad1ba4, 0x2c00183f, 0x2000d1e0, 0xbdf0b00f,
    0xd1012b00, 0x47702004, 0xb089b5ff, 0x461d4616, 0x466a460c, 0x98099f12, 0xfefbf7ff, 0x46214632,
    0x98099b07, 0xf82df000, 0xd11d2800, 0x2e009c00, 0x4928d01a, 0x18470638, 0x20010221, 0x06400a09,
    0x48201809, 0x60876041, 0x60c16829, 0xf7ff9809, 0x2800feb1, 0x9913d00a, 0xd0002900, 0x9914600c,
    0xd0012900, 0x600a2200, 0xbdf0b00d, 0x1a769907, 0x00890889, 0x9907194d, 0x2e00190c, 0xb00dd1dc,
    0x2800bdf0, 0x2004d101, 0xb4104770, 0x42191e5b, 0x421ad101, 0xbc10d002, 0x47702065, 0x428b6803,
    0x6840d804, 0x18181889, 0xd2024288, 0x2066bc10, 0xbc104770, 0x47702000, 0x40048040, 0x000003a0,
    0xf0003000, 0x40020000, 0x44ffffff, 0x6b65666b, 0x4000ffff, 0x00ffffff, 0x460bb530, 0x20004601,
    0x24012220, 0x460de009, 0x429d40d5, 0x461dd305, 0x1b494095, 0x40954625, 0x46151940, 0x2d001e52,
    0xbd30dcf1, 0x40020004, 0x40020010, 0x00100008, 0x00200018, 0x00400030, 0x00800060, 0x010000c0,
    0x02000180, 0x04000300, 0x00000600, 0x00000000, 0x00000000,
};

static const program_target_t flash = {
    0x20000021, // Init
    0x20000065, // UnInit
    0x20000089, // EraseChip
    0x200000A5, // EraseSector
    0x200000CB, // ProgramPage

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000000 + 0x00000001,
        0x20000000 + 0x00000020 + 0x000004cc,
        0x20000800
    },

    0x20000000 + 0x00000A00,   // mem buffer location
    0x20000000,                // location to write prog_blob in target RAM
    sizeof(mkl43z4_flash_prog_blob), // prog_blob size
    mkl43z4_flash_prog_blob,         // address of prog_blob
    0x00000200                 // ram_to_flash_bytes_to_be_written
};