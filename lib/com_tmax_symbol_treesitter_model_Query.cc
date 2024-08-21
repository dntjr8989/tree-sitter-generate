#include "com_tmax_symbol_treesitter.h"
#include "com_tmax_symbol_treesitter_model_Query.h"
#include <jni.h>
#include <string.h>
#include <tree_sitter/api.h>

JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_Query_delete(
  JNIEnv* env, jobject thisObject) {
  TSQuery* query = (TSQuery*)__getPointer(env, thisObject);
  ts_query_delete(query);
  __clearPointer(env, thisObject);
}
