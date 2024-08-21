#include "com_tmax_symbol_treesitter.h"
#include "com_tmax_symbol_treesitter_model_Point.h"
#include <jni.h>
#include <tree_sitter/api.h>

JNIEXPORT jint JNICALL Java_com_tmax_symbol_treesitter_model_Point_compareTo(
  JNIEnv* env, jobject thisObject, jobject otherObject) {
  if (otherObject == NULL)
    return __throwNPE(env, "Point must not be null!");
  TSPoint thisPoint = __unmarshalPoint(env, thisObject);
  TSPoint otherPoint = __unmarshalPoint(env, otherObject);
  return (jint)__comparePoints(thisPoint, otherPoint);
}
