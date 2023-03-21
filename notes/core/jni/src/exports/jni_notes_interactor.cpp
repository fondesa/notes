#include <jni.h>
#include "mapping/jvm_class.hpp"
#include "mapping/to_jvm.hpp"
#include "mem/jvm_pointer.hpp"
#include "notes/notes_interactor_factory.hpp"

extern "C" {
JNIEXPORT jlong JNICALL
Java_com_fondesa_notes_core_notes_internal_NativeNotesInteractor_nativeAddress(JNIEnv *env, jobject /* this */) {
  auto interactor = NotesInteractorFactory::create();
  return Jni::JvmPointer<NotesInteractor>::create(interactor)->toAddress();
}

JNIEXPORT jobject JNICALL Java_com_fondesa_notes_core_notes_internal_NativeNotesInteractor_getDraft(JNIEnv *env,
                                                                                                    jobject /* this */,
                                                                                                    jlong address) {
  auto repository = Jni::JvmPointer<NotesInteractor>::fromAddress(address);
  auto draft = repository->getDraft();
  if (!draft) return nullptr;

  auto jvmClass = Jni::JvmClass(env, "com/fondesa/notes/core/notes/Draft");
  auto ctor = jvmClass.constructor("(Ljava/lang/String;Ljava/lang/String;)V");
  auto mapper = Jni::ToJvm(env);
  auto title = mapper.toString(draft->getTitle());
  auto description = mapper.toString(draft->getDescription());
  return env->NewObject(jvmClass.get(), ctor, title, description);
}

JNIEXPORT void JNICALL Java_com_fondesa_notes_core_notes_internal_NativeNotesInteractor_dispose(JNIEnv *env,
                                                                                                jobject /* this */,
                                                                                                jlong address) {
  Jni::JvmPointer<NotesInteractor>::dispose(address);
}
}