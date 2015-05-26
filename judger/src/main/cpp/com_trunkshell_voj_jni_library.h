#include <jni.h>
/* Header for class com_trunkshell_voj_jni_library */

#ifndef _Included_com_trunkshell_voj_jni_library
#define _Included_com_trunkshell_voj_jni_library
#ifdef __cplusplus
extern "C" {
#endif

/**
 * 获取Java中String的值.
 * @param  jniEnv - JNI 运行环境引用
 * @param  jStr   - 待获取值的Java字符串
 * @return Java字符串的值
 */
const char* getStringValue(JNIEnv* JniEnv, jstring jStr) {
	if ( jStr == nullptr || jStr == NULL ) {
		return "";
	}
	const char* str = JniEnv->GetStringUTFChars(jStr, 0);
	return str;
}

/**
 * 抛出异常至Java运行环境.
 * @param  jniEnv  - JNI 运行环境引用
 * @param  message - 异常信息
 * @return Java.lang.Error对象
 */
jint throwException(JNIEnv* jniEnv, char* message) {
	jclass exClass;
    char* className = "java/lang/Error";
    exClass = jniEnv->FindClass(className);

    return jniEnv->ThrowNew(exClass, message);
}

#ifdef __cplusplus
}
#endif
#endif
