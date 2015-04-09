/* Include files */

#include <stddef.h>
#include "blas.h"
#include "provaArduino_sfun.h"
#include "c1_provaArduino.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "provaArduino_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_click                 (0)
#define c1_event_ON                    (1)
#define c1_event_OFF                   (2)
#define c1_event_YellowButton          (3)
#define c1_event_RedButton             (4)
#define c1_event_GreenON               (5)
#define c1_event_GreenOFF              (6)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_Suspend                  ((uint8_T)1U)
#define c1_IN_main                     ((uint8_T)2U)
#define c1_IN_body                     ((uint8_T)1U)
#define c1_IN_init                     ((uint8_T)2U)
#define c1_IN_A                        ((uint8_T)1U)
#define c1_IN_B                        ((uint8_T)2U)
#define c1_IN_C                        ((uint8_T)1U)
#define c1_IN_D                        ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void initialize_params_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void enable_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void disable_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_provaArduino
  (SFc1_provaArduinoInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_provaArduino
  (SFc1_provaArduinoInstanceStruct *chartInstance);
static void set_sim_state_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_provaArduino
  (SFc1_provaArduinoInstanceStruct *chartInstance);
static void finalize_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void sf_c1_provaArduino(SFc1_provaArduinoInstanceStruct *chartInstance);
static void c1_c1_provaArduino(SFc1_provaArduinoInstanceStruct *chartInstance);
static void initSimStructsc1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void registerMessagesc1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void c1_enter_internal_main(SFc1_provaArduinoInstanceStruct
  *chartInstance);
static void c1_main(SFc1_provaArduinoInstanceStruct *chartInstance);
static void c1_due(SFc1_provaArduinoInstanceStruct *chartInstance);
static void c1_tre(SFc1_provaArduinoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int8_T c1_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_b_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_c_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_main, const char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_e_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_RedLed, const char_T *c1_identifier);
static boolean_T c1_f_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_h_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_provaArduinoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
  boolean_T *c1_RedLed;
  boolean_T *c1_GreenLed;
  c1_GreenLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_RedLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_Suspend = 0U;
  chartInstance->c1_tp_main = 0U;
  chartInstance->c1_is_active_due = 0U;
  chartInstance->c1_is_due = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_was_due = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_due = 0U;
  chartInstance->c1_tp_A = 0U;
  chartInstance->c1_tp_B = 0U;
  chartInstance->c1_is_active_tre = 0U;
  chartInstance->c1_is_tre = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_was_tre = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_tre = 0U;
  chartInstance->c1_tp_C = 0U;
  chartInstance->c1_tp_D = 0U;
  chartInstance->c1_is_active_uno = 0U;
  chartInstance->c1_is_uno = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_was_uno = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_uno = 0U;
  chartInstance->c1_tp_body = 0U;
  chartInstance->c1_tp_init = 0U;
  chartInstance->c1_is_active_c1_provaArduino = 0U;
  chartInstance->c1_is_c1_provaArduino = c1_IN_NO_ACTIVE_CHILD;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_RedLed = FALSE;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c1_GreenLed = FALSE;
  }
}

static void initialize_params_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
}

