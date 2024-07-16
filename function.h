#pragma once
#include <assert.h>
#include <Novice.h>
#define _USE_MATH_DEFINES
#include "math.h"
#include <cmath>
#include <limits>
#include <numbers>
#include "Vector3.h"

Vector3 operator+(const Vector3& mValue1, const Vector3& mValue2) {
	Vector3 result = {};
	result.x = mValue1.x + mValue2.x;
	result.y = mValue1.y + mValue2.y;
	result.z = mValue1.z + mValue2.z;

	return result;
}

Vector3 operator-(const Vector3& mValue1, const Vector3& mValue2) {
	Vector3 result = {};
	result.x = mValue1.x - mValue2.x;
	result.y = mValue1.y - mValue2.y;
	result.z = mValue1.z - mValue2.z;

	return result;
}

struct Matrix4x4 {
	float m[4][4];
};

//行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 r;
	r = {
		r.m[0][0] = m1.m[0][0] + m2.m[0][0],r.m[0][1] = m1.m[0][1] + m2.m[0][1],r.m[0][2] = m1.m[0][2] + m2.m[0][2],r.m[0][3] = m1.m[0][3] + m2.m[0][3],
		r.m[1][0] = m1.m[1][0] + m2.m[1][0],r.m[1][1] = m1.m[1][1] + m2.m[1][1],r.m[1][2] = m1.m[1][2] + m2.m[1][2],r.m[1][3] = m1.m[1][3] + m2.m[1][3],
		r.m[2][0] = m1.m[2][0] + m2.m[2][0],r.m[2][1] = m1.m[2][1] + m2.m[2][1],r.m[2][2] = m1.m[2][2] + m2.m[2][2],r.m[2][3] = m1.m[2][3] + m2.m[2][3],
		r.m[3][0] = m1.m[3][0] + m2.m[3][0],r.m[3][1] = m1.m[3][1] + m2.m[3][1],r.m[3][2] = m1.m[3][2] + m2.m[3][2],r.m[3][3] = m1.m[3][3] + m2.m[3][3],
	};
	return r;
};
//行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 r;
	r = {
		r.m[0][0] = m1.m[0][0] - m2.m[0][0],r.m[0][1] = m1.m[0][1] - m2.m[0][1],r.m[0][2] = m1.m[0][2] - m2.m[0][2],r.m[0][3] = m1.m[0][3] - m2.m[0][3],
		r.m[1][0] = m1.m[1][0] - m2.m[1][0],r.m[1][1] = m1.m[1][1] - m2.m[1][1],r.m[1][2] = m1.m[1][2] - m2.m[1][2],r.m[1][3] = m1.m[1][3] - m2.m[1][3],
		r.m[2][0] = m1.m[2][0] - m2.m[2][0],r.m[2][1] = m1.m[2][1] - m2.m[2][1],r.m[2][2] = m1.m[2][2] - m2.m[2][2],r.m[2][3] = m1.m[2][3] - m2.m[2][3],
		r.m[3][0] = m1.m[3][0] - m2.m[3][0],r.m[3][1] = m1.m[3][1] - m2.m[3][1],r.m[3][2] = m1.m[3][2] - m2.m[3][2],r.m[3][3] = m1.m[3][3] - m2.m[3][3],
	};
	return r;
};
//行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 r;
	r = {
		r.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0],r.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1],r.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2],r.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3],
		r.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0],r.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1],r.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2],r.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3],
		r.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0],r.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1],r.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2],r.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3],
		r.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0],r.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1],r.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2],r.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3],
	};
	return r;
};
//逆行列
Matrix4x4 Inverse(const Matrix4x4& m) {
	float inverse = m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]
		- m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1] - m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2]
		- m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1] - m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2]
		+ m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] + m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2]
		+ m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2]
		- m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]
		- m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0] - m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0] - m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0]
		+ m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0] + m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] + m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0];

	Matrix4x4 r;
	r = {
		r.m[0][0] = (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][3] * m.m[2][2] * m.m[3][1] - m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][1] * m.m[2][3] * m.m[3][2]) / inverse,
		r.m[0][1] = (-m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] - m.m[0][3] * m.m[2][1] * m.m[3][2] + m.m[0][3] * m.m[2][2] * m.m[3][1] + m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[2][3] * m.m[3][2]) / inverse,
		r.m[0][2] = (m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][3] * m.m[1][2] * m.m[3][1] - m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[3][2]) / inverse,
		r.m[0][3] = (-m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] - m.m[0][3] * m.m[1][1] * m.m[2][2] + m.m[0][3] * m.m[1][2] * m.m[2][1] + m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][1] * m.m[1][3] * m.m[2][2]) / inverse,
		r.m[1][0] = (-m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] - m.m[1][3] * m.m[2][0] * m.m[3][2] + m.m[1][3] * m.m[2][2] * m.m[3][0] + m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][0] * m.m[2][3] * m.m[3][2]) / inverse,
		r.m[1][1] = (m.m[0][0] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][0] + m.m[0][3] * m.m[2][0] * m.m[3][2] - m.m[0][3] * m.m[2][2] * m.m[3][0] - m.m[0][2] * m.m[2][0] * m.m[3][3] - m.m[0][0] * m.m[2][3] * m.m[3][2]) / inverse,
		r.m[1][2] = (-m.m[0][0] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][0] - m.m[0][3] * m.m[1][0] * m.m[3][2] + m.m[0][3] * m.m[1][2] * m.m[3][0] + m.m[0][2] * m.m[1][0] * m.m[3][3] + m.m[0][0] * m.m[1][3] * m.m[3][2]) / inverse,
		r.m[1][3] = (m.m[0][0] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] + m.m[0][3] * m.m[1][0] * m.m[2][2] - m.m[0][3] * m.m[1][2] * m.m[2][0] - m.m[0][2] * m.m[1][0] * m.m[2][3] - m.m[0][0] * m.m[1][3] * m.m[2][2]) / inverse,
		r.m[2][0] = (m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] + m.m[1][3] * m.m[2][0] * m.m[3][1] - m.m[1][3] * m.m[2][1] * m.m[3][0] - m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][0] * m.m[2][3] * m.m[3][1]) / inverse,
		r.m[2][1] = (-m.m[0][0] * m.m[2][1] * m.m[3][3] - m.m[0][1] * m.m[2][3] * m.m[3][0] - m.m[0][3] * m.m[2][0] * m.m[3][1] + m.m[0][3] * m.m[2][1] * m.m[3][0] + m.m[0][1] * m.m[2][0] * m.m[3][3] + m.m[0][0] * m.m[2][3] * m.m[3][1]) / inverse,
		r.m[2][2] = (m.m[0][0] * m.m[1][1] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[3][0] + m.m[0][3] * m.m[1][0] * m.m[3][1] - m.m[0][3] * m.m[1][1] * m.m[3][0] - m.m[0][1] * m.m[1][0] * m.m[3][3] - m.m[0][0] * m.m[1][3] * m.m[3][1]) / inverse,
		r.m[2][3] = (-m.m[0][0] * m.m[1][1] * m.m[2][3] - m.m[0][1] * m.m[1][3] * m.m[2][0] - m.m[0][3] * m.m[1][0] * m.m[2][1] + m.m[0][3] * m.m[1][1] * m.m[2][0] + m.m[0][1] * m.m[1][0] * m.m[2][3] + m.m[0][0] * m.m[1][3] * m.m[2][1]) / inverse,
		r.m[3][0] = (-m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][2] * m.m[3][0] - m.m[1][2] * m.m[2][0] * m.m[3][1] + m.m[1][2] * m.m[2][1] * m.m[3][0] + m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[1][0] * m.m[2][2] * m.m[3][1]) / inverse,
		r.m[3][1] = (m.m[0][0] * m.m[2][1] * m.m[3][2] + m.m[0][1] * m.m[2][2] * m.m[3][0] + m.m[0][2] * m.m[2][0] * m.m[3][1] - m.m[0][2] * m.m[2][1] * m.m[3][0] - m.m[0][1] * m.m[2][0] * m.m[3][2] - m.m[0][0] * m.m[2][2] * m.m[3][1]) / inverse,
		r.m[3][2] = (-m.m[0][0] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][2] * m.m[3][0] - m.m[0][2] * m.m[1][0] * m.m[3][1] + m.m[0][2] * m.m[1][1] * m.m[3][0] + m.m[0][1] * m.m[1][0] * m.m[3][2] + m.m[0][0] * m.m[1][2] * m.m[3][1]) / inverse,
		r.m[3][3] = (m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] + m.m[0][2] * m.m[1][0] * m.m[2][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] - m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][2] * m.m[2][1]) / inverse,
	};
	return r;
};
//転置行列
Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 r;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			r.m[i][j] = m.m[j][i];
		}
	}
	return r;
};
//単位行列の作成
Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 r;
	r = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	return r;
};

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 v3;
	v3 = { v1.x + v2.x,v1.y + v2.y ,v1.z + v2.z };
	return v3;
};
//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 v3;
	v3 = { v1.x - v2.x,v1.y - v2.y ,v1.z - v2.z };
	return v3;
};
//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 v3;
	v3 = { scalar * v.x,scalar * v.y,scalar * v.z };
	return v3;
};
//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float r;
	r = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return r;
};
//長さ（ノルム）
float Length(const Vector3& v) {
	float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return length;
};
//正規化
Vector3 Normalize(const Vector3& v) {
	float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	Vector3 r;
	r = { v.x / length,v.y / length ,v.z / length };
	return r;
};

