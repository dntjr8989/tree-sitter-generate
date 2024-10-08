#include "com_tmax_symbol_treesitter.h"
#include "com_tmax_symbol_treesitter_model_Tree.h"
#include <jni.h>
#include <tree_sitter/api.h>

JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_Tree_delete(
  JNIEnv* env, jobject thisObject) {
  TSTree* tree = (TSTree*)__getPointer(env, thisObject);
  ts_tree_delete(tree);
  __clearPointer(env, thisObject);
}

JNIEXPORT void JNICALL Java_com_tmax_symbol_treesitter_model_Tree_edit(
  JNIEnv* env, jobject thisObject, jobject inputEditObject) {
  jlong tree = __getPointer(env, thisObject);
  if (inputEditObject == NULL) {
    __throwNPE(env, "Input edit must not be null!");
    return;
  }
  TSInputEdit inputEdit = __unmarshalInputEdit(env, inputEditObject);
  ts_tree_edit((TSTree*)tree, &inputEdit);
}

JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_Tree_getRootNode(
  JNIEnv* env, jobject thisObject) {
  jlong tree = __getPointer(env, thisObject);
  TSNode node = ts_tree_root_node((TSTree*)tree);
  jobject nodeObject = __marshalNode(env, node);
  _setNodeTreeField(nodeObject, thisObject);
  return nodeObject;
}

JNIEXPORT jobject JNICALL Java_com_tmax_symbol_treesitter_model_Tree_clone(
  JNIEnv* env, jobject thisObject) {
  jobject languageObject = env->GetObjectField(thisObject, _treeLanguageField);
  jobject sourceObject = env->GetObjectField(thisObject, _treeSourceField);
  jlong tree = __getPointer(env, thisObject);
  jlong copy = (jlong)ts_tree_copy((const TSTree*)tree);
  return env->NewObject(_treeClass, _treeConstructor, copy, languageObject, sourceObject);
}