static void enable_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_provaArduino
  (SFc1_provaArduinoInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_provaArduino == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_provaArduino == c1_IN_main) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_uno == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_uno == c1_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_uno == c1_IN_body) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_due == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_due == c1_IN_A) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_due == c1_IN_B) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_provaArduino == c1_IN_Suspend) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_tre == c1_IN_C) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_tre == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_tre == c1_IN_D) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_provaArduino
  (SFc1_provaArduinoInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  boolean_T c1_u;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_b_hoistedGlobal;
  boolean_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  uint8_T c1_g_hoistedGlobal;
  uint8_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  uint8_T c1_h_hoistedGlobal;
  uint8_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  uint8_T c1_i_hoistedGlobal;
  uint8_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  uint8_T c1_j_hoistedGlobal;
  uint8_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  uint8_T c1_k_hoistedGlobal;
  uint8_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  uint8_T c1_l_hoistedGlobal;
  uint8_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  uint8_T c1_m_hoistedGlobal;
  uint8_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  boolean_T *c1_GreenLed;
  boolean_T *c1_RedLed;
  c1_GreenLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_RedLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(13), FALSE);
  c1_hoistedGlobal = *c1_GreenLed;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_RedLed;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_provaArduino;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_uno;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_is_active_due;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_active_tre;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = chartInstance->c1_is_c1_provaArduino;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_is_uno;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = chartInstance->c1_is_due;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_is_tre;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = chartInstance->c1_was_uno;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = chartInstance->c1_was_due;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = chartInstance->c1_was_tre;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_GreenLed;
  boolean_T *c1_RedLed;
  c1_GreenLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_RedLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_GreenLed = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "GreenLed");
  *c1_RedLed = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "RedLed");
  chartInstance->c1_is_active_c1_provaArduino = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_provaArduino");
  chartInstance->c1_is_active_uno = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 3)), "is_active_uno");
  chartInstance->c1_is_active_due = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 4)), "is_active_due");
  chartInstance->c1_is_active_tre = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 5)), "is_active_tre");
  chartInstance->c1_is_c1_provaArduino = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 6)), "is_c1_provaArduino");
  chartInstance->c1_is_uno = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 7)), "is_uno");
  chartInstance->c1_is_due = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 8)), "is_due");
  chartInstance->c1_is_tre = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 9)), "is_tre");
  chartInstance->c1_was_uno = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 10)), "was_uno");
  chartInstance->c1_was_due = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "was_due");
  chartInstance->c1_was_tre = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 12)), "was_tre");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 13)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_provaArduino(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_provaArduino
  (SFc1_provaArduinoInstanceStruct *chartInstance)
{
  if ((int16_T)chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_provaArduino == c1_IN_Suspend) {
      chartInstance->c1_tp_Suspend = 1U;
    } else {
      chartInstance->c1_tp_Suspend = 0U;
    }

    if (chartInstance->c1_is_c1_provaArduino == c1_IN_main) {
      chartInstance->c1_tp_main = 1U;
    } else {
      chartInstance->c1_tp_main = 0U;
    }

    if (chartInstance->c1_is_active_due == 1U) {
      chartInstance->c1_tp_due = 1U;
    } else {
      chartInstance->c1_tp_due = 0U;
    }

    if (chartInstance->c1_is_due == c1_IN_A) {
      chartInstance->c1_tp_A = 1U;
      chartInstance->c1_was_due = c1_IN_A;
    } else {
      chartInstance->c1_tp_A = 0U;
    }

    if (chartInstance->c1_is_due == c1_IN_B) {
      chartInstance->c1_tp_B = 1U;
      chartInstance->c1_was_due = c1_IN_B;
    } else {
      chartInstance->c1_tp_B = 0U;
    }

    if (chartInstance->c1_is_active_uno == 1U) {
      chartInstance->c1_tp_uno = 1U;
    } else {
      chartInstance->c1_tp_uno = 0U;
    }

    if (chartInstance->c1_is_uno == c1_IN_body) {
      chartInstance->c1_tp_body = 1U;
      chartInstance->c1_was_uno = c1_IN_body;
    } else {
      chartInstance->c1_tp_body = 0U;
    }

    if (chartInstance->c1_is_uno == c1_IN_init) {
      chartInstance->c1_tp_init = 1U;
      chartInstance->c1_was_uno = c1_IN_init;
    } else {
      chartInstance->c1_tp_init = 0U;
    }

    if (chartInstance->c1_is_active_tre == 1U) {
      chartInstance->c1_tp_tre = 1U;
    } else {
      chartInstance->c1_tp_tre = 0U;
    }

    if (chartInstance->c1_is_tre == c1_IN_C) {
      chartInstance->c1_tp_C = 1U;
      chartInstance->c1_was_tre = c1_IN_C;
    } else {
      chartInstance->c1_tp_C = 0U;
    }

    if (chartInstance->c1_is_tre == c1_IN_D) {
      chartInstance->c1_tp_D = 1U;
      chartInstance->c1_was_tre = c1_IN_D;
    } else {
      chartInstance->c1_tp_D = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_provaArduino(SFc1_provaArduinoInstanceStruct *chartInstance)
{
  int8_T *c1_click;
  int8_T *c1_YellowButton;
  int8_T *c1_RedButton;
  c1_RedButton = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 0) + 2);
  c1_YellowButton = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 0) +
    1);
  c1_click = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 0) + 0);
  c1_set_sim_state_side_effects_c1_provaArduino(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if ((int16_T)*c1_click == 1) {
    chartInstance->c1_sfEvent = c1_event_click;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_click,
                 chartInstance->c1_sfEvent);
    c1_c1_provaArduino(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_click,
                 chartInstance->c1_sfEvent);
  }

  if ((int16_T)*c1_YellowButton == 1) {
    chartInstance->c1_sfEvent = c1_event_YellowButton;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_YellowButton,
                 chartInstance->c1_sfEvent);
    c1_c1_provaArduino(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_YellowButton,
                 chartInstance->c1_sfEvent);
  }

  if ((int16_T)*c1_RedButton == 1) {
    chartInstance->c1_sfEvent = c1_event_RedButton;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_RedButton,
                 chartInstance->c1_sfEvent);
    c1_c1_provaArduino(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_RedButton,
                 chartInstance->c1_sfEvent);
  }

  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_provaArduinoMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_provaArduino(SFc1_provaArduinoInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_provaArduino == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_provaArduino = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_provaArduino = c1_IN_main;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_main = 1U;
    c1_enter_internal_main(chartInstance);
  } else {
    switch (chartInstance->c1_is_c1_provaArduino) {
     case c1_IN_Suspend:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c1_sfEvent);
      c1_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0,
                  chartInstance->c1_sfEvent == c1_event_RedButton != 0U,
                  chartInstance->c1_sfEvent)) != 0);
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Suspend = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_provaArduino = c1_IN_main;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_main = 1U;
        c1_enter_internal_main(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_main:
      CV_CHART_EVAL(0, 0, 2);
      c1_main(chartInstance);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c1_is_c1_provaArduino = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_provaArduino(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
}

static void c1_enter_internal_main(SFc1_provaArduinoInstanceStruct
  *chartInstance)
{
  boolean_T *c1_RedLed;
  boolean_T *c1_GreenLed;
  c1_GreenLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_RedLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_is_active_due = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_due = 1U;
  switch (chartInstance->c1_was_due) {
   case c1_IN_A:
    CV_STATE_EVAL(2, 2, 1);
    if (chartInstance->c1_is_due == c1_IN_A) {
    } else {
      chartInstance->c1_is_due = c1_IN_A;
      chartInstance->c1_was_due = c1_IN_A;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_A = 1U;
      *c1_RedLed = TRUE;
    }
    break;

   case c1_IN_B:
    CV_STATE_EVAL(2, 2, 2);
    if (chartInstance->c1_is_due == c1_IN_B) {
    } else {
      chartInstance->c1_is_due = c1_IN_B;
      chartInstance->c1_was_due = c1_IN_B;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_B = 1U;
      *c1_RedLed = FALSE;
    }
    break;

   default:
    CV_STATE_EVAL(2, 2, 0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_due == c1_IN_B) {
    } else {
      chartInstance->c1_is_due = c1_IN_B;
      chartInstance->c1_was_due = c1_IN_B;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_B = 1U;
      *c1_RedLed = FALSE;
    }
    break;
  }

  chartInstance->c1_is_active_uno = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_uno = 1U;
  switch (chartInstance->c1_was_uno) {
   case c1_IN_body:
    CV_STATE_EVAL(8, 2, 1);
    chartInstance->c1_is_uno = c1_IN_body;
    chartInstance->c1_was_uno = c1_IN_body;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_body = 1U;
    break;

   case c1_IN_init:
    CV_STATE_EVAL(8, 2, 2);
    chartInstance->c1_is_uno = c1_IN_init;
    chartInstance->c1_was_uno = c1_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_init = 1U;
    break;

   default:
    CV_STATE_EVAL(8, 2, 0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_uno = c1_IN_init;
    chartInstance->c1_was_uno = c1_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_init = 1U;
    break;
  }

  chartInstance->c1_is_active_tre = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_tre = 1U;
  switch (chartInstance->c1_was_tre) {
   case c1_IN_C:
    CV_STATE_EVAL(5, 2, 1);
    if (chartInstance->c1_is_tre == c1_IN_C) {
    } else {
      chartInstance->c1_is_tre = c1_IN_C;
      chartInstance->c1_was_tre = c1_IN_C;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_C = 1U;
      *c1_GreenLed = TRUE;
    }
    break;

   case c1_IN_D:
    CV_STATE_EVAL(5, 2, 2);
    if (chartInstance->c1_is_tre == c1_IN_D) {
    } else {
      chartInstance->c1_is_tre = c1_IN_D;
      chartInstance->c1_was_tre = c1_IN_D;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_D = 1U;
      *c1_GreenLed = FALSE;
    }
    break;

   default:
    CV_STATE_EVAL(5, 2, 0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_tre == c1_IN_D) {
    } else {
      chartInstance->c1_is_tre = c1_IN_D;
      chartInstance->c1_was_tre = c1_IN_D;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_D = 1U;
      *c1_GreenLed = FALSE;
    }
    break;
  }
}

static void c1_main(SFc1_provaArduinoInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  int32_T c1_previousEvent;
  boolean_T c1_c_out;
  int32_T c1_b_previousEvent;
  boolean_T *c1_RedLed;
  boolean_T *c1_GreenLed;
  c1_GreenLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_RedLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0,
              chartInstance->c1_sfEvent == c1_event_RedButton != 0U,
              chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_tre) {
     case c1_IN_C:
      CV_STATE_EVAL(5, 1, 1);
      chartInstance->c1_tp_C = 0U;
      chartInstance->c1_is_tre = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_D:
      CV_STATE_EVAL(5, 1, 2);
      chartInstance->c1_tp_D = 0U;
      chartInstance->c1_is_tre = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(5, 1, 0);
      chartInstance->c1_is_tre = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      break;
    }

    chartInstance->c1_tp_tre = 0U;
    chartInstance->c1_is_active_tre = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_uno) {
     case c1_IN_body:
      CV_STATE_EVAL(8, 1, 1);
      chartInstance->c1_tp_body = 0U;
      chartInstance->c1_is_uno = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_init:
      CV_STATE_EVAL(8, 1, 2);
      chartInstance->c1_tp_init = 0U;
      chartInstance->c1_is_uno = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(8, 1, 0);
      chartInstance->c1_is_uno = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      break;
    }

    chartInstance->c1_tp_uno = 0U;
    chartInstance->c1_is_active_uno = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_due) {
     case c1_IN_A:
      CV_STATE_EVAL(2, 1, 1);
      chartInstance->c1_tp_A = 0U;
      chartInstance->c1_is_due = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_B:
      CV_STATE_EVAL(2, 1, 2);
      chartInstance->c1_tp_B = 0U;
      chartInstance->c1_is_due = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(2, 1, 0);
      chartInstance->c1_is_due = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      break;
    }

    chartInstance->c1_tp_due = 0U;
    chartInstance->c1_is_active_due = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_main = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_provaArduino = c1_IN_Suspend;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_Suspend = 1U;
    *c1_RedLed = FALSE;
    *c1_GreenLed = FALSE;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_is_active_due == 0U) {
    } else {
      c1_due(chartInstance);
    }

    if (chartInstance->c1_is_active_uno == 0U) {
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c1_sfEvent);
      switch (chartInstance->c1_is_uno) {
       case c1_IN_body:
        CV_STATE_EVAL(8, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c1_sfEvent);
        c1_b_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
          chartInstance->c1_sfEvent == c1_event_click != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_body = 0U;
          chartInstance->c1_is_uno = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 2U,
                       chartInstance->c1_sfEvent);
          c1_previousEvent = chartInstance->c1_sfEvent;
          chartInstance->c1_sfEvent = c1_event_OFF;
          _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_OFF,
                       chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_active_due == 0U) {
          } else {
            c1_due(chartInstance);
          }

          _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_OFF,
                       chartInstance->c1_sfEvent);
          chartInstance->c1_sfEvent = c1_previousEvent;
          chartInstance->c1_is_uno = c1_IN_init;
          chartInstance->c1_was_uno = c1_IN_init;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_init = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                       chartInstance->c1_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
        break;

       case c1_IN_init:
        CV_STATE_EVAL(8, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                     chartInstance->c1_sfEvent);
        c1_c_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
          chartInstance->c1_sfEvent == c1_event_click != 0U,
          chartInstance->c1_sfEvent)) != 0);
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_init = 0U;
          chartInstance->c1_is_uno = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 1U,
                       chartInstance->c1_sfEvent);
          c1_b_previousEvent = chartInstance->c1_sfEvent;
          chartInstance->c1_sfEvent = c1_event_ON;
          _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_ON,
                       chartInstance->c1_sfEvent);
          if (chartInstance->c1_is_active_due == 0U) {
          } else {
            c1_due(chartInstance);
          }

          _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_ON,
                       chartInstance->c1_sfEvent);
          chartInstance->c1_sfEvent = c1_b_previousEvent;
          chartInstance->c1_is_uno = c1_IN_body;
          chartInstance->c1_was_uno = c1_IN_body;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_body = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                       chartInstance->c1_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
        break;

       default:
        CV_STATE_EVAL(8, 0, 0);
        chartInstance->c1_is_uno = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
    }

    if (chartInstance->c1_is_active_tre == 0U) {
    } else {
      c1_tre(chartInstance);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
}

