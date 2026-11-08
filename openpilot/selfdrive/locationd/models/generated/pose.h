#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6057666269876821352);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5874123099794783116);
void pose_H_mod_fun(double *state, double *out_3022146375872577553);
void pose_f_fun(double *state, double dt, double *out_5302456385426177188);
void pose_F_fun(double *state, double dt, double *out_1927640881032223950);
void pose_h_4(double *state, double *unused, double *out_61275514649772420);
void pose_H_4(double *state, double *unused, double *out_8870228182624536274);
void pose_h_10(double *state, double *unused, double *out_3113540078229992172);
void pose_H_10(double *state, double *unused, double *out_8133353293446248542);
void pose_h_13(double *state, double *unused, double *out_9190534258819938312);
void pose_H_13(double *state, double *unused, double *out_5657954357292203473);
void pose_h_14(double *state, double *unused, double *out_4475366908773028757);
void pose_H_14(double *state, double *unused, double *out_9141399364440131743);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}