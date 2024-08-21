#include "com_tmax_symbol_treesitter.h"
#include "com_tmax_symbol_treesitter_model_Capture.h"
#include <jni.h>
#include <tree_sitter/api.h>

JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_Capture_disable(
  JNIEnv* env, jobject thisObject) {
  jboolean enabled = env->GetBooleanField(thisObject, _captureEnabledField);
  if (!enabled) return;
  env->SetBooleanField(thisObject, _captureEnabledField, JNI_FALSE);
  jobject queryObject = env->GetObjectField(thisObject, _captureQueryField);
  if (queryObject == NULL) return;
  TSQuery* query = (TSQuery*)__getPointer(env, queryObject);
  if (query == NULL) return;
  jstring name = (jstring)env->GetObjectField(thisObject, _captureNameField);
  uint32_t length = env->GetStringLength(name);
  const char* characters = env->GetStringUTFChars(name, NULL);
  ts_query_disable_capture(query, characters, length);
}
