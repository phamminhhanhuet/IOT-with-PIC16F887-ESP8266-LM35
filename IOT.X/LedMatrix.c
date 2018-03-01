/* 
 * File:  LedMatrix.c
 * Author:  TungHT
 * Comments: 
 * Revision history: May 7, 2017, 3:58 PM
 */

#include "LedMatrix.h"

/* Hang va cot cua matrix*/
//unsigned char row[] = {1, 2, 4, 8, 16, 32, 64, 128};a LED matrix*/
//unsigned char row[] = {1, 2, 4, 8, 16, 32, 64, 128};
//int column[] = {128, 64, 32, 16, 8, 4, 2, 1};
/*bieu dien các ki tu chu va so o dang HEX*/
//unsigned int Timer0   = 65535 - 1*(1000000/(4*128));
//const unsigned char characterHEX[][8] = {
//    {0x3C, 0x66, 0x66, 0x6E, 0x76, 0x66, 0x66, 0x3C}, //0
//    {0x18, 0x38, 0x58, 0x18, 0x18, 0x18, 0x18, 0x7E}, //1
//    {0x3C, 0x66, 0x66, 0x0C, 0x18, 0x30, 0x7E, 0x7E}, //2
//    {0x7E, 0x0C, 0x18, 0x3C, 0x06, 0x06, 0x46, 0x3C}, //3
//    {0x0C, 0x18, 0x30, 0x6C, 0x6C, 0x7E, 0x0C, 0x0C}, //4
//    {0x7E, 0x60, 0x60, 0x7C, 0x06, 0x06, 0x46, 0x3C}, //5
//    {0x04, 0x08, 0x10, 0x38, 0x6C, 0x66, 0x66, 0x3C}, //6
//    {0x7E, 0x46, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18}, //7
//    {0x3C, 0x66, 0x66, 0x3C, 0x66, 0x66, 0x66, 0x3C}, //8
//    {0x3C, 0x66, 0x66, 0x36, 0x1C, 0x08, 0x10, 0x20}, //9
//    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // khoang trong
//    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18}, // dau '.'
//    {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66}, //A 
//    {0x78, 0x64, 0x68, 0x78, 0x64, 0x66, 0x66, 0x7C}, //B
//    {0x3C, 0x62, 0x60, 0x60, 0x60, 0x62, 0x62, 0x3C}, //C
//    {0x78, 0x64, 0x66, 0x66, 0x66, 0x66, 0x64, 0x78}, //D
//    {0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x60, 0x7E}, //E
//    {0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x60, 0x60}, //F
//    {0x3C, 0x62, 0x60, 0x60, 0x66, 0x62, 0x62, 0x3C}, //G
//    {0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x66}, //H
//    {0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E}, //I
//    {0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1A, 0x0C}, //J
//    {0x62, 0x64, 0x68, 0x70, 0x70, 0x68, 0x64, 0x62}, //K
//    {0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E}, //L
//    {0xC3, 0xE7, 0xDB, 0xDB, 0xC3, 0xC3, 0xC3, 0xC3}, //M
//    {0x62, 0x62, 0x52, 0x52, 0x4A, 0x4A, 0x46, 0x46}, //N
//    {0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C}, //O
//    {0x7C, 0x62, 0x62, 0x7C, 0x60, 0x60, 0x60, 0x60}, //P
//    {0x38, 0x64, 0x64, 0x64, 0x64, 0x6C, 0x64, 0x3A}, //Q
//    {0x7C, 0x62, 0x62, 0x7C, 0x70, 0x68, 0x64, 0x62}, //R
//    {0x1C, 0x22, 0x30, 0x18, 0x0C, 0x46, 0x46, 0x3C}, //S
//    {0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18}, //T
//    {0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C}, //U
//    {0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18}, //V
//    {0x81, 0x81, 0x81, 0x81, 0x81, 0x99, 0x99, 0x66}, //W
//    {0x42, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x42}, //X
//    {0xC3, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18}, //Y
//    {0x7E, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x7E}, //Z
//    {0x00, 0x66, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00}// hinh trai tim, ki hieu la '&'
//    };
///* ki tu dai dien de bieu dien chu va so tren led ma tran */
//const unsigned char character[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '.', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '&'};

