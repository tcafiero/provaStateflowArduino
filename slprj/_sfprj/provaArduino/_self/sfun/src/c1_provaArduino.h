#ifndef __c1_provaArduino_h__
#define __c1_provaArduino_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_provaArduinoInstanceStruct
#define typedef_SFc1_provaArduinoInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_main;
  uint8_T c1_tp_uno;
  uint8_T c1_tp_init;
  uint8_T c1_tp_body;
  uint8_T c1_tp_due;
  uint8_T c1_tp_A;
  uint8_T c1_tp_B;
  uint8_T c1_tp_Suspend;
  uint8_T c1_tp_C;
  uint8_T c1_tp_tre;
  uint8_T c1_tp_D;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_provaArduino;
  uint8_T c1_is_c1_provaArduino;
  uint8_T c1_is_uno;
  uint8_T c1_was_uno;
  uint8_T c1_is_active_uno;
  uint8_T c1_is_due;
  uint8_T c1_was_due;
  uint8_T c1_is_active_due;
  uint8_T c1_is_tre;
  uint8_T c1_was_tre;
  uint8_T c1_is_active_tre;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_provaArduinoInstanceStruct;

#endif                                 /*typedef_SFc1_provaArduinoInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_provaArduino_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_provaArduino_get_check_sum(mxArray *plhs[]);
extern void c1_provaArduino_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
