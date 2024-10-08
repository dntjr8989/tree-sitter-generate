#include "com_tmax_symbol_treesitter.h"
#include "com_tmax_symbol_treesitter_model_TreeCursor.h"
#include <jni.h>
#include <string.h>
#include <tree_sitter/api.h>

JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_delete(
  JNIEnv* env, jobject thisObject) {
  TSTreeCursor* treeCursor = (TSTreeCursor*)__getPointer(env, thisObject);
  ts_tree_cursor_delete(treeCursor);
  __clearPointer(env, thisObject);
}

JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_getCurrentNode(
  JNIEnv* env, jobject thisObject) {
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  TSNode node = ts_tree_cursor_current_node(cursor);
  jobject nodeObject = __marshalNode(env, node);
  jobject treeObject = env->GetObjectField(thisObject, _treeCursorTreeField);
  _setNodeTreeField(nodeObject, treeObject);
  return nodeObject;
}

JNIEXPORT jstring JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_getCurrentFieldName(
  JNIEnv* env, jobject thisObject) {
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  const char* name = ts_tree_cursor_current_field_name(cursor);
  return env->NewStringUTF(name);
}

JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_getCurrentTreeCursorNode(
  JNIEnv* env, jobject thisObject) {
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  const char* name = ts_tree_cursor_current_field_name(cursor);
  TSNode node = ts_tree_cursor_current_node(cursor);
  jobject nodeObject = __marshalNode(env, node);
  jobject treeObject = env->GetObjectField(thisObject, _treeCursorTreeField);
  _setNodeTreeField(nodeObject, treeObject);
  return env->NewObject(
    _treeCursorNodeClass,
    _treeCursorNodeConstructor,
    env->NewStringUTF(name),
    nodeObject
  );
}

JNIEXPORT jboolean JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_gotoFirstChild__(
  JNIEnv* env, jobject thisObject) {
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  bool result = ts_tree_cursor_goto_first_child(cursor);
  env->SetIntField(thisObject, _treeCursorContext0Field, cursor->context[0]);
  env->SetIntField(thisObject, _treeCursorContext1Field, cursor->context[1]);
  return result ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_gotoFirstChild__I(
  JNIEnv* env, jobject thisObject, jint offset) {
  if (offset < 0) {
    __throwIAE(env, "Byte offset must not be negative!");
    return JNI_FALSE;
  }
  // Not sure why I need to multiply by two, again probably because of utf-16
  uint32_t childStart = (uint32_t)offset * 2;
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  TSNode node = ts_tree_cursor_current_node(cursor);
  uint32_t nodeStart = ts_node_start_byte(node);
  if (childStart < nodeStart) {
    __throwBOB(env, offset);
    return JNI_FALSE;
  }
  uint32_t nodeEnd = ts_node_end_byte(node);
  if (childStart > nodeEnd) {
    __throwBOB(env, offset);
    return JNI_FALSE;
  }
  int64_t result = ts_tree_cursor_goto_first_child_for_byte(cursor, childStart);
  env->SetIntField(thisObject, _treeCursorContext0Field, cursor->context[0]);
  env->SetIntField(thisObject, _treeCursorContext1Field, cursor->context[1]);
  return (result > -1) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_gotoFirstChild__Lcom_tmax_symbol_treesitter_model_Point_2(
  JNIEnv* env, jobject thisObject, jobject pointObject) {
  if (pointObject == NULL) {
    __throwNPE(env, "Point must not be null!");
    return JNI_FALSE;
  }
  TSPoint point = __unmarshalPoint(env, pointObject);
  if (point.row < 0 || point.column < 0) {
    __throwIAE(env, "Point can not have negative coordinates!");
    return JNI_FALSE;
  }
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  TSNode node = ts_tree_cursor_current_node(cursor);
  TSPoint lowerBound = ts_node_start_point(node);
  if (__comparePoints(lowerBound, point) == GT) {
    __throwPOB(env, pointObject);
    return JNI_FALSE;
  }
  TSPoint upperBound = ts_node_end_point(node);
  if (__comparePoints(point, upperBound) == GT) {
    __throwPOB(env, pointObject);
    return JNI_FALSE;
  }
  int64_t result = ts_tree_cursor_goto_first_child_for_point(cursor, point);
  env->SetIntField(thisObject, _treeCursorContext0Field, cursor->context[0]);
  env->SetIntField(thisObject, _treeCursorContext1Field, cursor->context[1]);
  return (result > -1) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_gotoNextSibling(
  JNIEnv* env, jobject thisObject) {
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  bool result = ts_tree_cursor_goto_next_sibling(cursor);
  env->SetIntField(thisObject, _treeCursorContext0Field, cursor->context[0]);
  env->SetIntField(thisObject, _treeCursorContext1Field, cursor->context[1]);
  return result ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_gotoParent(
  JNIEnv* env, jobject thisObject) {
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  bool result = ts_tree_cursor_goto_parent(cursor);
  env->SetIntField(thisObject, _treeCursorContext0Field, cursor->context[0]);
  env->SetIntField(thisObject, _treeCursorContext1Field, cursor->context[1]);
  return result ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_gotoNode(
  JNIEnv* env, jobject thisObject, jobject nodeObject) {
  if (nodeObject == NULL) {
    __throwNPE(env, "Node must not be null!");
    return JNI_FALSE;
  }
  TSNode target = __unmarshalNode(env, nodeObject);
  if (ts_node_is_null(target)) {
    __throwIAE(env, "Node must be part of the tree!");
    return JNI_FALSE;
  }
  TSTreeCursor* cursor = (TSTreeCursor*)__getPointer(env, thisObject);
  TSNode source = ts_tree_cursor_current_node(cursor);
  if (ts_node_eq(source, target)) return JNI_FALSE;
  if (source.tree != target.tree) {
    __throwIAE(env, "Node must be part of the tree!");
    return JNI_FALSE;
  }
  ts_tree_cursor_reset(cursor, target);
  env->SetIntField(thisObject, _treeCursorContext0Field, cursor->context[0]);
  env->SetIntField(thisObject, _treeCursorContext1Field, cursor->context[1]);
  return JNI_TRUE;
}

JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_TreeCursor_clone(
  JNIEnv* env, jobject thisObject) {
  jobject treeObject = env->GetObjectField(thisObject, _treeCursorTreeField);
  const TSTreeCursor* cursor = (const TSTreeCursor*)__getPointer(env, thisObject);
  TSTreeCursor copy = ts_tree_cursor_copy(cursor);
  return env->NewObject(
    _treeCursorClass,
    _treeCursorConstructor,
    new TSTreeCursor(copy),
    copy.context[0],
    copy.context[1],
    copy.id,
    treeObject
  );
}