//x軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 R = {
		R.m[0][0] = 1,
		R.m[0][1] = 0,
		R.m[0][2] = 0,
		R.m[0][3] = 0,
		R.m[1][0] = 0,
		R.m[1][1] = std::cos(radian),
		R.m[1][2] = std::sin(radian),
		R.m[1][3] = 0,
		R.m[2][0] = 0,
		R.m[2][1] = -std::sin(radian),
		R.m[2][2] = std::cos(radian),
		R.m[2][3] = 0,
		R.m[3][0] = 0,
		R.m[3][1] = 0,
		R.m[3][2] = 0,
		R.m[3][3] = 1,
	};
	return R;
};

//y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 R = {
		R.m[0][0] = std::cos(radian),
		R.m[0][1] = 0,
		R.m[0][2] = -std::sin(radian),
		R.m[0][3] = 0,
		R.m[1][0] = 0,
		R.m[1][1] = 1,
		R.m[1][2] = 0,
		R.m[1][3] = 0,
		R.m[2][0] = std::sin(radian),
		R.m[2][1] = 0,
		R.m[2][2] = std::cos(radian),
		R.m[2][3] = 0,
		R.m[3][0] = 0,
		R.m[3][1] = 0,
		R.m[3][2] = 0,
		R.m[3][3] = 1,
	};
	return R;
};