//******************BANG MA ASCII on LED matrix font 5x7 designer QH use RTB****************

//const char font[97][6] = {
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //SPACE0 
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //!    1     
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //'    2
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //#    3
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //$    4
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //%    5
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //&    6
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //'    7
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //(    8
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //)    9
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //*    10
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //+    11
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //,    12
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //-    13
//                          0xFF, 0x9F, 0x9F, 0xFF, 0xFF, 0xFF, //x    14
//                          0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, // /   15
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //0    16      
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //1    17
//                          0x8D, 0xB6, 0xB6, 0xB6, 0xB9, 0xFF, //2    18
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //3    19
//                          0xE7, 0xEB, 0xED, 0x80, 0xEF, 0xFF, //4    20
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //5    21
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //6    22
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //7    23
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //8    24
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //9    25
//                          0xFF, 0xC9, 0xC9, 0xFF, 0xFF, 0xFF, //:    26
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, ////   27
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //<    28
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //=    29
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //>    30
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //?    31
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //@    32
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //A    33
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //B    34
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //C    35
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //D    36
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //E    37
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //F    38
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //G    39
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //H    40
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //I    41
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //J    42
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //K    43
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //L    44
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //M    45
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //N    46
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //O    47
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //P    48
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //Q    49
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //R    50
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //S    51 
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //T    52
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //U    53
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //V    54
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //W    55
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //X    56
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //Y    57
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //Z    58
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //[    59
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //\    60
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //]    61
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //^    92
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //_    63
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //'    64
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //a    65
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //b    66
//                          0xFF, 0xC7, 0xBB, 0xBB, 0xBB, 0xFF, //c    67
//                          0xC7, 0xBB, 0xBB, 0xC7, 0x80, 0xFF, //d    68
//                          0xC7, 0xAB, 0xAB, 0xAB, 0xF7, 0xFF, //e    69
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //f    70
//                          0xF7, 0xAB, 0xAB, 0xAB, 0xC3, 0xFF, //g    71
//                          0x80, 0xF7, 0xFB, 0xFB, 0x87, 0xFF, //h    72
//                          0xFF, 0xBB, 0x82, 0xBF, 0xFF, 0xFF, //i    73
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //j    74
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //k    75
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //l    76
//                          0x83, 0xFB, 0x87, 0xFB, 0x87, 0xFF, //m    77
//                          0x83, 0xF7, 0xFB, 0xFB, 0x87, 0xFF, //n    78
//                          0xC7, 0xBB, 0xBB, 0xBB, 0xC7, 0xFF, //o    79
//                          0x83, 0xEB, 0xEB, 0xEB, 0xF7, 0xFF, //p    80
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //q    81
//                          0x83, 0xF7, 0xFB, 0xFB, 0xF7, 0xFF, //r    82
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //s    83
//                          0xFF, 0xFB, 0xC0, 0xBB, 0xBB, 0xFF, //t    84
//                          0xC3, 0xBF, 0xBF, 0xDF, 0x83, 0xFF, //u    85
//                          0xE3, 0xDF, 0xBF, 0xDF, 0xE3, 0xFF, //v    86
//                          0xC3, 0xBF, 0xCF, 0xBF, 0xC3, 0xFF, //w    87
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //x    88
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //y    89
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //z    90
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //^    62
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //->   93
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //<-   94
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //     95
//                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //BLANK CHAR 96
//    };

