#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_90543357710769815) {
   out_90543357710769815[0] = delta_x[0] + nom_x[0];
   out_90543357710769815[1] = delta_x[1] + nom_x[1];
   out_90543357710769815[2] = delta_x[2] + nom_x[2];
   out_90543357710769815[3] = delta_x[3] + nom_x[3];
   out_90543357710769815[4] = delta_x[4] + nom_x[4];
   out_90543357710769815[5] = delta_x[5] + nom_x[5];
   out_90543357710769815[6] = delta_x[6] + nom_x[6];
   out_90543357710769815[7] = delta_x[7] + nom_x[7];
   out_90543357710769815[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_17966199294720670) {
   out_17966199294720670[0] = -nom_x[0] + true_x[0];
   out_17966199294720670[1] = -nom_x[1] + true_x[1];
   out_17966199294720670[2] = -nom_x[2] + true_x[2];
   out_17966199294720670[3] = -nom_x[3] + true_x[3];
   out_17966199294720670[4] = -nom_x[4] + true_x[4];
   out_17966199294720670[5] = -nom_x[5] + true_x[5];
   out_17966199294720670[6] = -nom_x[6] + true_x[6];
   out_17966199294720670[7] = -nom_x[7] + true_x[7];
   out_17966199294720670[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_844907361945072597) {
   out_844907361945072597[0] = 1.0;
   out_844907361945072597[1] = 0.0;
   out_844907361945072597[2] = 0.0;
   out_844907361945072597[3] = 0.0;
   out_844907361945072597[4] = 0.0;
   out_844907361945072597[5] = 0.0;
   out_844907361945072597[6] = 0.0;
   out_844907361945072597[7] = 0.0;
   out_844907361945072597[8] = 0.0;
   out_844907361945072597[9] = 0.0;
   out_844907361945072597[10] = 1.0;
   out_844907361945072597[11] = 0.0;
   out_844907361945072597[12] = 0.0;
   out_844907361945072597[13] = 0.0;
   out_844907361945072597[14] = 0.0;
   out_844907361945072597[15] = 0.0;
   out_844907361945072597[16] = 0.0;
   out_844907361945072597[17] = 0.0;
   out_844907361945072597[18] = 0.0;
   out_844907361945072597[19] = 0.0;
   out_844907361945072597[20] = 1.0;
   out_844907361945072597[21] = 0.0;
   out_844907361945072597[22] = 0.0;
   out_844907361945072597[23] = 0.0;
   out_844907361945072597[24] = 0.0;
   out_844907361945072597[25] = 0.0;
   out_844907361945072597[26] = 0.0;
   out_844907361945072597[27] = 0.0;
   out_844907361945072597[28] = 0.0;
   out_844907361945072597[29] = 0.0;
   out_844907361945072597[30] = 1.0;
   out_844907361945072597[31] = 0.0;
   out_844907361945072597[32] = 0.0;
   out_844907361945072597[33] = 0.0;
   out_844907361945072597[34] = 0.0;
   out_844907361945072597[35] = 0.0;
   out_844907361945072597[36] = 0.0;
   out_844907361945072597[37] = 0.0;
   out_844907361945072597[38] = 0.0;
   out_844907361945072597[39] = 0.0;
   out_844907361945072597[40] = 1.0;
   out_844907361945072597[41] = 0.0;
   out_844907361945072597[42] = 0.0;
   out_844907361945072597[43] = 0.0;
   out_844907361945072597[44] = 0.0;
   out_844907361945072597[45] = 0.0;
   out_844907361945072597[46] = 0.0;
   out_844907361945072597[47] = 0.0;
   out_844907361945072597[48] = 0.0;
   out_844907361945072597[49] = 0.0;
   out_844907361945072597[50] = 1.0;
   out_844907361945072597[51] = 0.0;
   out_844907361945072597[52] = 0.0;
   out_844907361945072597[53] = 0.0;
   out_844907361945072597[54] = 0.0;
   out_844907361945072597[55] = 0.0;
   out_844907361945072597[56] = 0.0;
   out_844907361945072597[57] = 0.0;
   out_844907361945072597[58] = 0.0;
   out_844907361945072597[59] = 0.0;
   out_844907361945072597[60] = 1.0;
   out_844907361945072597[61] = 0.0;
   out_844907361945072597[62] = 0.0;
   out_844907361945072597[63] = 0.0;
   out_844907361945072597[64] = 0.0;
   out_844907361945072597[65] = 0.0;
   out_844907361945072597[66] = 0.0;
   out_844907361945072597[67] = 0.0;
   out_844907361945072597[68] = 0.0;
   out_844907361945072597[69] = 0.0;
   out_844907361945072597[70] = 1.0;
   out_844907361945072597[71] = 0.0;
   out_844907361945072597[72] = 0.0;
   out_844907361945072597[73] = 0.0;
   out_844907361945072597[74] = 0.0;
   out_844907361945072597[75] = 0.0;
   out_844907361945072597[76] = 0.0;
   out_844907361945072597[77] = 0.0;
   out_844907361945072597[78] = 0.0;
   out_844907361945072597[79] = 0.0;
   out_844907361945072597[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7814100581081982154) {
   out_7814100581081982154[0] = state[0];
   out_7814100581081982154[1] = state[1];
   out_7814100581081982154[2] = state[2];
   out_7814100581081982154[3] = state[3];
   out_7814100581081982154[4] = state[4];
   out_7814100581081982154[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7814100581081982154[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7814100581081982154[7] = state[7];
   out_7814100581081982154[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8005261171107713583) {
   out_8005261171107713583[0] = 1;
   out_8005261171107713583[1] = 0;
   out_8005261171107713583[2] = 0;
   out_8005261171107713583[3] = 0;
   out_8005261171107713583[4] = 0;
   out_8005261171107713583[5] = 0;
   out_8005261171107713583[6] = 0;
   out_8005261171107713583[7] = 0;
   out_8005261171107713583[8] = 0;
   out_8005261171107713583[9] = 0;
   out_8005261171107713583[10] = 1;
   out_8005261171107713583[11] = 0;
   out_8005261171107713583[12] = 0;
   out_8005261171107713583[13] = 0;
   out_8005261171107713583[14] = 0;
   out_8005261171107713583[15] = 0;
   out_8005261171107713583[16] = 0;
   out_8005261171107713583[17] = 0;
   out_8005261171107713583[18] = 0;
   out_8005261171107713583[19] = 0;
   out_8005261171107713583[20] = 1;
   out_8005261171107713583[21] = 0;
   out_8005261171107713583[22] = 0;
   out_8005261171107713583[23] = 0;
   out_8005261171107713583[24] = 0;
   out_8005261171107713583[25] = 0;
   out_8005261171107713583[26] = 0;
   out_8005261171107713583[27] = 0;
   out_8005261171107713583[28] = 0;
   out_8005261171107713583[29] = 0;
   out_8005261171107713583[30] = 1;
   out_8005261171107713583[31] = 0;
   out_8005261171107713583[32] = 0;
   out_8005261171107713583[33] = 0;
   out_8005261171107713583[34] = 0;
   out_8005261171107713583[35] = 0;
   out_8005261171107713583[36] = 0;
   out_8005261171107713583[37] = 0;
   out_8005261171107713583[38] = 0;
   out_8005261171107713583[39] = 0;
   out_8005261171107713583[40] = 1;
   out_8005261171107713583[41] = 0;
   out_8005261171107713583[42] = 0;
   out_8005261171107713583[43] = 0;
   out_8005261171107713583[44] = 0;
   out_8005261171107713583[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8005261171107713583[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8005261171107713583[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8005261171107713583[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8005261171107713583[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8005261171107713583[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8005261171107713583[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8005261171107713583[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8005261171107713583[53] = -9.8100000000000005*dt;
   out_8005261171107713583[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8005261171107713583[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8005261171107713583[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8005261171107713583[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8005261171107713583[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8005261171107713583[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8005261171107713583[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8005261171107713583[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8005261171107713583[62] = 0;
   out_8005261171107713583[63] = 0;
   out_8005261171107713583[64] = 0;
   out_8005261171107713583[65] = 0;
   out_8005261171107713583[66] = 0;
   out_8005261171107713583[67] = 0;
   out_8005261171107713583[68] = 0;
   out_8005261171107713583[69] = 0;
   out_8005261171107713583[70] = 1;
   out_8005261171107713583[71] = 0;
   out_8005261171107713583[72] = 0;
   out_8005261171107713583[73] = 0;
   out_8005261171107713583[74] = 0;
   out_8005261171107713583[75] = 0;
   out_8005261171107713583[76] = 0;
   out_8005261171107713583[77] = 0;
   out_8005261171107713583[78] = 0;
   out_8005261171107713583[79] = 0;
   out_8005261171107713583[80] = 1;
}
void h_25(double *state, double *unused, double *out_3451529468624779566) {
   out_3451529468624779566[0] = state[6];
}
void H_25(double *state, double *unused, double *out_339572919744775885) {
   out_339572919744775885[0] = 0;
   out_339572919744775885[1] = 0;
   out_339572919744775885[2] = 0;
   out_339572919744775885[3] = 0;
   out_339572919744775885[4] = 0;
   out_339572919744775885[5] = 0;
   out_339572919744775885[6] = 1;
   out_339572919744775885[7] = 0;
   out_339572919744775885[8] = 0;
}
void h_24(double *state, double *unused, double *out_3799606392279303524) {
   out_3799606392279303524[0] = state[4];
   out_3799606392279303524[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3383890129749124077) {
   out_3383890129749124077[0] = 0;
   out_3383890129749124077[1] = 0;
   out_3383890129749124077[2] = 0;
   out_3383890129749124077[3] = 0;
   out_3383890129749124077[4] = 1;
   out_3383890129749124077[5] = 0;
   out_3383890129749124077[6] = 0;
   out_3383890129749124077[7] = 0;
   out_3383890129749124077[8] = 0;
   out_3383890129749124077[9] = 0;
   out_3383890129749124077[10] = 0;
   out_3383890129749124077[11] = 0;
   out_3383890129749124077[12] = 0;
   out_3383890129749124077[13] = 0;
   out_3383890129749124077[14] = 1;
   out_3383890129749124077[15] = 0;
   out_3383890129749124077[16] = 0;
   out_3383890129749124077[17] = 0;
}
void h_30(double *state, double *unused, double *out_2912064509677036295) {
   out_2912064509677036295[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6577117421746840870) {
   out_6577117421746840870[0] = 0;
   out_6577117421746840870[1] = 0;
   out_6577117421746840870[2] = 0;
   out_6577117421746840870[3] = 0;
   out_6577117421746840870[4] = 1;
   out_6577117421746840870[5] = 0;
   out_6577117421746840870[6] = 0;
   out_6577117421746840870[7] = 0;
   out_6577117421746840870[8] = 0;
}
void h_26(double *state, double *unused, double *out_2089608757983809350) {
   out_2089608757983809350[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4081076238618832109) {
   out_4081076238618832109[0] = 0;
   out_4081076238618832109[1] = 0;
   out_4081076238618832109[2] = 0;
   out_4081076238618832109[3] = 0;
   out_4081076238618832109[4] = 0;
   out_4081076238618832109[5] = 0;
   out_4081076238618832109[6] = 0;
   out_4081076238618832109[7] = 1;
   out_4081076238618832109[8] = 0;
}
void h_27(double *state, double *unused, double *out_7992451901291706271) {
   out_7992451901291706271[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2643675178688440866) {
   out_2643675178688440866[0] = 0;
   out_2643675178688440866[1] = 0;
   out_2643675178688440866[2] = 0;
   out_2643675178688440866[3] = 1;
   out_2643675178688440866[4] = 0;
   out_2643675178688440866[5] = 0;
   out_2643675178688440866[6] = 0;
   out_2643675178688440866[7] = 0;
   out_2643675178688440866[8] = 0;
}
void h_29(double *state, double *unused, double *out_99512406407182912) {
   out_99512406407182912[0] = state[1];
}
void H_29(double *state, double *unused, double *out_41319477426376229) {
   out_41319477426376229[0] = 0;
   out_41319477426376229[1] = 1;
   out_41319477426376229[2] = 0;
   out_41319477426376229[3] = 0;
   out_41319477426376229[4] = 0;
   out_41319477426376229[5] = 0;
   out_41319477426376229[6] = 0;
   out_41319477426376229[7] = 0;
   out_41319477426376229[8] = 0;
}
void h_28(double *state, double *unused, double *out_4705680922922981175) {
   out_4705680922922981175[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2004949748991702480) {
   out_2004949748991702480[0] = 1;
   out_2004949748991702480[1] = 0;
   out_2004949748991702480[2] = 0;
   out_2004949748991702480[3] = 0;
   out_2004949748991702480[4] = 0;
   out_2004949748991702480[5] = 0;
   out_2004949748991702480[6] = 0;
   out_2004949748991702480[7] = 0;
   out_2004949748991702480[8] = 0;
}
void h_31(double *state, double *unused, double *out_1000579080861491944) {
   out_1000579080861491944[0] = state[8];
}
void H_31(double *state, double *unused, double *out_308926957867815457) {
   out_308926957867815457[0] = 0;
   out_308926957867815457[1] = 0;
   out_308926957867815457[2] = 0;
   out_308926957867815457[3] = 0;
   out_308926957867815457[4] = 0;
   out_308926957867815457[5] = 0;
   out_308926957867815457[6] = 0;
   out_308926957867815457[7] = 0;
   out_308926957867815457[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_90543357710769815) {
  err_fun(nom_x, delta_x, out_90543357710769815);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_17966199294720670) {
  inv_err_fun(nom_x, true_x, out_17966199294720670);
}
void car_H_mod_fun(double *state, double *out_844907361945072597) {
  H_mod_fun(state, out_844907361945072597);
}
void car_f_fun(double *state, double dt, double *out_7814100581081982154) {
  f_fun(state,  dt, out_7814100581081982154);
}
void car_F_fun(double *state, double dt, double *out_8005261171107713583) {
  F_fun(state,  dt, out_8005261171107713583);
}
void car_h_25(double *state, double *unused, double *out_3451529468624779566) {
  h_25(state, unused, out_3451529468624779566);
}
void car_H_25(double *state, double *unused, double *out_339572919744775885) {
  H_25(state, unused, out_339572919744775885);
}
void car_h_24(double *state, double *unused, double *out_3799606392279303524) {
  h_24(state, unused, out_3799606392279303524);
}
void car_H_24(double *state, double *unused, double *out_3383890129749124077) {
  H_24(state, unused, out_3383890129749124077);
}
void car_h_30(double *state, double *unused, double *out_2912064509677036295) {
  h_30(state, unused, out_2912064509677036295);
}
void car_H_30(double *state, double *unused, double *out_6577117421746840870) {
  H_30(state, unused, out_6577117421746840870);
}
void car_h_26(double *state, double *unused, double *out_2089608757983809350) {
  h_26(state, unused, out_2089608757983809350);
}
void car_H_26(double *state, double *unused, double *out_4081076238618832109) {
  H_26(state, unused, out_4081076238618832109);
}
void car_h_27(double *state, double *unused, double *out_7992451901291706271) {
  h_27(state, unused, out_7992451901291706271);
}
void car_H_27(double *state, double *unused, double *out_2643675178688440866) {
  H_27(state, unused, out_2643675178688440866);
}
void car_h_29(double *state, double *unused, double *out_99512406407182912) {
  h_29(state, unused, out_99512406407182912);
}
void car_H_29(double *state, double *unused, double *out_41319477426376229) {
  H_29(state, unused, out_41319477426376229);
}
void car_h_28(double *state, double *unused, double *out_4705680922922981175) {
  h_28(state, unused, out_4705680922922981175);
}
void car_H_28(double *state, double *unused, double *out_2004949748991702480) {
  H_28(state, unused, out_2004949748991702480);
}
void car_h_31(double *state, double *unused, double *out_1000579080861491944) {
  h_31(state, unused, out_1000579080861491944);
}
void car_H_31(double *state, double *unused, double *out_308926957867815457) {
  H_31(state, unused, out_308926957867815457);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