//z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 R = {
		R.m[0][0] = std::cos(radian),
		R.m[0][1] = std::sin(radian),
		R.m[0][2] = 0,
		R.m[0][3] = 0,
		R.m[1][0] = -std::sin(radian),
		R.m[1][1] = std::cos(radian),
		R.m[1][2] = 0,
		R.m[1][3] = 0,
		R.m[2][0] = 0,
		R.m[2][1] = 0,
		R.m[2][2] = 1,
		R.m[2][3] = 0,
		R.m[3][0] = 0,
		R.m[3][1] = 0,
		R.m[3][2] = 0,
		R.m[3][3] = 1,
	};
	return R;
};

//xyz回転行列
Matrix4x4 MakeRotateXYZMatrix(const Vector3& rotate) {

	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);

	Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));

	return rotateXYZMatrix;
};

//平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 T = {
		T.m[0][0] = 1,
		T.m[0][1] = 0,
		T.m[0][2] = 0,
		T.m[0][3] = 0,
		T.m[1][0] = 0,
		T.m[1][1] = 1,
		T.m[1][2] = 0,
		T.m[1][3] = 0,
		T.m[2][0] = 0,
		T.m[2][1] = 0,
		T.m[2][2] = 1,
		T.m[2][3] = 0,
		T.m[3][0] = translate.x,
		T.m[3][1] = translate.y,
		T.m[3][2] = translate.z,
		T.m[3][3] = 1,
	};
	return T;
};

//拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 S = {
		S.m[0][0] = scale.x,
		S.m[0][1] = 0,
		S.m[0][2] = 0,
		S.m[0][3] = 0,
		S.m[1][0] = 0,
		S.m[1][1] = scale.y,
		S.m[1][2] = 0,
		S.m[1][3] = 0,
		S.m[2][0] = 0,
		S.m[2][1] = 0,
		S.m[2][2] = scale.z,
		S.m[2][3] = 0,
		S.m[3][0] = 0,
		S.m[3][1] = 0,
		S.m[3][2] = 0,
		S.m[3][3] = 1,
	};
	return S;
};

//座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + 1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + 1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + 1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + 1.0f * matrix.m[3][3];

	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
};

//アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 S = MakeScaleMatrix(scale);
	Matrix4x4 R = MakeRotateXYZMatrix(rotate);
	Matrix4x4 T = MakeTranslateMatrix(translate);

	Matrix4x4 SR = Multiply(S, R);
	Matrix4x4 result = Multiply(SR, T);
	return result;
};

//数値表示
static const int kColumnWidth = 60;
static const int kRowHeight = 20;

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

//4x4数値表示
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + 20 + row * kRowHeight, "%6.02f", matrix.m[row][column]);

		}
	}
}

//透視投影行列	
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 perspectiveFovMatrix = {
		perspectiveFovMatrix.m[0][0] = (1.0f / aspectRatio) * 1.0f / tanf(fovY / 2.0f),
		perspectiveFovMatrix.m[0][1] = 0.0f,
		perspectiveFovMatrix.m[0][2] = 0.0f,
		perspectiveFovMatrix.m[0][3] = 0.0f,
		perspectiveFovMatrix.m[1][0] = 0.0f,
		perspectiveFovMatrix.m[1][1] = 1.0f / tanf(fovY / 2.0f),
		perspectiveFovMatrix.m[1][2] = 0.0f,
		perspectiveFovMatrix.m[1][3] = 0.0f,
		perspectiveFovMatrix.m[2][0] = 0.0f,
		perspectiveFovMatrix.m[2][1] = 0.0f,
		perspectiveFovMatrix.m[2][2] = farClip / (farClip - nearClip),
		perspectiveFovMatrix.m[2][3] = 1.0f,
		perspectiveFovMatrix.m[3][0] = 0.0f,
		perspectiveFovMatrix.m[3][1] = 0.0f,
		perspectiveFovMatrix.m[3][2] = (-nearClip * farClip) / (farClip - nearClip),
		perspectiveFovMatrix.m[3][3] = 0.0f,
	};
	return perspectiveFovMatrix;
};

//正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {
	Matrix4x4 orthographicMatrix = {
		orthographicMatrix.m[0][0] = 2.0f / (right - left),
		orthographicMatrix.m[0][1] = 0.0f,
		orthographicMatrix.m[0][2] = 0.0f,
		orthographicMatrix.m[0][3] = 0.0f,
		orthographicMatrix.m[1][0] = 0.0f,
		orthographicMatrix.m[1][1] = 2.0f / (top - bottom),
		orthographicMatrix.m[1][2] = 0.0f,
		orthographicMatrix.m[1][3] = 0.0f,
		orthographicMatrix.m[2][0] = 0.0f,
		orthographicMatrix.m[2][1] = 0.0f,
		orthographicMatrix.m[2][2] = 1.0f / (farClip - nearClip),
		orthographicMatrix.m[2][3] = 0.0f,
		orthographicMatrix.m[3][0] = (left + right) / (left - right),
		orthographicMatrix.m[3][1] = (top + bottom) / (bottom - top),
		orthographicMatrix.m[3][2] = nearClip / (nearClip - farClip),
		orthographicMatrix.m[3][3] = 1.0f,
	};
	return orthographicMatrix;
};

//ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 viewportMatrix = {
		viewportMatrix.m[0][0] = width / 2.0f,
		viewportMatrix.m[0][1] = 0.0f,
		viewportMatrix.m[0][2] = 0.0f,
		viewportMatrix.m[0][3] = 0.0f,
		viewportMatrix.m[1][0] = 0.0f,
		viewportMatrix.m[1][1] = -height / 2.0f,
		viewportMatrix.m[1][2] = 0.0f,
		viewportMatrix.m[1][3] = 0.0f,
		viewportMatrix.m[2][0] = 0.0f,
		viewportMatrix.m[2][1] = 0.0f,
		viewportMatrix.m[2][2] = maxDepth - minDepth,
		viewportMatrix.m[2][3] = 0.0f,
		viewportMatrix.m[3][0] = left + (width / 2.0f),
		viewportMatrix.m[3][1] = top + (height / 2.0f),
		viewportMatrix.m[3][2] = minDepth,
		viewportMatrix.m[3][3] = 1.0f,
	};
	return viewportMatrix;
};

//クロス積	
Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 cross{
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x,
	};
	return cross;
};

