#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_90543357710769815);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_17966199294720670);
void car_H_mod_fun(double *state, double *out_844907361945072597);
void car_f_fun(double *state, double dt, double *out_7814100581081982154);
void car_F_fun(double *state, double dt, double *out_8005261171107713583);
void car_h_25(double *state, double *unused, double *out_3451529468624779566);
void car_H_25(double *state, double *unused, double *out_339572919744775885);
void car_h_24(double *state, double *unused, double *out_3799606392279303524);
void car_H_24(double *state, double *unused, double *out_3383890129749124077);
void car_h_30(double *state, double *unused, double *out_2912064509677036295);
void car_H_30(double *state, double *unused, double *out_6577117421746840870);
void car_h_26(double *state, double *unused, double *out_2089608757983809350);
void car_H_26(double *state, double *unused, double *out_4081076238618832109);
void car_h_27(double *state, double *unused, double *out_7992451901291706271);
void car_H_27(double *state, double *unused, double *out_2643675178688440866);
void car_h_29(double *state, double *unused, double *out_99512406407182912);
void car_H_29(double *state, double *unused, double *out_41319477426376229);
void car_h_28(double *state, double *unused, double *out_4705680922922981175);
void car_H_28(double *state, double *unused, double *out_2004949748991702480);
void car_h_31(double *state, double *unused, double *out_1000579080861491944);
void car_H_31(double *state, double *unused, double *out_308926957867815457);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}