static void c1_due(SFc1_provaArduinoInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  int32_T c1_previousEvent;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  boolean_T c1_f_out;
  int32_T c1_b_previousEvent;
  boolean_T *c1_RedLed;
  c1_RedLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_due) {
   case c1_IN_A:
    CV_STATE_EVAL(2, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c1_sfEvent);
    c1_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
                chartInstance->c1_sfEvent == c1_event_OFF != 0U,
                chartInstance->c1_sfEvent)) != 0);
    if (c1_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 3;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        c1_b_out = (chartInstance->c1_sfEvent == c1_event_YellowButton);
        if (c1_b_out) {
          transitionList[numTransitions] = 5;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_A = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_due = c1_IN_B;
      chartInstance->c1_was_due = c1_IN_B;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_B = 1U;
      *c1_RedLed = FALSE;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c1_sfEvent);
      c1_c_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
        chartInstance->c1_sfEvent == c1_event_YellowButton != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_A = 0U;
        chartInstance->c1_is_due = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 5U,
                     chartInstance->c1_sfEvent);
        c1_previousEvent = chartInstance->c1_sfEvent;
        chartInstance->c1_sfEvent = c1_event_GreenON;
        _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GreenON,
                     chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_active_tre == 0U) {
        } else {
          c1_tre(chartInstance);
        }

        _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GreenON,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_sfEvent = c1_previousEvent;
        chartInstance->c1_is_due = c1_IN_A;
        chartInstance->c1_was_due = c1_IN_A;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_A = 1U;
        *c1_RedLed = TRUE;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c1_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_B:
    CV_STATE_EVAL(2, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c1_sfEvent);
    c1_d_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
      chartInstance->c1_sfEvent == c1_event_ON != 0U, chartInstance->c1_sfEvent))
                != 0);
    if (c1_d_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 4;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        c1_e_out = (chartInstance->c1_sfEvent == c1_event_YellowButton);
        if (c1_e_out) {
          transitionList[numTransitions] = 6;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_B = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_due = c1_IN_A;
      chartInstance->c1_was_due = c1_IN_A;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_A = 1U;
      *c1_RedLed = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c1_sfEvent);
      c1_f_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0,
        chartInstance->c1_sfEvent == c1_event_YellowButton != 0U,
        chartInstance->c1_sfEvent)) != 0);
      if (c1_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_B = 0U;
        chartInstance->c1_is_due = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 6U,
                     chartInstance->c1_sfEvent);
        c1_b_previousEvent = chartInstance->c1_sfEvent;
        chartInstance->c1_sfEvent = c1_event_GreenOFF;
        _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_GreenOFF,
                     chartInstance->c1_sfEvent);
        if (chartInstance->c1_is_active_tre == 0U) {
        } else {
          c1_tre(chartInstance);
        }

        _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_GreenOFF,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_sfEvent = c1_b_previousEvent;
        chartInstance->c1_is_due = c1_IN_B;
        chartInstance->c1_was_due = c1_IN_B;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_B = 1U;
        *c1_RedLed = FALSE;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c1_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(2, 0, 0);
    chartInstance->c1_is_due = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
}