//=====End Table font=========================
#define   With_of_font   6  
const unsigned char font[97][6] = {
                                   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //  SPACE 0
                                   0xFF, 0xFF, 0xA0, 0xFF, 0xFF, 0xFF, //  ! 1
                                   0xFF, 0xFF, 0xF8, 0xF4, 0xFF, 0xFF, //  ' 2
                                   0xEB, 0x80, 0xEB, 0x80, 0xEB, 0xFF, //  # 3
                                   0xDB, 0xD5, 0x80, 0xD5, 0xED, 0xFF, //  $ 4
                                   0xD8, 0xEA, 0x94, 0xAB, 0x8D, 0xFF, //  % 5
                                   0xC9, 0xB6, 0xA9, 0xDF, 0xAF, 0xFF, //  & 6
                                   0xFF, 0xFF, 0xF8, 0xF4, 0xFF, 0xFF, //  ' 7
                                   0xFF, 0xE3, 0xDD, 0xBE, 0xFF, 0xFF, //  ( 8
                                   0xFF, 0xBE, 0xDD, 0xE3, 0xFF, 0xFF, //  ) 9
                                   0xD5, 0xE3, 0x80, 0xE3, 0xD5, 0xFF, //  * 10
                                   0xF7, 0xF7, 0xC1, 0xF7, 0xF7, 0xFF, //  + 11
                                   0xFF, 0xA7, 0xC7, 0xFF, 0xFF, 0xFF, //  , 12
                                   0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xFF, //  - 13
                                   0xFF, 0x9F, 0x9F, 0xFF, 0xFF, 0xFF, //  x 14
                                   0xFF, 0xC9, 0xC9, 0xFF, 0xFF, 0xFF, //  / 15
                                   0xC1, 0xAE, 0xB6, 0xBA, 0xC1, 0xFF, //  0 16
                                   0xFF, 0xBD, 0x80, 0xBF, 0xFF, 0xFF, //  1 17
                                   0x8D, 0xB6, 0xB6, 0xB6, 0xB9, 0xFF, //  2 18
                                   0xDD, 0xBE, 0xB6, 0xB6, 0xC9, 0xFF, //  3 19
                                   0xE7, 0xEB, 0xED, 0x80, 0xEF, 0xFF, //  4 20
                                   0xD8, 0xBA, 0xBA, 0xBA, 0xC6, 0xFF, //  5 21
                                   0xC3, 0xB5, 0xB6, 0xB6, 0xCF, 0xFF, //  6 22
                                   0xFE, 0x8E, 0xF6, 0xFA, 0xFC, 0xFF, //  7 23
                                   0xC9, 0xB6, 0xB6, 0xB6, 0xC9, 0xFF, //  8 24
                                   0xF9, 0xB6, 0xB6, 0xD6, 0xE1, 0xFF, //  9 25
                                   0xFF, 0xC9, 0xC9, 0xFF, 0xFF, 0xFF, //  : 26
                                   0xFF, 0xA4, 0xC4, 0xFF, 0xFF, 0xFF, //  // 27
                                   0xF7, 0xEB, 0xDD, 0xBE, 0xFF, 0xFF, //  < 28
                                   0xEB, 0xEB, 0xEB, 0xEB, 0xEB, 0xFF, //  = 29
                                   0xFF, 0xBE, 0xDD, 0xEB, 0xF7, 0xFF, //  > 30
                                   0xFD, 0xFE, 0xAE, 0xF6, 0xF9, 0xFF, //  ? 31
                                   0xCD, 0xB6, 0x8E, 0xBE, 0xC1, 0xFF, //  @ 32
                                   0x83, 0xF5, 0xF6, 0xF5, 0x83, 0xFF, //  A 33
                                   0xBE, 0x80, 0xB6, 0xB6, 0xC9, 0xFF, //  B 34
                                   0xC1, 0xBE, 0xBE, 0xBE, 0xDD, 0xFF, //  C 35
                                   0xBE, 0x80, 0xBE, 0xBE, 0xC1, 0xFF, //  D 36
                                   0x80, 0xB6, 0xB6, 0xB6, 0xBE, 0xFF, //  E 37
                                   0x80, 0xF6, 0xF6, 0xFE, 0xFE, 0xFF, //  F 38
                                   0xC1, 0xBE, 0xB6, 0xB6, 0xC5, 0xFF, //  G 39
                                   0x80, 0xF7, 0xF7, 0xF7, 0x80, 0xFF, //  H 40
                                   0xFF, 0xBE, 0x80, 0xBE, 0xFF, 0xFF, //  I 41
                                   0xDF, 0xBF, 0xBE, 0xC0, 0xFE, 0xFF, //  J 42
                                   0x80, 0xF7, 0xEB, 0xDD, 0xBE, 0xFF, //  K 43
                                   0x80, 0xBF, 0xBF, 0xBF, 0xFF, 0xFF, //  L 44
                                   0x80, 0xFD, 0xF3, 0xFD, 0x80, 0xFF, //  M 45
                                   0x80, 0xFD, 0xFB, 0xF7, 0x80, 0xFF, //  N 46
                                   0xC1, 0xBE, 0xBE, 0xBE, 0xC1, 0xFF, //  O 47
                                   0x80, 0xF6, 0xF6, 0xF6, 0xF9, 0xFF, //  P 48
                                   0xC1, 0xBE, 0xAE, 0xDE, 0xA1, 0xFF, //  Q 49
                                   0x80, 0xF6, 0xE6, 0xD6, 0xB9, 0xFF, //  R 50
                                   0xD9, 0xB6, 0xB6, 0xB6, 0xCD, 0xFF, //  S 51
                                   0xFE, 0xFE, 0x80, 0xFE, 0xFE, 0xFF, //  T 52
                                   0xC0, 0xBF, 0xBF, 0xBF, 0xC0, 0xFF, //  U 53
                                   0xE0, 0xDF, 0xBF, 0xDF, 0xE0, 0xFF, //  V 54
                                   0xC0, 0xBF, 0xCF, 0xBF, 0xC0, 0xFF, //  W 55
                                   0x9C, 0xEB, 0xF7, 0xEB, 0x9C, 0xFF, //  X 56
                                   0xFC, 0xFB, 0x87, 0xFB, 0xFC, 0xFF, //  Y 57
                                   0x9E, 0xAE, 0xB6, 0xBA, 0xBC, 0xFF, //  Z 58
                                   0xFF, 0x80, 0xBE, 0xBE, 0xFF, 0xFF, //  [ 59
                                   0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xFF, //  \ 60
                                   0xFF, 0xBE, 0xBE, 0x80, 0xFF, 0xFF, //  ] 61
                                   0xFB, 0xFD, 0xFE, 0xFD, 0xFB, 0xFF, //  ^ 92
                                   0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, //  _ 63
                                   0xFF, 0xFF, 0xF8, 0xF4, 0xFF, 0xFF, //  ' 64
                                   0xDF, 0xAB, 0xAB, 0xAB, 0xC7, 0xFF, //  a 65
                                   0x80, 0xC7, 0xBB, 0xBB, 0xC7, 0xFF, //  b 66
                                   0xFF, 0xC7, 0xBB, 0xBB, 0xBB, 0xFF, //  c 67
                                   0xC7, 0xBB, 0xBB, 0xC7, 0x80, 0xFF, //  d 68
                                   0xC7, 0xAB, 0xAB, 0xAB, 0xF7, 0xFF, //  e 69
                                   0xF7, 0x81, 0xF6, 0xF6, 0xFD, 0xFF, //  f 70
                                   0xF7, 0xAB, 0xAB, 0xAB, 0xC3, 0xFF, //  g 71
                                   0x80, 0xF7, 0xFB, 0xFB, 0x87, 0xFF, //  h 72
                                   0xFF, 0xBB, 0x82, 0xBF, 0xFF, 0xFF, //  i 73
                                   0xDF, 0xBF, 0xBB, 0xC2, 0xFF, 0xFF, //  j 74
                                   0xFF, 0x80, 0xEF, 0xD7, 0xBB, 0xFF, //  k 75
                                   0xFF, 0xBE, 0x80, 0xBF, 0xFF, 0xFF, //  l 76
                                   0x83, 0xFB, 0x87, 0xFB, 0x87, 0xFF, //  m 77
                                   0x83, 0xF7, 0xFB, 0xFB, 0x87, 0xFF, //  n 78
                                   0xC7, 0xBB, 0xBB, 0xBB, 0xC7, 0xFF, //  o 79
                                   0x83, 0xEB, 0xEB, 0xEB, 0xF7, 0xFF, //  p 80
                                   0xF7, 0xEB, 0xEB, 0xEB, 0x83, 0xFF, //  q 81
                                   0x83, 0xF7, 0xFB, 0xFB, 0xF7, 0xFF, //  r 82
                                   0xB7, 0xAB, 0xAB, 0xAB, 0xDB, 0xFF, //  s 83
                                   0xFF, 0xFB, 0xC0, 0xBB, 0xBB, 0xFF, //  t 84
                                   0xC3, 0xBF, 0xBF, 0xDF, 0x83, 0xFF, //  u 85
                                   0xE3, 0xDF, 0xBF, 0xDF, 0xE3, 0xFF, //  v 86
                                   0xC3, 0xBF, 0xCF, 0xBF, 0xC3, 0xFF, //  w 87
                                   0xBB, 0xD7, 0xEF, 0xD7, 0xBB, 0xFF, //  x 88
                                   0xF3, 0xAF, 0xAF, 0xAF, 0xC3, 0xFF, //  y 89
                                   0xBB, 0x9B, 0xAB, 0xB3, 0xBB, 0xFF, //  z 90
                                   0xFB, 0xE1, 0xE0, 0xE1, 0xFB, 0xFF, //  ^ 62
                                   0xE3, 0xE3, 0xC1, 0xE3, 0xF7, 0xFF, //  -> 93
                                   0xF7, 0xE3, 0xC1, 0xE3, 0xE3, 0xFF, //  <- 94
                                   0xEF, 0xC3, 0x83, 0xC3, 0xEF, 0xFF, //         95
                                   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //  BLANK CHAR 96
    };

