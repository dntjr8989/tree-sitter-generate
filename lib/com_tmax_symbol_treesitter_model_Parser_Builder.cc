#include "com_tmax_symbol_treesitter.h"
#include "com_tmax_symbol_treesitter_model_Parser_Builder.h"
#include <jni.h>
#include <tree_sitter/api.h>

JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_Parser_00024Builder_build(
  JNIEnv* env, jclass thisClass, jobject languageObject, jlong timeout) {
  TSParser* parser = ts_parser_new();
  const TSLanguage* language = __unmarshalLanguage(env, languageObject);
  bool succeeded = ts_parser_set_language(parser, language);
  if (!succeeded) {
    ts_parser_delete(parser);
    __throwILE(env, languageObject);
    return NULL;
  }
  if (timeout < 0) {
    ts_parser_delete(parser);
    __throwIAE(env, "Timeout can not be negative!");
    return NULL;
  } else if (timeout > 0) {
    ts_parser_set_timeout_micros(parser, (uint64_t)timeout);
  }
  return env->NewObject(
    _parserClass,
    _parserConstructor,
    (jlong)parser,
    languageObject
  );
}