static void c1_tre(SFc1_provaArduinoInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T *c1_GreenLed;
  c1_GreenLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_tre) {
   case c1_IN_C:
    CV_STATE_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c1_sfEvent);
    c1_out = (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0,
                chartInstance->c1_sfEvent == c1_event_GreenOFF != 0U,
                chartInstance->c1_sfEvent)) != 0);
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_C = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_tre = c1_IN_D;
      chartInstance->c1_was_tre = c1_IN_D;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_D = 1U;
      *c1_GreenLed = FALSE;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_D:
    CV_STATE_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c1_sfEvent);
    c1_b_out = (CV_TRANSITION_EVAL(13U, (int32_T)_SFD_CCP_CALL(13U, 0,
      chartInstance->c1_sfEvent == c1_event_GreenON != 0U,
      chartInstance->c1_sfEvent)) != 0);
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_D = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_tre = c1_IN_C;
      chartInstance->c1_was_tre = c1_IN_C;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_C = 1U;
      *c1_GreenLed = TRUE;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(5, 0, 0);
    chartInstance->c1_is_tre = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_provaArduino_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int8_T c1_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_click;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_click = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_click), &c1_thisId);
  sf_mex_destroy(&c1_click);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_b_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i1, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_main, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_main),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_main);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_main;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_b_tp_main = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_main),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_main);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_e_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_RedLed, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_RedLed), &c1_thisId);
  sf_mex_destroy(&c1_RedLed);
  return c1_y;
}

