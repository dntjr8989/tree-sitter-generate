#include "com_tmax_symbol_treesitter.h"
#include "com_tmax_symbol_treesitter_model_Language.h"
#include <jni.h>
#include <string.h>
#include <tree_sitter/api.h>


JNIEXPORT jlong JNICALL Java_com_tmax_symbol_treesitter_model_Language_c(
  JNIEnv* env, jclass self) {
#ifdef TS_LANGUAGE_C
  return (jlong)tree_sitter_c();
#else
  return (jlong)com_tmax_symbol_treesitter_model_Language_INVALID;
#endif
}


JNIEXPORT jlong JNICALL Java_com_tmax_symbol_treesitter_model_Language_java(
  JNIEnv* env, jclass self) {
#ifdef TS_LANGUAGE_JAVA
  return (jlong)tree_sitter_java();
#else
  return (jlong)com_tmax_symbol_treesitter_model_Language_INVALID;
#endif
}

JNIEXPORT jlong JNICALL Java_com_tmax_symbol_treesitter_model_Language_python(
  JNIEnv* env, jclass self) {
#ifdef TS_LANGUAGE_PYTHON
  return (jlong)tree_sitter_python();
#else
  return (jlong)com_tmax_symbol_treesitter_model_Language_INVALID;
#endif
}


JNIEXPORT jint JNICALL Java_com_tmax_symbol_treesitter_model_Language_version(
  JNIEnv* env, jclass self, jlong id) {
  return (jint)ts_language_version((const TSLanguage *)id);
}

JNIEXPORT jint JNICALL Java_com_tmax_symbol_treesitter_model_Language_symbols(
  JNIEnv* env, jclass self, jlong id) {
  return (jint)ts_language_symbol_count((const TSLanguage *)id);
}

JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_Language_symbol(
  JNIEnv* env, jclass self, jlong languageId, jint symbolId) {
  TSSymbol symbol = (TSSymbol)symbolId;
  const TSLanguage* language = (const TSLanguage*)languageId;
  const char* name = ts_language_symbol_name(language, symbol);
  TSSymbolType type = ts_language_symbol_type(language, symbol);
  return env->NewObject(
    _symbolClass,
    _symbolConstructor,
    (jint)symbol,
    (jint)type,
    env->NewStringUTF(name)
  );
}

JNIEXPORT jint JNICALL Java_com_tmax_symbol_treesitter_model_Language_fields(
  JNIEnv* env, jclass self, jlong id) {
  return (jint)ts_language_field_count((const TSLanguage *)id);
}
