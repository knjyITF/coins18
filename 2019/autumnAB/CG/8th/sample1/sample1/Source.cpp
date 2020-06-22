#define FREEGLUT_STATIC

#include <GL/glut.h>
#include <math.h>   
#include <stdlib.h> 
#include <stdio.h> 
#include <algorithm>

class Vector3d {
public:
	double x, y, z;
	Vector3d() { x = y = z = 0; }
	Vector3d(double _x, double _y, double _z) { x = _x; y = _y; z = _z; }
	void set(double _x, double _y, double _z) { x = _x; y = _y; z = _z; }

	// ������1�ɐ��K������
	void normalize() {
		double len = length();
		x /= len; y /= len; z /= len;
	}

	// ������Ԃ�
	double length() { return sqrt(x * x + y * y + z * z); }

	// s�{����
	void scale(const double s) { x *= s; y *= s; z *= s; }

	// ���Z�̒�`
	Vector3d operator+(Vector3d v) { return Vector3d(x + v.x, y + v.y, z + v.z); }

	// ���Z�̒�`
	Vector3d operator-(Vector3d v) { return Vector3d(x - v.x, y - v.y, z - v.z); }

	// ���ς̒�`
	double operator*(Vector3d v) { return x * v.x + y * v.y + z * v.z; }