static boolean_T c1_f_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_RedLed;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)chartInstanceVoid;
  c1_RedLed = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_RedLed), &c1_thisId);
  sf_mex_destroy(&c1_RedLed);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_h_emlrt_marshallIn(SFc1_provaArduinoInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_provaArduinoInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_provaArduino_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1544291405U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4024105634U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(855994861U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2935603359U);
}

mxArray *sf_c1_provaArduino_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nzjH0xo8mk9Wfn8pV3OJBF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_provaArduino_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_provaArduino(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[49],T\"GreenLed\",},{M[1],M[7],T\"RedLed\",},{M[8],M[0],T\"is_active_c1_provaArduino\",},{M[8],M[10],T\"is_active_uno\",},{M[8],M[11],T\"is_active_due\",},{M[8],M[67],T\"is_active_tre\",},{M[9],M[0],T\"is_c1_provaArduino\",},{M[9],M[10],T\"is_uno\",},{M[9],M[11],T\"is_due\",},{M[9],M[67],T\"is_tre\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[10],M[10],T\"was_uno\",},{M[10],M[11],T\"was_due\",},{M[10],M[67],T\"was_tre\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_provaArduino_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_provaArduinoInstanceStruct *chartInstance;
    chartInstance = (SFc1_provaArduinoInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _provaArduinoMachineNumber_,
           1,
           11,
           14,
           2,
           7,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_provaArduinoMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_provaArduinoMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _provaArduinoMachineNumber_,
            chartInstance->chartNumber,
            7,
            7,
            7);
          _SFD_SET_DATA_PROPS(0,2,0,1,"RedLed");
          _SFD_SET_DATA_PROPS(1,2,0,1,"GreenLed");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_EVENT_SCOPE(1,0);
          _SFD_EVENT_SCOPE(2,0);
          _SFD_EVENT_SCOPE(3,1);
          _SFD_EVENT_SCOPE(4,1);
          _SFD_EVENT_SCOPE(5,0);
          _SFD_EVENT_SCOPE(6,0);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,1,0);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,1,0);
          _SFD_STATE_INFO(4,1,0);
          _SFD_STATE_INFO(5,0,1);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,8);
          _SFD_ST_SUBSTATE_INDEX(1,2,5);
          _SFD_ST_SUBSTATE_COUNT(2,2);
          _SFD_ST_SUBSTATE_INDEX(2,0,3);
          _SFD_ST_SUBSTATE_INDEX(2,1,4);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(8,2);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(5,2);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,3,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,2,1,1,1,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,2,1,1,1,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,2,1,1,1,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 2 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(13,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 3 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 2 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);

        {
          boolean_T *c1_RedLed;
          boolean_T *c1_GreenLed;
          c1_GreenLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_RedLed = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_RedLed);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_GreenLed);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _provaArduinoMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tKcCN47ruhDvTbXJHLjaQE";
}