void InitLedMatrix(void)
    {
    IC74HC595_TRIS(0);
    }

//void display(unsigned char *StringDisplay)
//    {
//    unsigned int PosInCharacterHEX[LED_MARIX_AMOUNT]; // Mang chua tung vi tri  cua ki tu cua hien thi trong mang characterHEX
//
//    /* Lay vi tri ki tu can hien thi trong characterHEX[] */
//    for (int i = 0; i < LED_MARIX_AMOUNT; i++)
//        for (int j = 0; j<sizeof (character); j++)
//            {
//            if (StringDisplay[i] == character[j]) //tim so thu tu cua ki tu trong mang character
//                {
//                PosInCharacterHEX[i] = j;
//                break;
//                }
//            }
//
//    /*quet LED ma tran theo hang dung IC dich*/
//    for (int row = 0; row < 8; row++)//quet hang 
//        {
//        int rowID = (1 << row);
//        /*Cho tung bit chon hang vao IC dich hang*/
//        for (int r = 0; r < 8; r++)
//            {
//            SH_ROW = 0;
//            DS_ROW = ((0x80 >> r) == rowID) ? 1 : 0; //Dua lan luot tu bit 7 den bit 0 vao IC, hang la Katot
//            SH_ROW = 1; //thuc hien dua vao
//            }
//
//        /*Dich du lieu vao cot, ki tu sau dua vao truoc*/
//        for (signed int i = (LED_MARIX_AMOUNT - 1); i >= 0; i--)
//            {
//            for (int col = 0; col < 8; col++)
//                {
//                SH = 0;
//                DS = ((characterHEX[PosInCharacterHEX[i]][row] & (1 << col)) == 0); //Cot cua LED ma tran la Anot: bit 0 thi den sang, bit 1 den tat
//                SH = 1; //
//                }
//            }
//        /* Truyen du lieu tu IC7HC595 sang LED ma tran */
//        ST = 0;
//        //__delay_us(10);
//        ST = 1; // IC dich truyen song song tin hieu cho led ma tran
//        }
//    }

