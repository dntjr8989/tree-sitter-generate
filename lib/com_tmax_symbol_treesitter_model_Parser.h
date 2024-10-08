/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class ch_usi_si_seart_treesitter_Parser */

#ifndef _Included_com_tmax_symbol_treesitter_model_Parser
#define _Included_com_tmax_symbol_treesitter_model_Parser
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ch_usi_si_seart_treesitter_Parser
 * Method:    getLanguageVersion
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_tmax_symbol_treesitter_model_Parser_getLanguageVersion
  (JNIEnv *, jclass);

/*
 * Class:     ch_usi_si_seart_treesitter_Parser
 * Method:    getMinimumCompatibleLanguageVersion
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_tmax_symbol_treesitter_model_Parser_getMinimumCompatibleLanguageVersion
  (JNIEnv *, jclass);

/*
 * Class:     ch_usi_si_seart_treesitter_Parser
 * Method:    delete
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_Parser_delete
  (JNIEnv *, jobject);

/*
 * Class:     ch_usi_si_seart_treesitter_Parser
 * Method:    setLanguage
 * Signature: (Lch/usi/si/seart/treesitter/Parser;Lch/usi/si/seart/treesitter/Language;)V
 */
JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_Parser_setLanguage
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     ch_usi_si_seart_treesitter_Parser
 * Method:    getTimeout
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_tmax_symbol_treesitter_model_Parser_getTimeout
  (JNIEnv *, jobject);

/*
 * Class:     ch_usi_si_seart_treesitter_Parser
 * Method:    setTimeout
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_Parser_setTimeout
  (JNIEnv *, jobject, jlong);

/*
 * Class:     ch_usi_si_seart_treesitter_Parser
 * Method:    parse
 * Signature: (Ljava/lang/String;[BILch/usi/si/seart/treesitter/Tree;)Lch/usi/si/seart/treesitter/Tree;
 */
JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_Parser_parse
  (JNIEnv *, jobject, jstring, jbyteArray, jint, jobject);

#ifdef __cplusplus
}
#endif
#endif
