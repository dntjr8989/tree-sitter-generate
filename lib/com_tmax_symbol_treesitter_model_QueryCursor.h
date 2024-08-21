/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ch_usi_si_seart_treesitter_QueryCursor */

#ifndef _Included_com_tmax_symbol_treesitter_model_QueryCursor
#define _Included_com_tmax_symbol_treesitter_model_QueryCursor
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ch_usi_si_seart_treesitter_QueryCursor
 * Method:    delete
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_QueryCursor_delete
  (JNIEnv *, jobject);

/*
 * Class:     ch_usi_si_seart_treesitter_QueryCursor
 * Method:    execute
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_QueryCursor_execute
  (JNIEnv *, jobject);

/*
 * Class:     ch_usi_si_seart_treesitter_QueryCursor
 * Method:    setRange
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_QueryCursor_setRange__II
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     ch_usi_si_seart_treesitter_QueryCursor
 * Method:    setRange
 * Signature: (Lch/usi/si/seart/treesitter/Point;Lch/usi/si/seart/treesitter/Point;)V
 */
JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_QueryCursor_setRange__Lcom_tmax_symbol_treesitter_model_Point_2Lcom_tmax_symbol_treesitter_model_Point_2
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     ch_usi_si_seart_treesitter_QueryCursor
 * Method:    nextMatch
 * Signature: ()Lch/usi/si/seart/treesitter/QueryMatch;
 */
JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_QueryCursor_nextMatch
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