static void sf_opaque_initialize_c1_provaArduino(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_provaArduinoInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_provaArduino((SFc1_provaArduinoInstanceStruct*)
    chartInstanceVar);
  initialize_c1_provaArduino((SFc1_provaArduinoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_provaArduino(void *chartInstanceVar)
{
  enable_c1_provaArduino((SFc1_provaArduinoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_provaArduino(void *chartInstanceVar)
{
  disable_c1_provaArduino((SFc1_provaArduinoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_provaArduino(void *chartInstanceVar)
{
  sf_c1_provaArduino((SFc1_provaArduinoInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_provaArduino(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_provaArduino
    ((SFc1_provaArduinoInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_provaArduino();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_provaArduino(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_provaArduino();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_provaArduino((SFc1_provaArduinoInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_provaArduino(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_provaArduino(S);
}

static void sf_opaque_set_sim_state_c1_provaArduino(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c1_provaArduino(S, st);
}

static void sf_opaque_terminate_c1_provaArduino(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_provaArduinoInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_provaArduino_optimization_info();
    }

    finalize_c1_provaArduino((SFc1_provaArduinoInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_provaArduino((SFc1_provaArduinoInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_provaArduino(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_provaArduino((SFc1_provaArduinoInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_provaArduino(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_provaArduino_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1331292129U));
  ssSetChecksum1(S,(2823796647U));
  ssSetChecksum2(S,(3924149679U));
  ssSetChecksum3(S,(2441644981U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_provaArduino(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_provaArduino(SimStruct *S)
{
  SFc1_provaArduinoInstanceStruct *chartInstance;
  chartInstance = (SFc1_provaArduinoInstanceStruct *)utMalloc(sizeof
    (SFc1_provaArduinoInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_provaArduinoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_provaArduino;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_provaArduino;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_provaArduino;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_provaArduino;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_provaArduino;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_provaArduino;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_provaArduino;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_provaArduino;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_provaArduino;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_provaArduino;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_provaArduino;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_provaArduino_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_provaArduino(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_provaArduino(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_provaArduino(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_provaArduino_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