//グリッド表示
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfWidth = 2.0f;//Gridの半分の幅
	const uint32_t kSubdivision = 10;//分割数
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);//1つ分の長さ

	//奥から手前への線を順々に引いていく
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		float x = -kGridHalfWidth + (xIndex * kGridEvery);
		Vector3 startLine{ x, 0.0f, -kGridHalfWidth };
		Vector3 endLine{ x, 0.0f, kGridHalfWidth };

		Vector3 startScreen = Transform(Transform(startLine, viewProjectionMatrix), viewportMatrix);
		Vector3 endScreen = Transform(Transform(endLine, viewProjectionMatrix), viewportMatrix);

		Novice::DrawLine(int(startScreen.x), int(startScreen.y), int(endScreen.x), int(endScreen.y), x == 0.0f ? BLACK : 0xAAAAAAFF);

	}
	//左から右
	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		float z = -kGridHalfWidth + (zIndex * kGridEvery);
		Vector3 startLine{ -kGridHalfWidth, 0.0f, z };
		Vector3 endLine{ kGridHalfWidth, 0.0f, z };

		Vector3 startScreen = Transform(Transform(startLine, viewProjectionMatrix), viewportMatrix);
		Vector3 endScreen = Transform(Transform(endLine, viewProjectionMatrix), viewportMatrix);

		Novice::DrawLine(int(startScreen.x), int(startScreen.y), int(endScreen.x), int(endScreen.y), z == 0.0f ? BLACK : 0xAAAAAAFF);
	}
}

//球表示
struct Sphere {
	Vector3 center;//中心点
	float radius;//半径
};

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	float pi = std::numbers::pi_v<float>;
	const uint32_t kSubdivision = 12;//分割数
	const float kLonEvery = pi * 2.0f / float(kSubdivision);//経度分割1つ分の角度
	const float kLatEvery = pi / float(kSubdivision);//緯度分割1つ分の角度
	//緯度の方向に分割
	for (uint32_t latIndex = 0; latIndex < kSubdivision; ++latIndex) {
		float lat = -pi / 2.0f + kLatEvery * latIndex;//現在の緯度
		//緯度の方向に分割
		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; ++lonIndex) {
			float lon = lonIndex * kLonEvery;//現在の緯度
			//ワールド座標系でのabcを求める
			Vector3 a = {
				sphere.center.x + sphere.radius * std::cos(lat) * std::cos(lon),
				sphere.center.y + sphere.radius * std::sin(lat),
				sphere.center.z + sphere.radius * std::cos(lat) * std::sin(lon)
			};
			Vector3 b = {
				sphere.center.x + sphere.radius * std::cos(lat + kLatEvery) * std::cos(lon),
				sphere.center.y + sphere.radius * std::sin(lat + kLatEvery),
				sphere.center.z + sphere.radius * std::cos(lat + kLatEvery) * std::sin(lon)
			};
			Vector3 c = {
				sphere.center.x + sphere.radius * std::cos(lat) * std::cos(lon + kLonEvery),
				sphere.center.y + sphere.radius * std::sin(lat),
				sphere.center.z + sphere.radius * std::cos(lat) * std::sin(lon + kLonEvery)
			};

			//abcをスクリーン座標系まで変換
			Vector3 screenA = Transform(Transform(a, viewProjectionMatrix), viewportMatrix);
			Vector3 screenB = Transform(Transform(b, viewProjectionMatrix), viewportMatrix);
			Vector3 screenC = Transform(Transform(c, viewProjectionMatrix), viewportMatrix);

			//ab,bcで線を引く
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenB.x), int(screenB.y), color);
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenC.x), int(screenC.y), color);

		}
	}

}

struct AABB {
	Vector3 min; // 最小点
	Vector3 max; // 最大点
};

// AABBとAABBの当たり判定
bool ISCollisinAABBAABB(const AABB& aabb1, const AABB& aabb2) {
	if ((aabb1.min.x <= aabb2.max.x && aabb1.max.x >= aabb2.min.x) && // x軸
		(aabb1.min.y <= aabb2.max.y && aabb1.max.y >= aabb2.min.y) && // y軸
		(aabb1.min.z <= aabb2.max.z && aabb1.max.z >= aabb2.min.z)) { // z軸
		return true;
	}
	return false;
}

//球と球の当たり判定
bool IsCollisionSphereSphere(const Sphere& s1, const Sphere& s2) {
	//2つの球の中心点座標の距離を求める
	float distance = Length(s2.center - s1.center);
	//衝突判定
	if (distance <= s1.radius + s2.radius) {
		return true;
	}
	return false;
}