//        /*Cho tung bit cot cua LED ma tran hien thi don vi vao IC dich cot hang don vi*/
//        for (col = 0; col < 8; col++)
//            {
//            SH = 0;
//            DS = ((characterHEX[ones][row] & (1 << col)) == 0); //Cot cua LED ma tran la Anot: bit 0 thi den sang, bit 1 den tat
//            SH = 1;
//            }
//
//        /*Cho tung bit cot cua LED ma tran hien thi hang chuc vao IC dich cot hang chuc*/
//        for (col = 0; col < 8; col++)
//            {
//            SH = 0;
//            DS = ((characterHEX[tens][row] & (1 << col)) == 0);
//            SH = 1;
//            }


//void display(char key)
//    {
//    char i, r, a, b;
//    for (i = 0; i<sizeof (character); i++)
//        {
//        if (key == character[i])//tim so thu tu cua ki tu trong mang character
//            break;
//        }
//    for (r = 0; r < 8; r++)//quet cot
//        {
//        for (a = 0; a < 8; a++)
//            {
//            SH_ROW = 0;
//            DS_ROW = !(((1 << r)& (0x80 >> a)) == 0);
//            SH_ROW = 1;
//            }
//        for (b = 0; b < 8; b++)
//            {
//            SH = 0;
//            DS = ((characterHEX[i][r] & (0x01 << b)) == 0);
//            SH = 1;
//            }
//        ST = 0;
//        ST = 1;
//        }
//    }

