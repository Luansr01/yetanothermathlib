#include <iostream>
#include <math.h>
#include <iomanip>

void compareFloat(float expect, float result){
	int truncExpect = (int)(result * 1000);
	int truncResult = (int)(expect * 1000);

	std::cout << "Expected Result\t\t" << "Type: " << "(" << typeid(expect).name() << ") | " << "Original Value: " << expect << " | Truncated Value: " << truncExpect << "\n";
	std::cout << "Result\t\t\t" << "Type: " << "(" << typeid(result).name() << ") | " << "Original Value: " << result << " | Truncated Value: " << truncResult << "\n";
	bool success = (truncExpect == truncResult);
	if(success == 1){
		std::cout << "[" << success << "] " << "SUCCESS" << "\n";
	}else{
		std::cout << "[" << success << "]" << "FAILURE" << "\n";
	}
}

void compareVec2(Vec2* expect, Vec2* result){
	int truncExpectX = (int)(expect->x * 1000);
	int truncExpectY = (int)(expect->y * 1000);
	int truncResultX = (int)(result->x * 1000);
	int truncResultY = (int)(result->y * 1000);

	std::cout << "Expected Result\t\t" << "Type: " << "(" << typeid(expect).name() << ") | " << "Original Value: " << "[" << expect->x << ", " << expect->y << "]" << " | Truncated Value: " << "[" << truncExpectX << ", " << truncExpectY << "]" << "\n";
	std::cout << "Result\t\t\t" << "Type: " << "(" << typeid(result).name() << ") | " << "Original Value: " << "[" << result->x << ", " << result->y << "]" << " | Truncated Value: " << "[" << truncResultX << ", " << truncResultY << "]" << "\n";
	

	bool success = (truncExpectX == truncResultX) && (truncExpectY == truncResultY);
	if(success == 1){
		std::cout << "[" << success << "] " << "SUCCESS" << "\n";
	}else{
		std::cout << "[" << success << "]" << "FAILURE" << "\n";
	}
}

void compareVec3(Vec3* expect, Vec3* result){
	int truncExpectX = (int)(expect->x * 1000);
	int truncExpectY = (int)(expect->y * 1000);
	int truncExpectZ = (int)(expect->z * 1000);
	int truncResultX = (int)(result->x * 1000);
	int truncResultY = (int)(result->y * 1000);
	int truncResultZ = (int)(result->z * 1000);

	std::cout << "Expected Result\t\t" << "Type: " << "(" << typeid(expect).name() << ") | " << "Original Value: " << "[" << expect->x << ", " << expect->y << expect->z << "]" << " | Truncated Value: " << "[" << truncExpectX << ", " << truncExpectY << ", " << truncExpectZ << "]" << "\n";
	std::cout << "Result\t\t\t" << "Type: " << "(" << typeid(result).name() << ") | " << "Original Value: " << "[" << result->x << ", " << result->y << result->z << "]" << " | Truncated Value: " << "[" << truncResultX << ", " << truncResultY<< ", " << truncResultZ << "]" << "\n";
	

	bool success = (truncExpectX == truncResultX) && (truncExpectY == truncResultY) && (truncExpectZ == truncResultZ);
	if(success == 1){
		std::cout << "[" << success << "] " << "SUCCESS" << "\n";
	}else{
		std::cout << "[" << success << "]" << "FAILURE" << "\n";
	}
}

void compareMat2(Mat2* expect, Mat2* result){
	std::cout <<
				"Expected Result:\n" << 
				"[" << expect->x.x << ", " << expect->x.y << "]" << "\n" <<
				"[" << expect->y.x << ", " << expect->y.y << "]" << "\n\n";

	std::cout << 
				"Result:\n" <<
				"[" << result->x.x << ", " << result->x.y << "]" << "\n" <<
				"[" << result->y.x << ", " << result->y.y << "]" << "\n\n";
}

int main(){
	std::cout << std::setprecision(8) << std::fixed;
	
	Angle x(1);
	Angle y(1, DEGREES);

	Vec2 test_vec2_result = Vec2(1.0, 2.0) + Vec2(2.0, 2.0);
	Vec2 test_vec2_expect(3.0, 4.0);

	Vec3 test_vec3_result = Vec3(1.0, 2.0, 3.0) + Vec3(2.0, 5.0, 1.5);
	Vec3 test_vec3_expect = Vec3(3.0, 7.0, 4.5);

	Mat2 test_mat2_expect = Mat2(2, -9, 2.5, -11);

	Mat2 test_mat2_result(3,-2,4,-3);
	test_mat2_result /= Mat2(6,-10,1,-2);

	compareMat2(&test_mat2_expect, &test_mat2_result);

	compareVec2(&test_vec2_expect, &test_vec2_result);
	compareVec3(&test_vec3_expect, &test_vec3_result);

	compareFloat(x.Degrees(), 57.2958);
	compareFloat(y.Radians(), 0.0174533);
}
