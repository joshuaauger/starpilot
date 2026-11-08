#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6057666269876821352) {
   out_6057666269876821352[0] = delta_x[0] + nom_x[0];
   out_6057666269876821352[1] = delta_x[1] + nom_x[1];
   out_6057666269876821352[2] = delta_x[2] + nom_x[2];
   out_6057666269876821352[3] = delta_x[3] + nom_x[3];
   out_6057666269876821352[4] = delta_x[4] + nom_x[4];
   out_6057666269876821352[5] = delta_x[5] + nom_x[5];
   out_6057666269876821352[6] = delta_x[6] + nom_x[6];
   out_6057666269876821352[7] = delta_x[7] + nom_x[7];
   out_6057666269876821352[8] = delta_x[8] + nom_x[8];
   out_6057666269876821352[9] = delta_x[9] + nom_x[9];
   out_6057666269876821352[10] = delta_x[10] + nom_x[10];
   out_6057666269876821352[11] = delta_x[11] + nom_x[11];
   out_6057666269876821352[12] = delta_x[12] + nom_x[12];
   out_6057666269876821352[13] = delta_x[13] + nom_x[13];
   out_6057666269876821352[14] = delta_x[14] + nom_x[14];
   out_6057666269876821352[15] = delta_x[15] + nom_x[15];
   out_6057666269876821352[16] = delta_x[16] + nom_x[16];
   out_6057666269876821352[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5874123099794783116) {
   out_5874123099794783116[0] = -nom_x[0] + true_x[0];
   out_5874123099794783116[1] = -nom_x[1] + true_x[1];
   out_5874123099794783116[2] = -nom_x[2] + true_x[2];
   out_5874123099794783116[3] = -nom_x[3] + true_x[3];
   out_5874123099794783116[4] = -nom_x[4] + true_x[4];
   out_5874123099794783116[5] = -nom_x[5] + true_x[5];
   out_5874123099794783116[6] = -nom_x[6] + true_x[6];
   out_5874123099794783116[7] = -nom_x[7] + true_x[7];
   out_5874123099794783116[8] = -nom_x[8] + true_x[8];
   out_5874123099794783116[9] = -nom_x[9] + true_x[9];
   out_5874123099794783116[10] = -nom_x[10] + true_x[10];
   out_5874123099794783116[11] = -nom_x[11] + true_x[11];
   out_5874123099794783116[12] = -nom_x[12] + true_x[12];
   out_5874123099794783116[13] = -nom_x[13] + true_x[13];
   out_5874123099794783116[14] = -nom_x[14] + true_x[14];
   out_5874123099794783116[15] = -nom_x[15] + true_x[15];
   out_5874123099794783116[16] = -nom_x[16] + true_x[16];
   out_5874123099794783116[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3022146375872577553) {
   out_3022146375872577553[0] = 1.0;
   out_3022146375872577553[1] = 0.0;
   out_3022146375872577553[2] = 0.0;
   out_3022146375872577553[3] = 0.0;
   out_3022146375872577553[4] = 0.0;
   out_3022146375872577553[5] = 0.0;
   out_3022146375872577553[6] = 0.0;
   out_3022146375872577553[7] = 0.0;
   out_3022146375872577553[8] = 0.0;
   out_3022146375872577553[9] = 0.0;
   out_3022146375872577553[10] = 0.0;
   out_3022146375872577553[11] = 0.0;
   out_3022146375872577553[12] = 0.0;
   out_3022146375872577553[13] = 0.0;
   out_3022146375872577553[14] = 0.0;
   out_3022146375872577553[15] = 0.0;
   out_3022146375872577553[16] = 0.0;
   out_3022146375872577553[17] = 0.0;
   out_3022146375872577553[18] = 0.0;
   out_3022146375872577553[19] = 1.0;
   out_3022146375872577553[20] = 0.0;
   out_3022146375872577553[21] = 0.0;
   out_3022146375872577553[22] = 0.0;
   out_3022146375872577553[23] = 0.0;
   out_3022146375872577553[24] = 0.0;
   out_3022146375872577553[25] = 0.0;
   out_3022146375872577553[26] = 0.0;
   out_3022146375872577553[27] = 0.0;
   out_3022146375872577553[28] = 0.0;
   out_3022146375872577553[29] = 0.0;
   out_3022146375872577553[30] = 0.0;
   out_3022146375872577553[31] = 0.0;
   out_3022146375872577553[32] = 0.0;
   out_3022146375872577553[33] = 0.0;
   out_3022146375872577553[34] = 0.0;
   out_3022146375872577553[35] = 0.0;
   out_3022146375872577553[36] = 0.0;
   out_3022146375872577553[37] = 0.0;
   out_3022146375872577553[38] = 1.0;
   out_3022146375872577553[39] = 0.0;
   out_3022146375872577553[40] = 0.0;
   out_3022146375872577553[41] = 0.0;
   out_3022146375872577553[42] = 0.0;
   out_3022146375872577553[43] = 0.0;
   out_3022146375872577553[44] = 0.0;
   out_3022146375872577553[45] = 0.0;
   out_3022146375872577553[46] = 0.0;
   out_3022146375872577553[47] = 0.0;
   out_3022146375872577553[48] = 0.0;
   out_3022146375872577553[49] = 0.0;
   out_3022146375872577553[50] = 0.0;
   out_3022146375872577553[51] = 0.0;
   out_3022146375872577553[52] = 0.0;
   out_3022146375872577553[53] = 0.0;
   out_3022146375872577553[54] = 0.0;
   out_3022146375872577553[55] = 0.0;
   out_3022146375872577553[56] = 0.0;
   out_3022146375872577553[57] = 1.0;
   out_3022146375872577553[58] = 0.0;
   out_3022146375872577553[59] = 0.0;
   out_3022146375872577553[60] = 0.0;
   out_3022146375872577553[61] = 0.0;
   out_3022146375872577553[62] = 0.0;
   out_3022146375872577553[63] = 0.0;
   out_3022146375872577553[64] = 0.0;
   out_3022146375872577553[65] = 0.0;
   out_3022146375872577553[66] = 0.0;
   out_3022146375872577553[67] = 0.0;
   out_3022146375872577553[68] = 0.0;
   out_3022146375872577553[69] = 0.0;
   out_3022146375872577553[70] = 0.0;
   out_3022146375872577553[71] = 0.0;
   out_3022146375872577553[72] = 0.0;
   out_3022146375872577553[73] = 0.0;
   out_3022146375872577553[74] = 0.0;
   out_3022146375872577553[75] = 0.0;
   out_3022146375872577553[76] = 1.0;
   out_3022146375872577553[77] = 0.0;
   out_3022146375872577553[78] = 0.0;
   out_3022146375872577553[79] = 0.0;
   out_3022146375872577553[80] = 0.0;
   out_3022146375872577553[81] = 0.0;
   out_3022146375872577553[82] = 0.0;
   out_3022146375872577553[83] = 0.0;
   out_3022146375872577553[84] = 0.0;
   out_3022146375872577553[85] = 0.0;
   out_3022146375872577553[86] = 0.0;
   out_3022146375872577553[87] = 0.0;
   out_3022146375872577553[88] = 0.0;
   out_3022146375872577553[89] = 0.0;
   out_3022146375872577553[90] = 0.0;
   out_3022146375872577553[91] = 0.0;
   out_3022146375872577553[92] = 0.0;
   out_3022146375872577553[93] = 0.0;
   out_3022146375872577553[94] = 0.0;
   out_3022146375872577553[95] = 1.0;
   out_3022146375872577553[96] = 0.0;
   out_3022146375872577553[97] = 0.0;
   out_3022146375872577553[98] = 0.0;
   out_3022146375872577553[99] = 0.0;
   out_3022146375872577553[100] = 0.0;
   out_3022146375872577553[101] = 0.0;
   out_3022146375872577553[102] = 0.0;
   out_3022146375872577553[103] = 0.0;
   out_3022146375872577553[104] = 0.0;
   out_3022146375872577553[105] = 0.0;
   out_3022146375872577553[106] = 0.0;
   out_3022146375872577553[107] = 0.0;
   out_3022146375872577553[108] = 0.0;
   out_3022146375872577553[109] = 0.0;
   out_3022146375872577553[110] = 0.0;
   out_3022146375872577553[111] = 0.0;
   out_3022146375872577553[112] = 0.0;
   out_3022146375872577553[113] = 0.0;
   out_3022146375872577553[114] = 1.0;
   out_3022146375872577553[115] = 0.0;
   out_3022146375872577553[116] = 0.0;
   out_3022146375872577553[117] = 0.0;
   out_3022146375872577553[118] = 0.0;
   out_3022146375872577553[119] = 0.0;
   out_3022146375872577553[120] = 0.0;
   out_3022146375872577553[121] = 0.0;
   out_3022146375872577553[122] = 0.0;
   out_3022146375872577553[123] = 0.0;
   out_3022146375872577553[124] = 0.0;
   out_3022146375872577553[125] = 0.0;
   out_3022146375872577553[126] = 0.0;
   out_3022146375872577553[127] = 0.0;
   out_3022146375872577553[128] = 0.0;
   out_3022146375872577553[129] = 0.0;
   out_3022146375872577553[130] = 0.0;
   out_3022146375872577553[131] = 0.0;
   out_3022146375872577553[132] = 0.0;
   out_3022146375872577553[133] = 1.0;
   out_3022146375872577553[134] = 0.0;
   out_3022146375872577553[135] = 0.0;
   out_3022146375872577553[136] = 0.0;
   out_3022146375872577553[137] = 0.0;
   out_3022146375872577553[138] = 0.0;
   out_3022146375872577553[139] = 0.0;
   out_3022146375872577553[140] = 0.0;
   out_3022146375872577553[141] = 0.0;
   out_3022146375872577553[142] = 0.0;
   out_3022146375872577553[143] = 0.0;
   out_3022146375872577553[144] = 0.0;
   out_3022146375872577553[145] = 0.0;
   out_3022146375872577553[146] = 0.0;
   out_3022146375872577553[147] = 0.0;
   out_3022146375872577553[148] = 0.0;
   out_3022146375872577553[149] = 0.0;
   out_3022146375872577553[150] = 0.0;
   out_3022146375872577553[151] = 0.0;
   out_3022146375872577553[152] = 1.0;
   out_3022146375872577553[153] = 0.0;
   out_3022146375872577553[154] = 0.0;
   out_3022146375872577553[155] = 0.0;
   out_3022146375872577553[156] = 0.0;
   out_3022146375872577553[157] = 0.0;
   out_3022146375872577553[158] = 0.0;
   out_3022146375872577553[159] = 0.0;
   out_3022146375872577553[160] = 0.0;
   out_3022146375872577553[161] = 0.0;
   out_3022146375872577553[162] = 0.0;
   out_3022146375872577553[163] = 0.0;
   out_3022146375872577553[164] = 0.0;
   out_3022146375872577553[165] = 0.0;
   out_3022146375872577553[166] = 0.0;
   out_3022146375872577553[167] = 0.0;
   out_3022146375872577553[168] = 0.0;
   out_3022146375872577553[169] = 0.0;
   out_3022146375872577553[170] = 0.0;
   out_3022146375872577553[171] = 1.0;
   out_3022146375872577553[172] = 0.0;
   out_3022146375872577553[173] = 0.0;
   out_3022146375872577553[174] = 0.0;
   out_3022146375872577553[175] = 0.0;
   out_3022146375872577553[176] = 0.0;
   out_3022146375872577553[177] = 0.0;
   out_3022146375872577553[178] = 0.0;
   out_3022146375872577553[179] = 0.0;
   out_3022146375872577553[180] = 0.0;
   out_3022146375872577553[181] = 0.0;
   out_3022146375872577553[182] = 0.0;
   out_3022146375872577553[183] = 0.0;
   out_3022146375872577553[184] = 0.0;
   out_3022146375872577553[185] = 0.0;
   out_3022146375872577553[186] = 0.0;
   out_3022146375872577553[187] = 0.0;
   out_3022146375872577553[188] = 0.0;
   out_3022146375872577553[189] = 0.0;
   out_3022146375872577553[190] = 1.0;
   out_3022146375872577553[191] = 0.0;
   out_3022146375872577553[192] = 0.0;
   out_3022146375872577553[193] = 0.0;
   out_3022146375872577553[194] = 0.0;
   out_3022146375872577553[195] = 0.0;
   out_3022146375872577553[196] = 0.0;
   out_3022146375872577553[197] = 0.0;
   out_3022146375872577553[198] = 0.0;
   out_3022146375872577553[199] = 0.0;
   out_3022146375872577553[200] = 0.0;
   out_3022146375872577553[201] = 0.0;
   out_3022146375872577553[202] = 0.0;
   out_3022146375872577553[203] = 0.0;
   out_3022146375872577553[204] = 0.0;
   out_3022146375872577553[205] = 0.0;
   out_3022146375872577553[206] = 0.0;
   out_3022146375872577553[207] = 0.0;
   out_3022146375872577553[208] = 0.0;
   out_3022146375872577553[209] = 1.0;
   out_3022146375872577553[210] = 0.0;
   out_3022146375872577553[211] = 0.0;
   out_3022146375872577553[212] = 0.0;
   out_3022146375872577553[213] = 0.0;
   out_3022146375872577553[214] = 0.0;
   out_3022146375872577553[215] = 0.0;
   out_3022146375872577553[216] = 0.0;
   out_3022146375872577553[217] = 0.0;
   out_3022146375872577553[218] = 0.0;
   out_3022146375872577553[219] = 0.0;
   out_3022146375872577553[220] = 0.0;
   out_3022146375872577553[221] = 0.0;
   out_3022146375872577553[222] = 0.0;
   out_3022146375872577553[223] = 0.0;
   out_3022146375872577553[224] = 0.0;
   out_3022146375872577553[225] = 0.0;
   out_3022146375872577553[226] = 0.0;
   out_3022146375872577553[227] = 0.0;
   out_3022146375872577553[228] = 1.0;
   out_3022146375872577553[229] = 0.0;
   out_3022146375872577553[230] = 0.0;
   out_3022146375872577553[231] = 0.0;
   out_3022146375872577553[232] = 0.0;
   out_3022146375872577553[233] = 0.0;
   out_3022146375872577553[234] = 0.0;
   out_3022146375872577553[235] = 0.0;
   out_3022146375872577553[236] = 0.0;
   out_3022146375872577553[237] = 0.0;
   out_3022146375872577553[238] = 0.0;
   out_3022146375872577553[239] = 0.0;
   out_3022146375872577553[240] = 0.0;
   out_3022146375872577553[241] = 0.0;
   out_3022146375872577553[242] = 0.0;
   out_3022146375872577553[243] = 0.0;
   out_3022146375872577553[244] = 0.0;
   out_3022146375872577553[245] = 0.0;
   out_3022146375872577553[246] = 0.0;
   out_3022146375872577553[247] = 1.0;
   out_3022146375872577553[248] = 0.0;
   out_3022146375872577553[249] = 0.0;
   out_3022146375872577553[250] = 0.0;
   out_3022146375872577553[251] = 0.0;
   out_3022146375872577553[252] = 0.0;
   out_3022146375872577553[253] = 0.0;
   out_3022146375872577553[254] = 0.0;
   out_3022146375872577553[255] = 0.0;
   out_3022146375872577553[256] = 0.0;
   out_3022146375872577553[257] = 0.0;
   out_3022146375872577553[258] = 0.0;
   out_3022146375872577553[259] = 0.0;
   out_3022146375872577553[260] = 0.0;
   out_3022146375872577553[261] = 0.0;
   out_3022146375872577553[262] = 0.0;
   out_3022146375872577553[263] = 0.0;
   out_3022146375872577553[264] = 0.0;
   out_3022146375872577553[265] = 0.0;
   out_3022146375872577553[266] = 1.0;
   out_3022146375872577553[267] = 0.0;
   out_3022146375872577553[268] = 0.0;
   out_3022146375872577553[269] = 0.0;
   out_3022146375872577553[270] = 0.0;
   out_3022146375872577553[271] = 0.0;
   out_3022146375872577553[272] = 0.0;
   out_3022146375872577553[273] = 0.0;
   out_3022146375872577553[274] = 0.0;
   out_3022146375872577553[275] = 0.0;
   out_3022146375872577553[276] = 0.0;
   out_3022146375872577553[277] = 0.0;
   out_3022146375872577553[278] = 0.0;
   out_3022146375872577553[279] = 0.0;
   out_3022146375872577553[280] = 0.0;
   out_3022146375872577553[281] = 0.0;
   out_3022146375872577553[282] = 0.0;
   out_3022146375872577553[283] = 0.0;
   out_3022146375872577553[284] = 0.0;
   out_3022146375872577553[285] = 1.0;
   out_3022146375872577553[286] = 0.0;
   out_3022146375872577553[287] = 0.0;
   out_3022146375872577553[288] = 0.0;
   out_3022146375872577553[289] = 0.0;
   out_3022146375872577553[290] = 0.0;
   out_3022146375872577553[291] = 0.0;
   out_3022146375872577553[292] = 0.0;
   out_3022146375872577553[293] = 0.0;
   out_3022146375872577553[294] = 0.0;
   out_3022146375872577553[295] = 0.0;
   out_3022146375872577553[296] = 0.0;
   out_3022146375872577553[297] = 0.0;
   out_3022146375872577553[298] = 0.0;
   out_3022146375872577553[299] = 0.0;
   out_3022146375872577553[300] = 0.0;
   out_3022146375872577553[301] = 0.0;
   out_3022146375872577553[302] = 0.0;
   out_3022146375872577553[303] = 0.0;
   out_3022146375872577553[304] = 1.0;
   out_3022146375872577553[305] = 0.0;
   out_3022146375872577553[306] = 0.0;
   out_3022146375872577553[307] = 0.0;
   out_3022146375872577553[308] = 0.0;
   out_3022146375872577553[309] = 0.0;
   out_3022146375872577553[310] = 0.0;
   out_3022146375872577553[311] = 0.0;
   out_3022146375872577553[312] = 0.0;
   out_3022146375872577553[313] = 0.0;
   out_3022146375872577553[314] = 0.0;
   out_3022146375872577553[315] = 0.0;
   out_3022146375872577553[316] = 0.0;
   out_3022146375872577553[317] = 0.0;
   out_3022146375872577553[318] = 0.0;
   out_3022146375872577553[319] = 0.0;
   out_3022146375872577553[320] = 0.0;
   out_3022146375872577553[321] = 0.0;
   out_3022146375872577553[322] = 0.0;
   out_3022146375872577553[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5302456385426177188) {
   out_5302456385426177188[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5302456385426177188[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5302456385426177188[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5302456385426177188[3] = dt*state[12] + state[3];
   out_5302456385426177188[4] = dt*state[13] + state[4];
   out_5302456385426177188[5] = dt*state[14] + state[5];
   out_5302456385426177188[6] = state[6];
   out_5302456385426177188[7] = state[7];
   out_5302456385426177188[8] = state[8];
   out_5302456385426177188[9] = state[9];
   out_5302456385426177188[10] = state[10];
   out_5302456385426177188[11] = state[11];
   out_5302456385426177188[12] = state[12];
   out_5302456385426177188[13] = state[13];
   out_5302456385426177188[14] = state[14];
   out_5302456385426177188[15] = state[15];
   out_5302456385426177188[16] = state[16];
   out_5302456385426177188[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1927640881032223950) {
   out_1927640881032223950[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1927640881032223950[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1927640881032223950[2] = 0;
   out_1927640881032223950[3] = 0;
   out_1927640881032223950[4] = 0;
   out_1927640881032223950[5] = 0;
   out_1927640881032223950[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1927640881032223950[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1927640881032223950[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1927640881032223950[9] = 0;
   out_1927640881032223950[10] = 0;
   out_1927640881032223950[11] = 0;
   out_1927640881032223950[12] = 0;
   out_1927640881032223950[13] = 0;
   out_1927640881032223950[14] = 0;
   out_1927640881032223950[15] = 0;
   out_1927640881032223950[16] = 0;
   out_1927640881032223950[17] = 0;
   out_1927640881032223950[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1927640881032223950[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1927640881032223950[20] = 0;
   out_1927640881032223950[21] = 0;
   out_1927640881032223950[22] = 0;
   out_1927640881032223950[23] = 0;
   out_1927640881032223950[24] = 0;
   out_1927640881032223950[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1927640881032223950[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1927640881032223950[27] = 0;
   out_1927640881032223950[28] = 0;
   out_1927640881032223950[29] = 0;
   out_1927640881032223950[30] = 0;
   out_1927640881032223950[31] = 0;
   out_1927640881032223950[32] = 0;
   out_1927640881032223950[33] = 0;
   out_1927640881032223950[34] = 0;
   out_1927640881032223950[35] = 0;
   out_1927640881032223950[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1927640881032223950[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1927640881032223950[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1927640881032223950[39] = 0;
   out_1927640881032223950[40] = 0;
   out_1927640881032223950[41] = 0;
   out_1927640881032223950[42] = 0;
   out_1927640881032223950[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1927640881032223950[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1927640881032223950[45] = 0;
   out_1927640881032223950[46] = 0;
   out_1927640881032223950[47] = 0;
   out_1927640881032223950[48] = 0;
   out_1927640881032223950[49] = 0;
   out_1927640881032223950[50] = 0;
   out_1927640881032223950[51] = 0;
   out_1927640881032223950[52] = 0;
   out_1927640881032223950[53] = 0;
   out_1927640881032223950[54] = 0;
   out_1927640881032223950[55] = 0;
   out_1927640881032223950[56] = 0;
   out_1927640881032223950[57] = 1;
   out_1927640881032223950[58] = 0;
   out_1927640881032223950[59] = 0;
   out_1927640881032223950[60] = 0;
   out_1927640881032223950[61] = 0;
   out_1927640881032223950[62] = 0;
   out_1927640881032223950[63] = 0;
   out_1927640881032223950[64] = 0;
   out_1927640881032223950[65] = 0;
   out_1927640881032223950[66] = dt;
   out_1927640881032223950[67] = 0;
   out_1927640881032223950[68] = 0;
   out_1927640881032223950[69] = 0;
   out_1927640881032223950[70] = 0;
   out_1927640881032223950[71] = 0;
   out_1927640881032223950[72] = 0;
   out_1927640881032223950[73] = 0;
   out_1927640881032223950[74] = 0;
   out_1927640881032223950[75] = 0;
   out_1927640881032223950[76] = 1;
   out_1927640881032223950[77] = 0;
   out_1927640881032223950[78] = 0;
   out_1927640881032223950[79] = 0;
   out_1927640881032223950[80] = 0;
   out_1927640881032223950[81] = 0;
   out_1927640881032223950[82] = 0;
   out_1927640881032223950[83] = 0;
   out_1927640881032223950[84] = 0;
   out_1927640881032223950[85] = dt;
   out_1927640881032223950[86] = 0;
   out_1927640881032223950[87] = 0;
   out_1927640881032223950[88] = 0;
   out_1927640881032223950[89] = 0;
   out_1927640881032223950[90] = 0;
   out_1927640881032223950[91] = 0;
   out_1927640881032223950[92] = 0;
   out_1927640881032223950[93] = 0;
   out_1927640881032223950[94] = 0;
   out_1927640881032223950[95] = 1;
   out_1927640881032223950[96] = 0;
   out_1927640881032223950[97] = 0;
   out_1927640881032223950[98] = 0;
   out_1927640881032223950[99] = 0;
   out_1927640881032223950[100] = 0;
   out_1927640881032223950[101] = 0;
   out_1927640881032223950[102] = 0;
   out_1927640881032223950[103] = 0;
   out_1927640881032223950[104] = dt;
   out_1927640881032223950[105] = 0;
   out_1927640881032223950[106] = 0;
   out_1927640881032223950[107] = 0;
   out_1927640881032223950[108] = 0;
   out_1927640881032223950[109] = 0;
   out_1927640881032223950[110] = 0;
   out_1927640881032223950[111] = 0;
   out_1927640881032223950[112] = 0;
   out_1927640881032223950[113] = 0;
   out_1927640881032223950[114] = 1;
   out_1927640881032223950[115] = 0;
   out_1927640881032223950[116] = 0;
   out_1927640881032223950[117] = 0;
   out_1927640881032223950[118] = 0;
   out_1927640881032223950[119] = 0;
   out_1927640881032223950[120] = 0;
   out_1927640881032223950[121] = 0;
   out_1927640881032223950[122] = 0;
   out_1927640881032223950[123] = 0;
   out_1927640881032223950[124] = 0;
   out_1927640881032223950[125] = 0;
   out_1927640881032223950[126] = 0;
   out_1927640881032223950[127] = 0;
   out_1927640881032223950[128] = 0;
   out_1927640881032223950[129] = 0;
   out_1927640881032223950[130] = 0;
   out_1927640881032223950[131] = 0;
   out_1927640881032223950[132] = 0;
   out_1927640881032223950[133] = 1;
   out_1927640881032223950[134] = 0;
   out_1927640881032223950[135] = 0;
   out_1927640881032223950[136] = 0;
   out_1927640881032223950[137] = 0;
   out_1927640881032223950[138] = 0;
   out_1927640881032223950[139] = 0;
   out_1927640881032223950[140] = 0;
   out_1927640881032223950[141] = 0;
   out_1927640881032223950[142] = 0;
   out_1927640881032223950[143] = 0;
   out_1927640881032223950[144] = 0;
   out_1927640881032223950[145] = 0;
   out_1927640881032223950[146] = 0;
   out_1927640881032223950[147] = 0;
   out_1927640881032223950[148] = 0;
   out_1927640881032223950[149] = 0;
   out_1927640881032223950[150] = 0;
   out_1927640881032223950[151] = 0;
   out_1927640881032223950[152] = 1;
   out_1927640881032223950[153] = 0;
   out_1927640881032223950[154] = 0;
   out_1927640881032223950[155] = 0;
   out_1927640881032223950[156] = 0;
   out_1927640881032223950[157] = 0;
   out_1927640881032223950[158] = 0;
   out_1927640881032223950[159] = 0;
   out_1927640881032223950[160] = 0;
   out_1927640881032223950[161] = 0;
   out_1927640881032223950[162] = 0;
   out_1927640881032223950[163] = 0;
   out_1927640881032223950[164] = 0;
   out_1927640881032223950[165] = 0;
   out_1927640881032223950[166] = 0;
   out_1927640881032223950[167] = 0;
   out_1927640881032223950[168] = 0;
   out_1927640881032223950[169] = 0;
   out_1927640881032223950[170] = 0;
   out_1927640881032223950[171] = 1;
   out_1927640881032223950[172] = 0;
   out_1927640881032223950[173] = 0;
   out_1927640881032223950[174] = 0;
   out_1927640881032223950[175] = 0;
   out_1927640881032223950[176] = 0;
   out_1927640881032223950[177] = 0;
   out_1927640881032223950[178] = 0;
   out_1927640881032223950[179] = 0;
   out_1927640881032223950[180] = 0;
   out_1927640881032223950[181] = 0;
   out_1927640881032223950[182] = 0;
   out_1927640881032223950[183] = 0;
   out_1927640881032223950[184] = 0;
   out_1927640881032223950[185] = 0;
   out_1927640881032223950[186] = 0;
   out_1927640881032223950[187] = 0;
   out_1927640881032223950[188] = 0;
   out_1927640881032223950[189] = 0;
   out_1927640881032223950[190] = 1;
   out_1927640881032223950[191] = 0;
   out_1927640881032223950[192] = 0;
   out_1927640881032223950[193] = 0;
   out_1927640881032223950[194] = 0;
   out_1927640881032223950[195] = 0;
   out_1927640881032223950[196] = 0;
   out_1927640881032223950[197] = 0;
   out_1927640881032223950[198] = 0;
   out_1927640881032223950[199] = 0;
   out_1927640881032223950[200] = 0;
   out_1927640881032223950[201] = 0;
   out_1927640881032223950[202] = 0;
   out_1927640881032223950[203] = 0;
   out_1927640881032223950[204] = 0;
   out_1927640881032223950[205] = 0;
   out_1927640881032223950[206] = 0;
   out_1927640881032223950[207] = 0;
   out_1927640881032223950[208] = 0;
   out_1927640881032223950[209] = 1;
   out_1927640881032223950[210] = 0;
   out_1927640881032223950[211] = 0;
   out_1927640881032223950[212] = 0;
   out_1927640881032223950[213] = 0;
   out_1927640881032223950[214] = 0;
   out_1927640881032223950[215] = 0;
   out_1927640881032223950[216] = 0;
   out_1927640881032223950[217] = 0;
   out_1927640881032223950[218] = 0;
   out_1927640881032223950[219] = 0;
   out_1927640881032223950[220] = 0;
   out_1927640881032223950[221] = 0;
   out_1927640881032223950[222] = 0;
   out_1927640881032223950[223] = 0;
   out_1927640881032223950[224] = 0;
   out_1927640881032223950[225] = 0;
   out_1927640881032223950[226] = 0;
   out_1927640881032223950[227] = 0;
   out_1927640881032223950[228] = 1;
   out_1927640881032223950[229] = 0;
   out_1927640881032223950[230] = 0;
   out_1927640881032223950[231] = 0;
   out_1927640881032223950[232] = 0;
   out_1927640881032223950[233] = 0;
   out_1927640881032223950[234] = 0;
   out_1927640881032223950[235] = 0;
   out_1927640881032223950[236] = 0;
   out_1927640881032223950[237] = 0;
   out_1927640881032223950[238] = 0;
   out_1927640881032223950[239] = 0;
   out_1927640881032223950[240] = 0;
   out_1927640881032223950[241] = 0;
   out_1927640881032223950[242] = 0;
   out_1927640881032223950[243] = 0;
   out_1927640881032223950[244] = 0;
   out_1927640881032223950[245] = 0;
   out_1927640881032223950[246] = 0;
   out_1927640881032223950[247] = 1;
   out_1927640881032223950[248] = 0;
   out_1927640881032223950[249] = 0;
   out_1927640881032223950[250] = 0;
   out_1927640881032223950[251] = 0;
   out_1927640881032223950[252] = 0;
   out_1927640881032223950[253] = 0;
   out_1927640881032223950[254] = 0;
   out_1927640881032223950[255] = 0;
   out_1927640881032223950[256] = 0;
   out_1927640881032223950[257] = 0;
   out_1927640881032223950[258] = 0;
   out_1927640881032223950[259] = 0;
   out_1927640881032223950[260] = 0;
   out_1927640881032223950[261] = 0;
   out_1927640881032223950[262] = 0;
   out_1927640881032223950[263] = 0;
   out_1927640881032223950[264] = 0;
   out_1927640881032223950[265] = 0;
   out_1927640881032223950[266] = 1;
   out_1927640881032223950[267] = 0;
   out_1927640881032223950[268] = 0;
   out_1927640881032223950[269] = 0;
   out_1927640881032223950[270] = 0;
   out_1927640881032223950[271] = 0;
   out_1927640881032223950[272] = 0;
   out_1927640881032223950[273] = 0;
   out_1927640881032223950[274] = 0;
   out_1927640881032223950[275] = 0;
   out_1927640881032223950[276] = 0;
   out_1927640881032223950[277] = 0;
   out_1927640881032223950[278] = 0;
   out_1927640881032223950[279] = 0;
   out_1927640881032223950[280] = 0;
   out_1927640881032223950[281] = 0;
   out_1927640881032223950[282] = 0;
   out_1927640881032223950[283] = 0;
   out_1927640881032223950[284] = 0;
   out_1927640881032223950[285] = 1;
   out_1927640881032223950[286] = 0;
   out_1927640881032223950[287] = 0;
   out_1927640881032223950[288] = 0;
   out_1927640881032223950[289] = 0;
   out_1927640881032223950[290] = 0;
   out_1927640881032223950[291] = 0;
   out_1927640881032223950[292] = 0;
   out_1927640881032223950[293] = 0;
   out_1927640881032223950[294] = 0;
   out_1927640881032223950[295] = 0;
   out_1927640881032223950[296] = 0;
   out_1927640881032223950[297] = 0;
   out_1927640881032223950[298] = 0;
   out_1927640881032223950[299] = 0;
   out_1927640881032223950[300] = 0;
   out_1927640881032223950[301] = 0;
   out_1927640881032223950[302] = 0;
   out_1927640881032223950[303] = 0;
   out_1927640881032223950[304] = 1;
   out_1927640881032223950[305] = 0;
   out_1927640881032223950[306] = 0;
   out_1927640881032223950[307] = 0;
   out_1927640881032223950[308] = 0;
   out_1927640881032223950[309] = 0;
   out_1927640881032223950[310] = 0;
   out_1927640881032223950[311] = 0;
   out_1927640881032223950[312] = 0;
   out_1927640881032223950[313] = 0;
   out_1927640881032223950[314] = 0;
   out_1927640881032223950[315] = 0;
   out_1927640881032223950[316] = 0;
   out_1927640881032223950[317] = 0;
   out_1927640881032223950[318] = 0;
   out_1927640881032223950[319] = 0;
   out_1927640881032223950[320] = 0;
   out_1927640881032223950[321] = 0;
   out_1927640881032223950[322] = 0;
   out_1927640881032223950[323] = 1;
}
void h_4(double *state, double *unused, double *out_61275514649772420) {
   out_61275514649772420[0] = state[6] + state[9];
   out_61275514649772420[1] = state[7] + state[10];
   out_61275514649772420[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8870228182624536274) {
   out_8870228182624536274[0] = 0;
   out_8870228182624536274[1] = 0;
   out_8870228182624536274[2] = 0;
   out_8870228182624536274[3] = 0;
   out_8870228182624536274[4] = 0;
   out_8870228182624536274[5] = 0;
   out_8870228182624536274[6] = 1;
   out_8870228182624536274[7] = 0;
   out_8870228182624536274[8] = 0;
   out_8870228182624536274[9] = 1;
   out_8870228182624536274[10] = 0;
   out_8870228182624536274[11] = 0;
   out_8870228182624536274[12] = 0;
   out_8870228182624536274[13] = 0;
   out_8870228182624536274[14] = 0;
   out_8870228182624536274[15] = 0;
   out_8870228182624536274[16] = 0;
   out_8870228182624536274[17] = 0;
   out_8870228182624536274[18] = 0;
   out_8870228182624536274[19] = 0;
   out_8870228182624536274[20] = 0;
   out_8870228182624536274[21] = 0;
   out_8870228182624536274[22] = 0;
   out_8870228182624536274[23] = 0;
   out_8870228182624536274[24] = 0;
   out_8870228182624536274[25] = 1;
   out_8870228182624536274[26] = 0;
   out_8870228182624536274[27] = 0;
   out_8870228182624536274[28] = 1;
   out_8870228182624536274[29] = 0;
   out_8870228182624536274[30] = 0;
   out_8870228182624536274[31] = 0;
   out_8870228182624536274[32] = 0;
   out_8870228182624536274[33] = 0;
   out_8870228182624536274[34] = 0;
   out_8870228182624536274[35] = 0;
   out_8870228182624536274[36] = 0;
   out_8870228182624536274[37] = 0;
   out_8870228182624536274[38] = 0;
   out_8870228182624536274[39] = 0;
   out_8870228182624536274[40] = 0;
   out_8870228182624536274[41] = 0;
   out_8870228182624536274[42] = 0;
   out_8870228182624536274[43] = 0;
   out_8870228182624536274[44] = 1;
   out_8870228182624536274[45] = 0;
   out_8870228182624536274[46] = 0;
   out_8870228182624536274[47] = 1;
   out_8870228182624536274[48] = 0;
   out_8870228182624536274[49] = 0;
   out_8870228182624536274[50] = 0;
   out_8870228182624536274[51] = 0;
   out_8870228182624536274[52] = 0;
   out_8870228182624536274[53] = 0;
}
void h_10(double *state, double *unused, double *out_3113540078229992172) {
   out_3113540078229992172[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_3113540078229992172[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_3113540078229992172[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8133353293446248542) {
   out_8133353293446248542[0] = 0;
   out_8133353293446248542[1] = 9.8100000000000005*cos(state[1]);
   out_8133353293446248542[2] = 0;
   out_8133353293446248542[3] = 0;
   out_8133353293446248542[4] = -state[8];
   out_8133353293446248542[5] = state[7];
   out_8133353293446248542[6] = 0;
   out_8133353293446248542[7] = state[5];
   out_8133353293446248542[8] = -state[4];
   out_8133353293446248542[9] = 0;
   out_8133353293446248542[10] = 0;
   out_8133353293446248542[11] = 0;
   out_8133353293446248542[12] = 1;
   out_8133353293446248542[13] = 0;
   out_8133353293446248542[14] = 0;
   out_8133353293446248542[15] = 1;
   out_8133353293446248542[16] = 0;
   out_8133353293446248542[17] = 0;
   out_8133353293446248542[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8133353293446248542[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8133353293446248542[20] = 0;
   out_8133353293446248542[21] = state[8];
   out_8133353293446248542[22] = 0;
   out_8133353293446248542[23] = -state[6];
   out_8133353293446248542[24] = -state[5];
   out_8133353293446248542[25] = 0;
   out_8133353293446248542[26] = state[3];
   out_8133353293446248542[27] = 0;
   out_8133353293446248542[28] = 0;
   out_8133353293446248542[29] = 0;
   out_8133353293446248542[30] = 0;
   out_8133353293446248542[31] = 1;
   out_8133353293446248542[32] = 0;
   out_8133353293446248542[33] = 0;
   out_8133353293446248542[34] = 1;
   out_8133353293446248542[35] = 0;
   out_8133353293446248542[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8133353293446248542[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8133353293446248542[38] = 0;
   out_8133353293446248542[39] = -state[7];
   out_8133353293446248542[40] = state[6];
   out_8133353293446248542[41] = 0;
   out_8133353293446248542[42] = state[4];
   out_8133353293446248542[43] = -state[3];
   out_8133353293446248542[44] = 0;
   out_8133353293446248542[45] = 0;
   out_8133353293446248542[46] = 0;
   out_8133353293446248542[47] = 0;
   out_8133353293446248542[48] = 0;
   out_8133353293446248542[49] = 0;
   out_8133353293446248542[50] = 1;
   out_8133353293446248542[51] = 0;
   out_8133353293446248542[52] = 0;
   out_8133353293446248542[53] = 1;
}
void h_13(double *state, double *unused, double *out_9190534258819938312) {
   out_9190534258819938312[0] = state[3];
   out_9190534258819938312[1] = state[4];
   out_9190534258819938312[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5657954357292203473) {
   out_5657954357292203473[0] = 0;
   out_5657954357292203473[1] = 0;
   out_5657954357292203473[2] = 0;
   out_5657954357292203473[3] = 1;
   out_5657954357292203473[4] = 0;
   out_5657954357292203473[5] = 0;
   out_5657954357292203473[6] = 0;
   out_5657954357292203473[7] = 0;
   out_5657954357292203473[8] = 0;
   out_5657954357292203473[9] = 0;
   out_5657954357292203473[10] = 0;
   out_5657954357292203473[11] = 0;
   out_5657954357292203473[12] = 0;
   out_5657954357292203473[13] = 0;
   out_5657954357292203473[14] = 0;
   out_5657954357292203473[15] = 0;
   out_5657954357292203473[16] = 0;
   out_5657954357292203473[17] = 0;
   out_5657954357292203473[18] = 0;
   out_5657954357292203473[19] = 0;
   out_5657954357292203473[20] = 0;
   out_5657954357292203473[21] = 0;
   out_5657954357292203473[22] = 1;
   out_5657954357292203473[23] = 0;
   out_5657954357292203473[24] = 0;
   out_5657954357292203473[25] = 0;
   out_5657954357292203473[26] = 0;
   out_5657954357292203473[27] = 0;
   out_5657954357292203473[28] = 0;
   out_5657954357292203473[29] = 0;
   out_5657954357292203473[30] = 0;
   out_5657954357292203473[31] = 0;
   out_5657954357292203473[32] = 0;
   out_5657954357292203473[33] = 0;
   out_5657954357292203473[34] = 0;
   out_5657954357292203473[35] = 0;
   out_5657954357292203473[36] = 0;
   out_5657954357292203473[37] = 0;
   out_5657954357292203473[38] = 0;
   out_5657954357292203473[39] = 0;
   out_5657954357292203473[40] = 0;
   out_5657954357292203473[41] = 1;
   out_5657954357292203473[42] = 0;
   out_5657954357292203473[43] = 0;
   out_5657954357292203473[44] = 0;
   out_5657954357292203473[45] = 0;
   out_5657954357292203473[46] = 0;
   out_5657954357292203473[47] = 0;
   out_5657954357292203473[48] = 0;
   out_5657954357292203473[49] = 0;
   out_5657954357292203473[50] = 0;
   out_5657954357292203473[51] = 0;
   out_5657954357292203473[52] = 0;
   out_5657954357292203473[53] = 0;
}
void h_14(double *state, double *unused, double *out_4475366908773028757) {
   out_4475366908773028757[0] = state[6];
   out_4475366908773028757[1] = state[7];
   out_4475366908773028757[2] = state[8];
}
void H_14(double *state, double *unused, double *out_9141399364440131743) {
   out_9141399364440131743[0] = 0;
   out_9141399364440131743[1] = 0;
   out_9141399364440131743[2] = 0;
   out_9141399364440131743[3] = 0;
   out_9141399364440131743[4] = 0;
   out_9141399364440131743[5] = 0;
   out_9141399364440131743[6] = 1;
   out_9141399364440131743[7] = 0;
   out_9141399364440131743[8] = 0;
   out_9141399364440131743[9] = 0;
   out_9141399364440131743[10] = 0;
   out_9141399364440131743[11] = 0;
   out_9141399364440131743[12] = 0;
   out_9141399364440131743[13] = 0;
   out_9141399364440131743[14] = 0;
   out_9141399364440131743[15] = 0;
   out_9141399364440131743[16] = 0;
   out_9141399364440131743[17] = 0;
   out_9141399364440131743[18] = 0;
   out_9141399364440131743[19] = 0;
   out_9141399364440131743[20] = 0;
   out_9141399364440131743[21] = 0;
   out_9141399364440131743[22] = 0;
   out_9141399364440131743[23] = 0;
   out_9141399364440131743[24] = 0;
   out_9141399364440131743[25] = 1;
   out_9141399364440131743[26] = 0;
   out_9141399364440131743[27] = 0;
   out_9141399364440131743[28] = 0;
   out_9141399364440131743[29] = 0;
   out_9141399364440131743[30] = 0;
   out_9141399364440131743[31] = 0;
   out_9141399364440131743[32] = 0;
   out_9141399364440131743[33] = 0;
   out_9141399364440131743[34] = 0;
   out_9141399364440131743[35] = 0;
   out_9141399364440131743[36] = 0;
   out_9141399364440131743[37] = 0;
   out_9141399364440131743[38] = 0;
   out_9141399364440131743[39] = 0;
   out_9141399364440131743[40] = 0;
   out_9141399364440131743[41] = 0;
   out_9141399364440131743[42] = 0;
   out_9141399364440131743[43] = 0;
   out_9141399364440131743[44] = 1;
   out_9141399364440131743[45] = 0;
   out_9141399364440131743[46] = 0;
   out_9141399364440131743[47] = 0;
   out_9141399364440131743[48] = 0;
   out_9141399364440131743[49] = 0;
   out_9141399364440131743[50] = 0;
   out_9141399364440131743[51] = 0;
   out_9141399364440131743[52] = 0;
   out_9141399364440131743[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_6057666269876821352) {
  err_fun(nom_x, delta_x, out_6057666269876821352);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5874123099794783116) {
  inv_err_fun(nom_x, true_x, out_5874123099794783116);
}
void pose_H_mod_fun(double *state, double *out_3022146375872577553) {
  H_mod_fun(state, out_3022146375872577553);
}
void pose_f_fun(double *state, double dt, double *out_5302456385426177188) {
  f_fun(state,  dt, out_5302456385426177188);
}
void pose_F_fun(double *state, double dt, double *out_1927640881032223950) {
  F_fun(state,  dt, out_1927640881032223950);
}
void pose_h_4(double *state, double *unused, double *out_61275514649772420) {
  h_4(state, unused, out_61275514649772420);
}
void pose_H_4(double *state, double *unused, double *out_8870228182624536274) {
  H_4(state, unused, out_8870228182624536274);
}
void pose_h_10(double *state, double *unused, double *out_3113540078229992172) {
  h_10(state, unused, out_3113540078229992172);
}
void pose_H_10(double *state, double *unused, double *out_8133353293446248542) {
  H_10(state, unused, out_8133353293446248542);
}
void pose_h_13(double *state, double *unused, double *out_9190534258819938312) {
  h_13(state, unused, out_9190534258819938312);
}
void pose_H_13(double *state, double *unused, double *out_5657954357292203473) {
  H_13(state, unused, out_5657954357292203473);
}
void pose_h_14(double *state, double *unused, double *out_4475366908773028757) {
  h_14(state, unused, out_4475366908773028757);
}
void pose_H_14(double *state, double *unused, double *out_9141399364440131743) {
  H_14(state, unused, out_9141399364440131743);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