void Ic74595_Write(char data, char ic, char bits) // Ham dua du lieu vao IC 74HC595
    {
    //signed char count;
    if (ic == 1) //Dua du lieu vao IC cot
        {
        for (count = bits - 1; count >= 0; count--)
            {
            if (((data >> count) & 0x01) == 0)
                DS = 1;
            else
                DS = 0;
            SH = 0;
            SH = 1;
            }
        }
    if (ic == 2) //Dua du lieu vao IC hang
        {
        for (count = 0; count != bits; count++)
            {
            if (((data >> count) & 0x01) == 0)
                DS_ROW = 1;
            else
                DS_ROW = 0;
            SH_ROW = 0;
            SH_ROW = 1;
            }
        ST = 0;
        ST = 1;
        }
    }

void display(char* StringDisplay)
    {
    if (strcmp(OldString, StringDisplay))
        {
        next = 0; //Neu xau moi duoc hien thi thi vi tri tro ve 0
        }
    OldString = StringDisplay;
    LenghString = strlen(StringDisplay)*6; //1 font ki tu gom 6 cot tuong ung voi 6 byte
    //    unsigned char i, TempFont, mode = 1;
    //    unsigned char SelFont; //biến dùng để chọn font chữ
    //    unsigned char ColFont; //biến dùng để chọn cột của font chữ
    if (LenghString < 36)
        {
        next = 0;
        mode = 0;
        }
    Ic74595_Write(1, 1, 1);
    if (mode == 0) //Che do khong chay khi StringDisplay co it hon 6 ki tu
        {
        for (i = next; i < 32 + next; i++)
            {
            if (i < LenghString)
                {
                SelFont = StringDisplay[(i % LenghString) / With_of_font] - 32; //Đoạn code này có tác dụng trả về mã ascii tương ứng  của ký tự tương ứng trong chuỗi hiển thị,
                // trừ đi 32 tương ứng kí tự trong bảng font.
                ColFont = i % With_of_font; //Đoạn code này có tác dụng chọn cột của font
                TempFont = font[SelFont][ColFont];
                }
            else
                TempFont = 0xFF;

            Ic74595_Write(TempFont, 2, 8);
            __delay_us(500);
            Ic74595_Write(0, 1, 1);
            }
        }
    else //Che do  chay chu khi StringDisplay co nhieu hon 5 ki tu
        {
        for ( i = next; i < 32 + next; i++)
            {
            SelFont = StringDisplay[(i % LenghString) / With_of_font] - 32;
            ColFont = i % With_of_font;
            TempFont = font[SelFont][ColFont];
            //TempFont = font[StringDisplay[(i % LenghString) / With_of_font] - 32][i % With_of_font];
            Ic74595_Write(TempFont, 2, 8);
            __delay_us(500);
            Ic74595_Write(0, 1, 1);
            }
        }
    //    next++;
    //    if (next == LenghString)
    //        next = 0;
    }