	// �O�ς̒�`
	Vector3d operator%(Vector3d v) { return Vector3d(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

	// ������Z�̒�`
	Vector3d& operator=(const Vector3d& v) { x = v.x; y = v.y; z = v.z; return (*this); }

	// ���Z����̒�`
	Vector3d& operator+=(const Vector3d& v) { x += v.x; y += v.y; z += v.z; return (*this); }

	// ���Z����̒�`
	Vector3d& operator-=(const Vector3d& v) { x -= v.x; y -= v.y; z -= v.z; return (*this); }

	// �l���o�͂���
	void print() { printf("Vector3d(%f %f %f)\n", x, y, z); }
};
// �}�C�i�X�̕����̕t�����x�N�g����������悤�ɂ��邽�߂̒�` ��Fb=(-a); �̂悤�ɋL�q�ł���
Vector3d operator-(const Vector3d& v) { return(Vector3d(-v.x, -v.y, -v.z)); }

// �x�N�g���Ǝ����̐ς�������悤�ɂ��邽�߂̒�` ��F c=5*a+2*b; c=b*3; �̂悤�ɋL�q�ł���
Vector3d operator*(const double& k, const Vector3d& v) { return(Vector3d(k * v.x, k * v.y, k * v.z)); }
Vector3d operator*(const Vector3d& v, const double& k) { return(Vector3d(v.x * k, v.y * k, v.z * k)); }

// �x�N�g���������Ŋ��鑀���������悤�ɂ��邽�߂̒�` ��F c=a/2.3; �̂悤�ɋL�q�ł���
Vector3d operator/(const Vector3d& v, const double& k) { return(Vector3d(v.x / k, v.y / k, v.z / k)); }


// ����
class Sphere {
public:
	Vector3d center; // ���S���W
	double radius;   // ���a
	double cR, cG, cB;  // Red, Green, Blue �l 0.0�`1.0

	Sphere(double x, double y, double z, double r,
		double cr, double cg, double cb) {
		center.x = x;
		center.y = y;
		center.z = z;
		radius = r;
		cR = cr;
		cG = cg;
		cB = cb;
	}

	// �_p��ʂ�Av������Ray�Ƃ̌����𔻒肷��B
	// ��_�� p+tv �Ƃ��ĕ\����ꍇ�� t �̒l��Ԃ��B�����Ȃ��ꍇ��-1��Ԃ�
	double getIntersec(Vector3d& p, Vector3d& v) {
		// A*t^2 + B*t + C = 0 �̌`�ŕ\��
		double A = v.x * v.x + v.y * v.y + v.z * v.z;
		double B = 2.0 * (p.x * v.x - v.x * center.x +
			p.y * v.y - v.y * center.y +
			p.z * v.z - v.z * center.z);
		double C = p.x * p.x - 2 * p.x * center.x + center.x * center.x +
			p.y * p.y - 2 * p.y * center.y + center.y * center.y +
			p.z * p.z - 2 * p.z * center.z + center.z * center.z -
			radius * radius;
		double D = B * B - 4 * A * C; // ���ʎ�

		if (D >= 0) { // �����
			double t1 = (-B - sqrt(D)) / (2.0 * A);
			double t2 = (-B + sqrt(D)) / (2.0 * A);
			return t1 < t2 ? t1 : t2; // �������ق���t�̒l��Ԃ�
		}
		else { // �����Ȃ�
			return -1.0;
		}
	}
};

// �Bxz���ʂɕ��s�ȖʂƂ���
class Board {
public:
	double y; // y���W�l

	Board(double _y) {
		y = _y;
	}

	// �_p��ʂ�Av������Ray�Ƃ̌����𔻒肷��B
	// ��_�� p+tv �Ƃ��ĕ\����ꍇ�� t �̒l��Ԃ��B�����Ȃ��ꍇ�͕��̒l��Ԃ�
	double getIntersec(Vector3d& p, Vector3d& v) {
		if (fabs(v.y) < 1.0e-10) return -1; // ������Ray�͌����Ȃ�

		double t = -1;
		// �������� t �̒l���v�Z����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		// ��������z���W��-3000��菬�����Ȃ�����Ȃ����̂Ƃ���!!!!!!!!!!!!!
		t = -(150 + p.y) / v.y;
		if (v.z * t < -3000) {
			t = -1;
		}

		return t;
	}

	// x �� z �̒l���珰�̐F��Ԃ��i�i�q�͗l�ɂȂ�悤�Ɂj
	Vector3d getColorVec(double x, double z) {
		// �� x, z �̒l�ɂ����(1.0, 1.0, 0.7)�܂���(0.6, 0.6, 0.6)�̂ǂ��炩�̐F��Ԃ��悤�ɂ���
		int cx = -1, cz = -1;
		if (x >= 0) {
			cx = ((int)x / 100) % 2;
		}
		else {
			cx = (((int)(-x) + 100) / 100) % 2;
		}
		if (z >= 0) {
			cz = ((int)z / 100) % 2;
		}
		else {
			cz = (((int)(-z) + 100) / 100) % 2;
		}
		if ((cx == 1 && cz == 1) || (cx == 0 && cz == 0)) {
			return Vector3d(1.0, 1.0, 0.7);
		}
		else {
			return Vector3d(0.6, 0.6, 0.6);
		}
	}
};

int halfWidth;    // �`��̈�̉���/2
int halfHeight;   // �`��̈�̏c��/2
double screen_z = -1000;  // ���e�ʂ�z���W
double Kd = 0.8;  // �g�U���˒萔
double Ks = 0.8;  // ���ʔ��˒萔
double Iin = 0.5; // ���ˌ��̋��� 
double Ia = 0.5; // ����
Vector3d viewPosition(0, 0, 0); // ���_=���_
Vector3d lightDirection(-2, -4, -2); // ���ˌ��̐i�s����


// �����_�����O���鋅��
Sphere sphere(0.0, 0.0, -1500, // ���S���W
	150.0,           // ���a
	0.1, 0.7, 0.7);  // RGB�l

// ���̂̒u����Ă��鏰
Board board(-150); // y���W�l�� -150 �ɂ���B�i���Ɛڂ���悤�ɂ���j

// 2�̃x�N�g���̐����p��cos�l���v�Z����
double getCos(Vector3d& v0, Vector3d& v1) {
	return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z) / (v0.length() * v1.length());
}

// x, y �Ŏw�肳�ꂽ�X�N���[�����W�ł̐F(RGB)�� colorVec ��xyz�̒l�Ɋi�[����
void getPixelColor(double x, double y, Vector3d& colorVec) {
	// ���_����X�N���[����̃s�N�Z���֔�΂����C�̕���
	Vector3d ray(x - viewPosition.x, y - viewPosition.y, screen_z - viewPosition.z);

	ray.normalize(); // ���C�̒����̐��K��

	// ���C���΂��ċ��ƌ������邩���߂�
	double t_sphere = sphere.getIntersec(viewPosition, ray);

	if (t_sphere > 0) { // ���Ƃ̌�_������
		// ���O��̉ۑ���Q�l�ɁA���̂̕\�ʂ̐F���v�Z�ŋ��߁AcolorVec�ɐݒ肷��!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		double Is = 0; // ���ʔ��ˌ�
		double Id = 0; // �g�U���ˌ�
		Vector3d viewPositionToRayPoint = t_sphere * ray; // ���_���烌�C�Ƌ��Ƃ̌�_�ւ̃x�N�g��
		Vector3d sphereCenter(viewPosition.x, viewPosition.y, viewPosition.z - 1500); // ���_���狅���S�ւ̃x�N�g��
		Vector3d N = viewPositionToRayPoint - sphereCenter;
		N.normalize(); // �@���x�N�g��
		lightDirection.normalize();
		if (((-lightDirection) * N) >= 0) {
			Id = Iin * Kd * ((-lightDirection) * N);
		}


		Vector3d V = t_sphere * ((Vector3d(0, 0, -1500)) - viewPosition);
		V.normalize();
		double a = (-lightDirection) * N;
		Vector3d R = lightDirection + (2 * a * N);
		R.normalize();

		double cosy = 0;
		int npow = 10;
		cosy = pow(R * V, npow);

		if ((-lightDirection) * N >= 0) {
			Is = Iin * Ks * cosy;
		}

		double I = Id + Is + Ia;

		double r = std::min(I * sphere.cR, 1.0); // 1.0 �𒴂��Ȃ��悤�ɂ���
		double g = std::min(I * sphere.cG, 1.0); // 1.0 �𒴂��Ȃ��悤�ɂ���
		double b = std::min(I * sphere.cB, 1.0); // 1.0 �𒴂��Ȃ��悤�ɂ���

		colorVec.set(r, g, b);
		return;
	}

	// ���C���΂��ď��ƌ������邩���߂�
	double t_board = board.getIntersec(viewPosition, ray);

	if (t_board > 0) { // ���Ƃ̌�_������
		// �����̕\�ʂ̐F��ݒ肷��
		// �����̉e�ɂȂ�ꍇ�́ARGB�̒l�����ꂼ��0.5�{����
		double tx = t_board * ray.x;
		double ty = t_board * ray.y;
		double tz = t_board * ray.z;

		Vector3d point_board(tx, ty, tz);

		double r = board.getColorVec(tx, tz).x;
		double g = board.getColorVec(tx, tz).y;
		double b = board.getColorVec(tx, tz).z;

		lightDirection.normalize();
		Vector3d light = -lightDirection;

		double u = sphere.getIntersec(point_board, light);
		if (u > 0) {
			r = r * 0.5;
			g = g * 0.5;
			b = b * 0.5;
		}

		colorVec.set(r, g, b);
		return;
	}

	// ���Ƃ��������Ȃ�
	colorVec.set(0, 0, 0); // �w�i�F�i���j��ݒ肷��
}

// �`����s��
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT); // �`����e�̃N���A

	// �s�N�Z���P�ʂŕ`��F�����肷�郋�[�v����
	for (int y = (-halfHeight); y <= halfHeight; y++) {
		for (int x = (-halfWidth); x <= halfWidth; x++) {
			
			Vector3d colorVec0;
			Vector3d colorVec1;
			Vector3d colorVec2;
			Vector3d colorVec3;
			Vector3d colorVec4;
			Vector3d colorVec5;
			Vector3d colorVec6;
			Vector3d colorVec7;
			Vector3d colorVec8;


			// x, y ���W�̐F���擾����
			getPixelColor((double)x			, (double)y			, colorVec0);
			getPixelColor((double)x			, (double)y + 0.334	, colorVec1);
			getPixelColor((double)x			, (double)y + 0.667	, colorVec2);
			getPixelColor((double)x	+ 0.334	, (double)y			, colorVec3);
			getPixelColor((double)x + 0.334	, (double)y + 0.334	, colorVec4);
			getPixelColor((double)x + 0.334	, (double)y + 0.667	, colorVec5);
			getPixelColor((double)x	+ 0.667	, (double)y			, colorVec6);
			getPixelColor((double)x + 0.667	, (double)y + 0.334	, colorVec7);
			getPixelColor((double)x + 0.667	, (double)y + 0.667	, colorVec8);


			//�擾�����F�ŁA�`��F��ݒ肷��
			double colorX = (colorVec0.x + colorVec1.x + colorVec2.x + colorVec3.x + colorVec4.x + colorVec5.x + colorVec6.x + colorVec7.x + colorVec8.x)/9;
			double colorY = (colorVec0.y + colorVec1.y + colorVec2.y + colorVec3.y + colorVec4.y + colorVec5.y + colorVec6.y + colorVec7.y + colorVec8.y)/9;
			double colorZ = (colorVec0.z + colorVec1.z + colorVec2.z + colorVec3.z + colorVec4.z + colorVec5.z + colorVec6.z + colorVec7.z + colorVec8.z)/9;

			glColor3d(colorX, colorY, colorZ);
			

			/*
			Vector3d colorVec;

			// x, y ���W�̐F���擾����
			getPixelColor(x, y, colorVec);

			//�擾�����F�ŁA�`��F��ݒ肷��
			glColor3d(colorVec.x, colorVec.y, colorVec.z);
			*/

			// (x, y) �̉�f��`��
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}
	}
	glFlush();
}

void resizeWindow(int w, int h) {
	h = (h == 0) ? 1 : h;
	glViewport(0, 0, w, h);
	halfWidth = w / 2;
	halfHeight = h / 2;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// �E�B���h�E���̍��W�n�ݒ�
	glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0);  /* ESC code */
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	lightDirection.normalize();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(180, 10);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);

	glutDisplayFunc(display);
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}