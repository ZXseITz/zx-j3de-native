#include "ch_zxseitz_j3de_math_Matrix4.h"
#include <cstdlib>

const int SIZE = 16;

JNIEXPORT jboolean JNICALL Java_ch_zxseitz_j3de_math_Matrix4_equalsC
        (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b) {
    auto *pa = env->GetFloatArrayElements(a, nullptr);
    auto *pb = env->GetFloatArrayElements(b, nullptr);

    float *tpa = pa;
    float *tpb = pb;
    auto i = 0;
    auto check = true;
    while (check && i < SIZE) {
        check = abs((*tpa) - (*tpb)) < 0.000001;
        i++; tpa++; tpb++;
    }

    env->ReleaseFloatArrayElements(a, pa, 2);
    env->ReleaseFloatArrayElements(b, pb, 2);
    return check;
}

JNIEXPORT void JNICALL Java_ch_zxseitz_j3de_math_Matrix4_addC
        (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *pa = env->GetFloatArrayElements(a, nullptr);
    auto *pb = env->GetFloatArrayElements(b, nullptr);
    auto *pr = env->GetFloatArrayElements(r, nullptr);

    float *tpa = pa;
    float *tpb = pb;
    float *tpr = pr;
    for (auto i = 0; i < SIZE; i++) {
        *tpr = (*tpa) + (*tpb);
        tpa++; tpb++; tpr++;
    }

    env->ReleaseFloatArrayElements(a, pa, 2);
    env->ReleaseFloatArrayElements(b, pb, 2);
    env->ReleaseFloatArrayElements(r, pr, 0);
}

JNIEXPORT void JNICALL Java_ch_zxseitz_j3de_math_Matrix4_subtractC
        (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *pa = env->GetFloatArrayElements(a, nullptr);
    auto *pb = env->GetFloatArrayElements(b, nullptr);
    auto *pr = env->GetFloatArrayElements(r, nullptr);

    float *tpa = pa;
    float *tpb = pb;
    float *tpr = pr;
    for (auto i = 0; i < SIZE; i++) {
        *tpr = (*tpa) - (*tpb);
        tpa++; tpb++; tpr++;
    }

    env->ReleaseFloatArrayElements(a, pa, 2);
    env->ReleaseFloatArrayElements(b, pb, 2);
    env->ReleaseFloatArrayElements(r, pr, 0);
}

JNIEXPORT void JNICALL Java_ch_zxseitz_j3de_math_Matrix4_multiplyC
        (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *pa = env->GetFloatArrayElements(a, nullptr);
    auto *pb = env->GetFloatArrayElements(b, nullptr);
    auto *pr = env->GetFloatArrayElements(r, nullptr);

    float *tpa;
    float *tpb;
    float *tpr = pr;
    float sum;
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 4; j++) {
            tpa = pa + i * 4;
            tpb = pb + j;
            sum = 0;
            for (auto k = 0; k < 4; k++) {
                sum += (*tpa) * (*tpb);
                tpa += 1;
                tpb += 4;
            }
            *tpr = sum;
            tpr++;
        }
    }

    env->ReleaseFloatArrayElements(a, pa, 2);
    env->ReleaseFloatArrayElements(b, pb, 2);
    env->ReleaseFloatArrayElements(r, pr, 0);
}

JNIEXPORT void JNICALL Java_ch_zxseitz_j3de_math_Matrix4_multiplyElementsC
        (JNIEnv *env, jclass c, jfloatArray a, jfloatArray b, jfloatArray r) {
    auto *pa = env->GetFloatArrayElements(a, nullptr);
    auto *pb = env->GetFloatArrayElements(b, nullptr);
    auto *pr = env->GetFloatArrayElements(r, nullptr);

    float *tpa = pa;
    float *tpb = pb;
    float *tpr = pr;
    for (auto i = 0; i < SIZE; i++) {
        *tpr = (*tpa) * (*tpb);
        tpa++; tpb++; tpr++;
    }

    env->ReleaseFloatArrayElements(a, pa, 2);
    env->ReleaseFloatArrayElements(b, pb, 2);
    env->ReleaseFloatArrayElements(r, pr, 0);
}

JNIEXPORT void JNICALL Java_ch_zxseitz_j3de_math_Matrix4_multiplyScalarC
        (JNIEnv *env, jclass c, jfloatArray a, jfloat s, jfloatArray r) {
    auto *pa = env->GetFloatArrayElements(a, nullptr);
    auto *pr = env->GetFloatArrayElements(r, nullptr);

    float *tpa = pa;
    float *tpr = pr;
    for (auto i = 0; i < SIZE; i++) {
        *tpr = (*tpa) * s;
        pa++; pr++;
    }

    env->ReleaseFloatArrayElements(a, pa, 2);
    env->ReleaseFloatArrayElements(r, pr, 0);
}